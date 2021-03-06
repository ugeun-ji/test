// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CTPARTYDENY_PACKET_PARTY_H_
#define FLATBUFFERS_GENERATED_CTPARTYDENY_PACKET_PARTY_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Party {

struct CTPartyDeny;

struct CTPartyDeny FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHID = 4,
    VT_CHARSID = 6,
    VT_INVITEE = 8
  };
  int32_t chid() const {
    return GetField<int32_t>(VT_CHID, 0);
  }
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  const flatbuffers::String *invitee() const {
    return GetPointer<const flatbuffers::String *>(VT_INVITEE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHID) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyOffset(verifier, VT_INVITEE) &&
           verifier.VerifyString(invitee()) &&
           verifier.EndTable();
  }
};

struct CTPartyDenyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_chid(int32_t chid) {
    fbb_.AddElement<int32_t>(CTPartyDeny::VT_CHID, chid, 0);
  }
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(CTPartyDeny::VT_CHARSID, charsid, 0);
  }
  void add_invitee(flatbuffers::Offset<flatbuffers::String> invitee) {
    fbb_.AddOffset(CTPartyDeny::VT_INVITEE, invitee);
  }
  explicit CTPartyDenyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CTPartyDenyBuilder &operator=(const CTPartyDenyBuilder &);
  flatbuffers::Offset<CTPartyDeny> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CTPartyDeny>(end);
    return o;
  }
};

inline flatbuffers::Offset<CTPartyDeny> CreateCTPartyDeny(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t chid = 0,
    int32_t charsid = 0,
    flatbuffers::Offset<flatbuffers::String> invitee = 0) {
  CTPartyDenyBuilder builder_(_fbb);
  builder_.add_invitee(invitee);
  builder_.add_charsid(charsid);
  builder_.add_chid(chid);
  return builder_.Finish();
}

inline flatbuffers::Offset<CTPartyDeny> CreateCTPartyDenyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t chid = 0,
    int32_t charsid = 0,
    const char *invitee = nullptr) {
  return Packet::Party::CreateCTPartyDeny(
      _fbb,
      chid,
      charsid,
      invitee ? _fbb.CreateString(invitee) : 0);
}

inline const Packet::Party::CTPartyDeny *GetCTPartyDeny(const void *buf) {
  return flatbuffers::GetRoot<Packet::Party::CTPartyDeny>(buf);
}

inline const Packet::Party::CTPartyDeny *GetSizePrefixedCTPartyDeny(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Party::CTPartyDeny>(buf);
}

inline bool VerifyCTPartyDenyBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Party::CTPartyDeny>(nullptr);
}

inline bool VerifySizePrefixedCTPartyDenyBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Party::CTPartyDeny>(nullptr);
}

inline void FinishCTPartyDenyBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::CTPartyDeny> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCTPartyDenyBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::CTPartyDeny> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Party
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_CTPARTYDENY_PACKET_PARTY_H_
