#pragma once

#include "ctmsg/msg_LOGIN.h"

namespace ctlobby
{
	struct NMCOMM_API FnmLobbyCharEquip
	{
		FnmLobbyCharEquip() : id(0), tier(0) {}
		FnmLobbyCharEquip(int32 InID, int32 InTier) : id(InID), tier(InTier) {}
		int32 id;
		int32 tier;
	};

	class NMCOMM_API FnmCharacterData
	{
		friend class FnmCharacterList;

	public:
		FnmCharacterData();
		void Clear();
		bool IsEmpty() const;
		int32 GetSID() const;
		int32 GetGender() const;
		void SetGender(int32 InGender);
		bool IsMale() const;
		bool IsFemale() const;
		int32 GetCheckpoint() const;
		FString GetName() const;
		void SetName(const FString& InName);
		void SetWeapon(int32 Slot, int32 ID, int32 Tier);
		const FnmLobbyCharEquip* GetWeapon(int32 Slot) const;
		void SetArmor(int32 Slot, int32 ID, int32 Tier);
		const FnmLobbyCharEquip* GetArmor(int32 Slot) const;
		void SetCostume(int32 Slot, int32 ID);
		int32 GetCostume(int32 Slot) const;

		const TArray<FnmLobbyCharEquip>& GetWeaponList() const { return WeaponSlot; }
		const TArray<FnmLobbyCharEquip>& GetArmorList() const { return ArmorSlot; }
		const TArray<int32>& GetCostumeList() const { return CostumeSlot; }

	private:
		int32 SID;
		int32 Gender;
		int32 Checkpoint;
		FString Name;
		TArray<FnmLobbyCharEquip> WeaponSlot;
		TArray<FnmLobbyCharEquip> ArmorSlot;
		TArray<int32> CostumeSlot;
	};

	class NMCOMM_API FnmCharacterList
	{
	public:
		FnmCharacterList();
		void SetCharacterList(const Packet::Login::LGCharList* InCharList);
		void AddCharacter(const Packet::Login::DACharInfo* InChar);
		void RemoveCharacter(int32 SID);
		const FnmCharacterData* FindCharacter(int32 SID) const;
		FnmCharacterData* FindCharacter(int32 SID);
		int32 FindCharacterIndex(int32 SID) const;
		const FnmCharacterData* GetCharacterAt(int32 InIndex) const;
		FnmCharacterData* GetCharacterAt(int32 InIndex);
		void GetCharacterList(TArray<FnmCharacterData*>& OutCharList);
		int32 GetCharacterCount() const;

		// BEGIN: Activated Character
		const FnmCharacterData* GetActivatedCharacter() const;
		void SetActivatedCharacter(int32 SID);
		// END: Activated Character

		// BEGIN: Character Slot
		bool HasEmptySlot() const;
		int32 GetEmptySlotCount() const;
		void SetSlotCount(int32 InNewCount);
		void AddSlotCount(int32 InCount);
		// END: Character Slot

	private:
		void ClearData();

	private:
		TArray<FnmCharacterData> CharacterListArray;
		int32 CurrentCharacterSlotCount;
		int32 ActivatedCharacterSID;
	};

	class NMCOMM_API FnmCharacterHelper
	{
	public:
		int32 GenderMale() const;
		int32 GenderFemale() const;
	};

	extern NMCOMM_API FnmCharacterList& charlist();
	extern NMCOMM_API FnmCharacterHelper& charhelper();
}
