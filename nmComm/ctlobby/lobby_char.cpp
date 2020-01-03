#include "lobby_char.h"
#include "Datacache/nmDatacacheUtils.h"

#define MAX_CHAR_WEAPON 3
#define MAX_CHAR_ARMOR 4
#define MAX_CHAR_COSTUME 1
#define MIN_CHAR_SLOT 5
#define MAX_CHAR_SLOT 20

namespace ctlobby
{
	FnmCharacterData::FnmCharacterData()
	{
		Clear();
	}

	void FnmCharacterData::Clear()
	{
		SID = 0;
		Gender = 0;
		Checkpoint = 0;
		Name = TEXT("");
		WeaponSlot.Empty();
		WeaponSlot.AddDefaulted(MAX_CHAR_WEAPON);
		ArmorSlot.Empty();
		ArmorSlot.AddDefaulted(MAX_CHAR_ARMOR);
		CostumeSlot.Empty();
		CostumeSlot.AddDefaulted(MAX_CHAR_COSTUME);
	}

	bool FnmCharacterData::IsEmpty() const
	{
		return (SID <= 0);
	}

	int32 FnmCharacterData::GetSID() const
	{
		return SID;
	}
	int32 FnmCharacterData::GetGender() const
	{
		return Gender;
	}

	void FnmCharacterData::SetGender(int32 InGender)
	{
		Gender = InGender;
	}

	bool FnmCharacterData::IsMale() const
	{
		return Gender == charhelper().GenderMale();
	}

	bool FnmCharacterData::IsFemale() const
	{
		return Gender == charhelper().GenderFemale();
	}

	int32 FnmCharacterData::GetCheckpoint() const
	{
		return Checkpoint;
	}

	FString FnmCharacterData::GetName() const
	{
		return Name;
	}

	void FnmCharacterData::SetName(const FString& InName)
	{
		Name = InName;
	}

	void FnmCharacterData::SetWeapon(int32 Slot, int32 ID, int32 Tier)
	{
		if (WeaponSlot.IsValidIndex(Slot))
		{
			WeaponSlot[Slot] = FnmLobbyCharEquip(ID, Tier);
		}
	}

	const FnmLobbyCharEquip* FnmCharacterData::GetWeapon(int32 Slot) const
	{
		return WeaponSlot.IsValidIndex(Slot) ? &WeaponSlot[Slot] : nullptr;
	}

	void FnmCharacterData::SetArmor(int32 Slot, int32 ID, int32 Tier)
	{
		if (ArmorSlot.IsValidIndex(Slot))
		{
			ArmorSlot[Slot] = FnmLobbyCharEquip(ID, Tier);
		}
	}

	const FnmLobbyCharEquip* FnmCharacterData::GetArmor(int32 Slot) const
	{
		return ArmorSlot.IsValidIndex(Slot) ? &ArmorSlot[Slot] : nullptr;
	}

	void FnmCharacterData::SetCostume(int32 Slot, int32 ID)
	{
		if (CostumeSlot.IsValidIndex(Slot))
		{
			CostumeSlot[Slot] = ID;
		}
	}

	int32 FnmCharacterData::GetCostume(int32 Slot) const
	{
		return CostumeSlot.IsValidIndex(Slot) ? CostumeSlot[Slot] : 0;
	}

	FnmCharacterList::FnmCharacterList()
		: CurrentCharacterSlotCount(0)
		, ActivatedCharacterSID(0)
	{
	}

	void FnmCharacterList::ClearData()
	{
		CurrentCharacterSlotCount = MIN_CHAR_SLOT;
		CharacterListArray.Empty();
	}

	void FnmCharacterList::SetCharacterList(const Packet::Login::LGCharList* InCharList)
	{
		ClearData();

		for (const auto& It : *InCharList->info())
		{
			AddCharacter(It);
		}
	}

	void FnmCharacterList::AddCharacter(const Packet::Login::DACharInfo* InChar)
	{
		if (InChar == nullptr || InChar->sid() <= 0)
		{
			return;
		}

		FnmCharacterData* CharData = new (CharacterListArray) FnmCharacterData;
		CharData->SID = InChar->sid();
		CharData->Gender = InChar->gender();
		CharData->Checkpoint = InChar->checkpoint();
		CharData->Name = UTF8_TO_TCHAR(InChar->charName()->c_str());
		CharData->SetWeapon(0, InChar->weapon1(), InChar->w1tier());
		CharData->SetWeapon(1, InChar->weapon2(), InChar->w2tier());
		CharData->SetWeapon(2, InChar->weapon3(), InChar->w3tier());
		CharData->SetArmor(0, InChar->armor1(), InChar->a1tier());
		CharData->SetArmor(1, InChar->armor2(), InChar->a2tier());
		CharData->SetArmor(2, InChar->armor3(), InChar->a3tier());
		CharData->SetArmor(3, InChar->armor4(), InChar->a4tier());
		CharData->SetCostume(0, InChar->hair());
	}

	void FnmCharacterList::RemoveCharacter(int32 SID)
	{
		if (ActivatedCharacterSID == SID)
		{
			ActivatedCharacterSID = 0;
		}

		int32 CharIndex = FindCharacterIndex(SID);
		if (CharacterListArray.IsValidIndex(CharIndex))
		{
			CharacterListArray.RemoveAt(CharIndex);
		}
	}

	const FnmCharacterData* FnmCharacterList::FindCharacter(int32 SID) const
	{
		if (SID > 0)
		{
			for (const auto& It : CharacterListArray)
			{
				if (It.SID == SID)
				{
					return &It;
				}
			}
		}
		return nullptr;
	}

	FnmCharacterData* FnmCharacterList::FindCharacter(int32 SID)
	{
		if (SID > 0)
		{
			for (auto& It : CharacterListArray)
			{
				if (It.SID == SID)
				{
					return &It;
				}
			}
		}
		return nullptr;
	}

	int32 FnmCharacterList::FindCharacterIndex(int32 SID) const
	{
		if (SID > 0)
		{
			for (int32 i = 0; i < CharacterListArray.Num(); i++)
			{
				if (CharacterListArray[i].GetSID() == SID)
				{
					return i;
				}
			}
		}
		return INDEX_NONE;
	}

	const FnmCharacterData* FnmCharacterList::GetCharacterAt(int32 InIndex) const
	{
		return CharacterListArray.IsValidIndex(InIndex)
			? &CharacterListArray[InIndex]
			: nullptr;
	}

	FnmCharacterData* FnmCharacterList::GetCharacterAt(int32 InIndex)
	{
		return CharacterListArray.IsValidIndex(InIndex)
			? &CharacterListArray[InIndex]
			: nullptr;
	}

	void FnmCharacterList::GetCharacterList(TArray<FnmCharacterData*>& OutCharList)
	{
		for (auto& It : CharacterListArray)
		{
			OutCharList.Add(&It);
		}
	}

	int32 FnmCharacterList::GetCharacterCount() const
	{
		return CharacterListArray.Num();
	}

	const FnmCharacterData* FnmCharacterList::GetActivatedCharacter() const
	{
		return FindCharacter(ActivatedCharacterSID);
	}

	void FnmCharacterList::SetActivatedCharacter(int32 SID)
	{
		if (FindCharacter(SID) != nullptr)
		{
			ActivatedCharacterSID = SID;
		}
	}

	bool FnmCharacterList::HasEmptySlot() const
	{
		return GetEmptySlotCount() > 0;
	}

	int32 FnmCharacterList::GetEmptySlotCount() const
	{
		return FMath::Max(CurrentCharacterSlotCount - GetCharacterCount(), 0);
	}

	void FnmCharacterList::SetSlotCount(int32 InNewCount)
	{
		CurrentCharacterSlotCount = FMath::Clamp(InNewCount, MIN_CHAR_SLOT, MAX_CHAR_SLOT);
	}

	void FnmCharacterList::AddSlotCount(int32 InCount)
	{
		CurrentCharacterSlotCount = FMath::Clamp(CurrentCharacterSlotCount + InCount, MIN_CHAR_SLOT, MAX_CHAR_SLOT);
	}

	int32 FnmCharacterHelper::GenderMale() const
	{
		return 0;
	}

	int32 FnmCharacterHelper::GenderFemale() const
	{
		return 1;
	}

	FnmCharacterList& charlist()
	{
		static FnmCharacterList sCharList;
		return sCharList;
	}

	FnmCharacterHelper& charhelper()
	{
		static FnmCharacterHelper sCharHelper;
		return sCharHelper;
	}
}
