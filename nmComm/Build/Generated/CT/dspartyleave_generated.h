// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSPARTYLEAVE_PACKET_PARTY_H_
#define FLATBUFFERS_GENERATED_DSPARTYLEAVE_PACKET_PARTY_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Party {

struct DSPartyLeave;

struct DSPartyLeave FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_PARTYID = 6
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int32_t partyid() const {
    return GetField<int32_t>(VT_PARTYID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int32_t>(verifier, VT_PARTYID) &&
           verifier.EndTable();
  }
};

struct DSPartyLeaveBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(DSPartyLeave::VT_CHARSID, charsid, 0);
  }
  void add_partyid(int32_t partyid) {
    fbb_.AddElement<int32_t>(DSPartyLeave::VT_PARTYID, partyid, 0);
  }
  explicit DSPartyLeaveBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSPartyLeaveBuilder &operator=(const DSPartyLeaveBuilder &);
  flatbuffers::Offset<DSPartyLeave> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSPartyLeave>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSPartyLeave> CreateDSPartyLeave(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int32_t partyid = 0) {
  DSPartyLeaveBuilder builder_(_fbb);
  builder_.add_partyid(partyid);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Party::DSPartyLeave *GetDSPartyLeave(const void *buf) {
  return flatbuffers::GetRoot<Packet::Party::DSPartyLeave>(buf);
}

inline const Packet::Party::DSPartyLeave *GetSizePrefixedDSPartyLeave(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Party::DSPartyLeave>(buf);
}

inline bool VerifyDSPartyLeaveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Party::DSPartyLeave>(nullptr);
}

inline bool VerifySizePrefixedDSPartyLeaveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Party::DSPartyLeave>(nullptr);
}

inline void FinishDSPartyLeaveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::DSPartyLeave> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSPartyLeaveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::DSPartyLeave> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Party
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSPARTYLEAVE_PACKET_PARTY_H_