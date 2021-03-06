// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CTCHEAT_PACKET_MISC_H_
#define FLATBUFFERS_GENERATED_CTCHEAT_PACKET_MISC_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Misc {

struct CTCheat;

enum CheatResult {
  CheatResult_Ok = 0,
  CheatResult_InvalidCheat = 1,
  CheatResult_AccessDenied = 2,
  CheatResult_FailRemoveQuest = 3,
  CheatResult_FailBeginQuest = 4,
  CheatResult_FailEndQuest = 5,
  CheatResult_MIN = CheatResult_Ok,
  CheatResult_MAX = CheatResult_FailEndQuest
};

inline const CheatResult (&EnumValuesCheatResult())[6] {
  static const CheatResult values[] = {
    CheatResult_Ok,
    CheatResult_InvalidCheat,
    CheatResult_AccessDenied,
    CheatResult_FailRemoveQuest,
    CheatResult_FailBeginQuest,
    CheatResult_FailEndQuest
  };
  return values;
}

inline const char * const *EnumNamesCheatResult() {
  static const char * const names[] = {
    "Ok",
    "InvalidCheat",
    "AccessDenied",
    "FailRemoveQuest",
    "FailBeginQuest",
    "FailEndQuest",
    nullptr
  };
  return names;
}

inline const char *EnumNameCheatResult(CheatResult e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesCheatResult()[index];
}

struct CTCheat FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_RESULT = 6,
    VT_MESSAGE = 8
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  CheatResult result() const {
    return static_cast<CheatResult>(GetField<uint8_t>(VT_RESULT, 0));
  }
  const flatbuffers::String *message() const {
    return GetPointer<const flatbuffers::String *>(VT_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<uint8_t>(verifier, VT_RESULT) &&
           VerifyOffset(verifier, VT_MESSAGE) &&
           verifier.VerifyString(message()) &&
           verifier.EndTable();
  }
};

struct CTCheatBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(CTCheat::VT_CHARSID, charsid, 0);
  }
  void add_result(CheatResult result) {
    fbb_.AddElement<uint8_t>(CTCheat::VT_RESULT, static_cast<uint8_t>(result), 0);
  }
  void add_message(flatbuffers::Offset<flatbuffers::String> message) {
    fbb_.AddOffset(CTCheat::VT_MESSAGE, message);
  }
  explicit CTCheatBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CTCheatBuilder &operator=(const CTCheatBuilder &);
  flatbuffers::Offset<CTCheat> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CTCheat>(end);
    return o;
  }
};

inline flatbuffers::Offset<CTCheat> CreateCTCheat(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    CheatResult result = CheatResult_Ok,
    flatbuffers::Offset<flatbuffers::String> message = 0) {
  CTCheatBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_charsid(charsid);
  builder_.add_result(result);
  return builder_.Finish();
}

inline flatbuffers::Offset<CTCheat> CreateCTCheatDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    CheatResult result = CheatResult_Ok,
    const char *message = nullptr) {
  return Packet::Misc::CreateCTCheat(
      _fbb,
      charsid,
      result,
      message ? _fbb.CreateString(message) : 0);
}

inline const Packet::Misc::CTCheat *GetCTCheat(const void *buf) {
  return flatbuffers::GetRoot<Packet::Misc::CTCheat>(buf);
}

inline const Packet::Misc::CTCheat *GetSizePrefixedCTCheat(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Misc::CTCheat>(buf);
}

inline bool VerifyCTCheatBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Misc::CTCheat>(nullptr);
}

inline bool VerifySizePrefixedCTCheatBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Misc::CTCheat>(nullptr);
}

inline void FinishCTCheatBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Misc::CTCheat> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCTCheatBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Misc::CTCheat> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Misc
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_CTCHEAT_PACKET_MISC_H_
