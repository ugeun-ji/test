// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSCHEAT_PACKET_MISC_H_
#define FLATBUFFERS_GENERATED_DSCHEAT_PACKET_MISC_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Misc {

struct DSCheat;

enum CheatCmd {
  CheatCmd_CreateWeaponItem = 0,
  CheatCmd_CreateArmorItem = 1,
  CheatCmd_CreateMaterialItem = 2,
  CheatCmd_UpdateAmmo = 3,
  CheatCmd_UpdateGold = 4,
  CheatCmd_RemoveQuest = 5,
  CheatCmd_BeginQuest = 6,
  CheatCmd_EndQuest = 7,
  CheatCmd_MIN = CheatCmd_CreateWeaponItem,
  CheatCmd_MAX = CheatCmd_EndQuest
};

inline const CheatCmd (&EnumValuesCheatCmd())[8] {
  static const CheatCmd values[] = {
    CheatCmd_CreateWeaponItem,
    CheatCmd_CreateArmorItem,
    CheatCmd_CreateMaterialItem,
    CheatCmd_UpdateAmmo,
    CheatCmd_UpdateGold,
    CheatCmd_RemoveQuest,
    CheatCmd_BeginQuest,
    CheatCmd_EndQuest
  };
  return values;
}

inline const char * const *EnumNamesCheatCmd() {
  static const char * const names[] = {
    "CreateWeaponItem",
    "CreateArmorItem",
    "CreateMaterialItem",
    "UpdateAmmo",
    "UpdateGold",
    "RemoveQuest",
    "BeginQuest",
    "EndQuest",
    nullptr
  };
  return names;
}

inline const char *EnumNameCheatCmd(CheatCmd e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesCheatCmd()[index];
}

struct DSCheat FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_COMMAND = 6,
    VT_ARGS = 8
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  CheatCmd command() const {
    return static_cast<CheatCmd>(GetField<uint16_t>(VT_COMMAND, 0));
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *args() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_ARGS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<uint16_t>(verifier, VT_COMMAND) &&
           VerifyOffset(verifier, VT_ARGS) &&
           verifier.VerifyVector(args()) &&
           verifier.VerifyVectorOfStrings(args()) &&
           verifier.EndTable();
  }
};

struct DSCheatBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(DSCheat::VT_CHARSID, charsid, 0);
  }
  void add_command(CheatCmd command) {
    fbb_.AddElement<uint16_t>(DSCheat::VT_COMMAND, static_cast<uint16_t>(command), 0);
  }
  void add_args(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> args) {
    fbb_.AddOffset(DSCheat::VT_ARGS, args);
  }
  explicit DSCheatBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSCheatBuilder &operator=(const DSCheatBuilder &);
  flatbuffers::Offset<DSCheat> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSCheat>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSCheat> CreateDSCheat(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    CheatCmd command = CheatCmd_CreateWeaponItem,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> args = 0) {
  DSCheatBuilder builder_(_fbb);
  builder_.add_args(args);
  builder_.add_charsid(charsid);
  builder_.add_command(command);
  return builder_.Finish();
}

inline flatbuffers::Offset<DSCheat> CreateDSCheatDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    CheatCmd command = CheatCmd_CreateWeaponItem,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *args = nullptr) {
  return Packet::Misc::CreateDSCheat(
      _fbb,
      charsid,
      command,
      args ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*args) : 0);
}

inline const Packet::Misc::DSCheat *GetDSCheat(const void *buf) {
  return flatbuffers::GetRoot<Packet::Misc::DSCheat>(buf);
}

inline const Packet::Misc::DSCheat *GetSizePrefixedDSCheat(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Misc::DSCheat>(buf);
}

inline bool VerifyDSCheatBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Misc::DSCheat>(nullptr);
}

inline bool VerifySizePrefixedDSCheatBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Misc::DSCheat>(nullptr);
}

inline void FinishDSCheatBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Misc::DSCheat> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSCheatBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Misc::DSCheat> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Misc
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSCHEAT_PACKET_MISC_H_
