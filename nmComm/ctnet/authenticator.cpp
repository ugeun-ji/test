#include "authenticator.h"
namespace ctnet
{
	Authenticator::Authenticator()
	{
		Clear();
	}

	void Authenticator::Clear()
	{
		UserID = TEXT("");
		Token = TEXT("");
	}

	FString Authenticator::GetUserID() const
	{
		return UserID;
	}

	FString Authenticator::GetToken() const
	{
		return Token;
	}

	void Authenticator::SetUserID(const FString& InUserID)
	{
		UserID = InUserID;
	}

	void Authenticator::SetToken(const FString& InToken)
	{
		Token = InToken;
	}

	Authenticator& authenticator()
	{
		static Authenticator sAuth;
		return sAuth;
	}
}
