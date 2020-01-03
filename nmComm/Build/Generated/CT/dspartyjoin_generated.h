// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSPARTYJOIN_PACKET_PARTY_H_
#define FLATBUFFERS_GENERATED_DSPARTYJOIN_PACKET_PARTY_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Party {

struct DSPartyJoin;

struct DSPartyJoin FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_INVITATIONSID = 6
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int32_t invitationsid() const {
    return GetField<int32_t>(VT_INVITATIONSID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int32_t>(verifier, VT_INVITATIONSID) &&
           verifier.EndTable();
  }
};

struct DSPartyJoinBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(DSPartyJoin::VT_CHARSID, charsid, 0);
  }
  void add_invitationsid(int32_t invitationsid) {
    fbb_.AddElement<int32_t>(DSPartyJoin::VT_INVITATIONSID, invitationsid, 0);
  }
  explicit DSPartyJoinBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSPartyJoinBuilder &operator=(const DSPartyJoinBuilder &);
  flatbuffers::Offset<DSPartyJoin> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSPartyJoin>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSPartyJoin> CreateDSPartyJoin(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int32_t invitationsid = 0) {
  DSPartyJoinBuilder builder_(_fbb);
  builder_.add_invitationsid(invitationsid);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Party::DSPartyJoin *GetDSPartyJoin(const void *buf) {
  return flatbuffers::GetRoot<Packet::Party::DSPartyJoin>(buf);
}

inline const Packet::Party::DSPartyJoin *GetSizePrefixedDSPartyJoin(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Party::DSPartyJoin>(buf);
}

inline bool VerifyDSPartyJoinBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Party::DSPartyJoin>(nullptr);
}

inline bool VerifySizePrefixedDSPartyJoinBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Party::DSPartyJoin>(nullptr);
}

inline void FinishDSPartyJoinBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::DSPartyJoin> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSPartyJoinBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::DSPartyJoin> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Party
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSPARTYJOIN_PACKET_PARTY_H_