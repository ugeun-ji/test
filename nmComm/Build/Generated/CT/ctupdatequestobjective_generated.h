// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CTUPDATEQUESTOBJECTIVE_PACKET_CHARACTER_H_
#define FLATBUFFERS_GENERATED_CTUPDATEQUESTOBJECTIVE_PACKET_CHARACTER_H_

#include "flatbuffers/flatbuffers.h"

#include "daquest_generated.h"
#include "daquestobjective_generated.h"

namespace Packet {
namespace Character {

struct CTUpdateQuestObjective;

struct CTUpdateQuestObjective FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_QUEST = 6
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  const DAQuest *quest() const {
    return GetPointer<const DAQuest *>(VT_QUEST);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyOffset(verifier, VT_QUEST) &&
           verifier.VerifyTable(quest()) &&
           verifier.EndTable();
  }
};

struct CTUpdateQuestObjectiveBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(CTUpdateQuestObjective::VT_CHARSID, charsid, 0);
  }
  void add_quest(flatbuffers::Offset<DAQuest> quest) {
    fbb_.AddOffset(CTUpdateQuestObjective::VT_QUEST, quest);
  }
  explicit CTUpdateQuestObjectiveBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CTUpdateQuestObjectiveBuilder &operator=(const CTUpdateQuestObjectiveBuilder &);
  flatbuffers::Offset<CTUpdateQuestObjective> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CTUpdateQuestObjective>(end);
    return o;
  }
};

inline flatbuffers::Offset<CTUpdateQuestObjective> CreateCTUpdateQuestObjective(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    flatbuffers::Offset<DAQuest> quest = 0) {
  CTUpdateQuestObjectiveBuilder builder_(_fbb);
  builder_.add_quest(quest);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Character::CTUpdateQuestObjective *GetCTUpdateQuestObjective(const void *buf) {
  return flatbuffers::GetRoot<Packet::Character::CTUpdateQuestObjective>(buf);
}

inline const Packet::Character::CTUpdateQuestObjective *GetSizePrefixedCTUpdateQuestObjective(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Character::CTUpdateQuestObjective>(buf);
}

inline bool VerifyCTUpdateQuestObjectiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Character::CTUpdateQuestObjective>(nullptr);
}

inline bool VerifySizePrefixedCTUpdateQuestObjectiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Character::CTUpdateQuestObjective>(nullptr);
}

inline void FinishCTUpdateQuestObjectiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::CTUpdateQuestObjective> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCTUpdateQuestObjectiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::CTUpdateQuestObjective> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Character
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_CTUPDATEQUESTOBJECTIVE_PACKET_CHARACTER_H_