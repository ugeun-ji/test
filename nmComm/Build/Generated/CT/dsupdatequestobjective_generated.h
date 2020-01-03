// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSUPDATEQUESTOBJECTIVE_PACKET_CHARACTER_H_
#define FLATBUFFERS_GENERATED_DSUPDATEQUESTOBJECTIVE_PACKET_CHARACTER_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Character {

struct DSUpdateQuestObjective;

struct DSUpdateQuestObjective FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_QUESTSID = 6,
    VT_OBJECTIVEID = 8,
    VT_OBJECTIVEVALUE = 10
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int64_t questsid() const {
    return GetField<int64_t>(VT_QUESTSID, 0);
  }
  int32_t objectiveid() const {
    return GetField<int32_t>(VT_OBJECTIVEID, 0);
  }
  int32_t objectivevalue() const {
    return GetField<int32_t>(VT_OBJECTIVEVALUE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int64_t>(verifier, VT_QUESTSID) &&
           VerifyField<int32_t>(verifier, VT_OBJECTIVEID) &&
           VerifyField<int32_t>(verifier, VT_OBJECTIVEVALUE) &&
           verifier.EndTable();
  }
};

struct DSUpdateQuestObjectiveBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(DSUpdateQuestObjective::VT_CHARSID, charsid, 0);
  }
  void add_questsid(int64_t questsid) {
    fbb_.AddElement<int64_t>(DSUpdateQuestObjective::VT_QUESTSID, questsid, 0);
  }
  void add_objectiveid(int32_t objectiveid) {
    fbb_.AddElement<int32_t>(DSUpdateQuestObjective::VT_OBJECTIVEID, objectiveid, 0);
  }
  void add_objectivevalue(int32_t objectivevalue) {
    fbb_.AddElement<int32_t>(DSUpdateQuestObjective::VT_OBJECTIVEVALUE, objectivevalue, 0);
  }
  explicit DSUpdateQuestObjectiveBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSUpdateQuestObjectiveBuilder &operator=(const DSUpdateQuestObjectiveBuilder &);
  flatbuffers::Offset<DSUpdateQuestObjective> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSUpdateQuestObjective>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSUpdateQuestObjective> CreateDSUpdateQuestObjective(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int64_t questsid = 0,
    int32_t objectiveid = 0,
    int32_t objectivevalue = 0) {
  DSUpdateQuestObjectiveBuilder builder_(_fbb);
  builder_.add_questsid(questsid);
  builder_.add_objectivevalue(objectivevalue);
  builder_.add_objectiveid(objectiveid);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Character::DSUpdateQuestObjective *GetDSUpdateQuestObjective(const void *buf) {
  return flatbuffers::GetRoot<Packet::Character::DSUpdateQuestObjective>(buf);
}

inline const Packet::Character::DSUpdateQuestObjective *GetSizePrefixedDSUpdateQuestObjective(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Character::DSUpdateQuestObjective>(buf);
}

inline bool VerifyDSUpdateQuestObjectiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Character::DSUpdateQuestObjective>(nullptr);
}

inline bool VerifySizePrefixedDSUpdateQuestObjectiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Character::DSUpdateQuestObjective>(nullptr);
}

inline void FinishDSUpdateQuestObjectiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::DSUpdateQuestObjective> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSUpdateQuestObjectiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::DSUpdateQuestObjective> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Character
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSUPDATEQUESTOBJECTIVE_PACKET_CHARACTER_H_
