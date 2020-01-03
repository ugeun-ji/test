#pragma once

namespace ctnet
{
	class NMCOMM_API Authenticator
	{
	public:
		Authenticator();
		void Clear();
		FString GetUserID() const;
		FString GetToken() const;
		void SetUserID(const FString& InUserID);
		void SetToken(const FString& InToken);

	private:
		FString UserID;
		FString Token;
	};

	extern NMCOMM_API Authenticator& authenticator();
}
