// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CTUPDATEMISSIONUNLOCK_PACKET_CHARACTER_H_
#define FLATBUFFERS_GENERATED_CTUPDATEMISSIONUNLOCK_PACKET_CHARACTER_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Character {

struct CTUpdateMissionUnlock;

struct CTUpdateMissionUnlock FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_UNLOCKQUESTID = 6
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int32_t unlockquestid() const {
    return GetField<int32_t>(VT_UNLOCKQUESTID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int32_t>(verifier, VT_UNLOCKQUESTID) &&
           verifier.EndTable();
  }
};

struct CTUpdateMissionUnlockBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(CTUpdateMissionUnlock::VT_CHARSID, charsid, 0);
  }
  void add_unlockquestid(int32_t unlockquestid) {
    fbb_.AddElement<int32_t>(CTUpdateMissionUnlock::VT_UNLOCKQUESTID, unlockquestid, 0);
  }
  explicit CTUpdateMissionUnlockBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CTUpdateMissionUnlockBuilder &operator=(const CTUpdateMissionUnlockBuilder &);
  flatbuffers::Offset<CTUpdateMissionUnlock> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CTUpdateMissionUnlock>(end);
    return o;
  }
};

inline flatbuffers::Offset<CTUpdateMissionUnlock> CreateCTUpdateMissionUnlock(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int32_t unlockquestid = 0) {
  CTUpdateMissionUnlockBuilder builder_(_fbb);
  builder_.add_unlockquestid(unlockquestid);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Character::CTUpdateMissionUnlock *GetCTUpdateMissionUnlock(const void *buf) {
  return flatbuffers::GetRoot<Packet::Character::CTUpdateMissionUnlock>(buf);
}

inline const Packet::Character::CTUpdateMissionUnlock *GetSizePrefixedCTUpdateMissionUnlock(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Character::CTUpdateMissionUnlock>(buf);
}

inline bool VerifyCTUpdateMissionUnlockBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Character::CTUpdateMissionUnlock>(nullptr);
}

inline bool VerifySizePrefixedCTUpdateMissionUnlockBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Character::CTUpdateMissionUnlock>(nullptr);
}

inline void FinishCTUpdateMissionUnlockBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::CTUpdateMissionUnlock> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCTUpdateMissionUnlockBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::CTUpdateMissionUnlock> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Character
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_CTUPDATEMISSIONUNLOCK_PACKET_CHARACTER_H_
