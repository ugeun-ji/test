@echo off

set giturl=http://192.168.0.7:3000/schema/dsct
set remote=origin
set branch=dev

pushd "%~dp0"

if not exist DSCT\.git (
	git clone -b %branch% %giturl% DSCT
) else (
	cd DSCT
	git pull %remote% %branch%
	cd ..
)

CALL :CompileAndGenerate COMMON
CALL :CompileAndGenerate CT
CALL :CompileAndGenerate LOGIN

p4 edit Generated\messages.h
copy DSCT\CT\messages.h Generated\messages.h
p4 revert -a Generated\messages.h

popd

pause
exit /b

:CompileAndGenerate
setlocal enabledelayedexpansion
set Category=%~1

for %%F in (Generated\%Category%\*.h) do (
	for /f "tokens=1 delims=_" %%a in ("%%~nF") do (
		set msgtype=%%a
	)
	
	if not exist DSCT\%Category%\!msgtype!.fbs (
		p4 delete %%F
	) else (
		p4 edit %%F
	)	
)

for %%F in (DSCT\%Category%\*.fbs) do (
	if not exist Generated\%Category% (
		mkdir Generated\%Category%
	)

	flatc.exe -c -o Generated\%Category% %%F
)

for /f "tokens=1,2,3,4,5" %%F in ('p4 status Generated\%Category%\*.h') do (
	rem parse "{filename} - reconcile to add"
	rem echo %%H %%J %%F
	if "%%H" == "reconcile" (
		if "%%J" == "add" (
			p4 add %%F
		)
	)
)
p4 revert -a Generated\%Category%\*.h

set header=..\ctmsg\msg_%Category%.h
p4 edit %header%

echo Generating header %header% ...
echo // CTProxy generated header files include>%header%
echo // do not edit this directly but instead, run generate batch file>>%header%
echo // contact: jungjaehun@spacedivegames.com>>%header%
echo #pragma once>>%header%
echo #include "flatbuffers/flatbuffers.h">>%header%

for %%f in (Generated\%Category%\*_generated.h) do (
	set file=%%f
	set file=!file:\=/!
	rem echo "f=!file!"
	echo #include "Build/!file!">>%header%
)
endlocal

p4 revert -a %header%
exit /b
