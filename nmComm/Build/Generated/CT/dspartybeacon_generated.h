// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSPARTYBEACON_PACKET_PARTY_H_
#define FLATBUFFERS_GENERATED_DSPARTYBEACON_PACKET_PARTY_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Party {

struct DSPartyBeacon;

struct DSPartyBeacon FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_QUESTID = 6
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int32_t questid() const {
    return GetField<int32_t>(VT_QUESTID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int32_t>(verifier, VT_QUESTID) &&
           verifier.EndTable();
  }
};

struct DSPartyBeaconBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(DSPartyBeacon::VT_CHARSID, charsid, 0);
  }
  void add_questid(int32_t questid) {
    fbb_.AddElement<int32_t>(DSPartyBeacon::VT_QUESTID, questid, 0);
  }
  explicit DSPartyBeaconBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSPartyBeaconBuilder &operator=(const DSPartyBeaconBuilder &);
  flatbuffers::Offset<DSPartyBeacon> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSPartyBeacon>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSPartyBeacon> CreateDSPartyBeacon(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int32_t questid = 0) {
  DSPartyBeaconBuilder builder_(_fbb);
  builder_.add_questid(questid);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Party::DSPartyBeacon *GetDSPartyBeacon(const void *buf) {
  return flatbuffers::GetRoot<Packet::Party::DSPartyBeacon>(buf);
}

inline const Packet::Party::DSPartyBeacon *GetSizePrefixedDSPartyBeacon(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Party::DSPartyBeacon>(buf);
}

inline bool VerifyDSPartyBeaconBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Party::DSPartyBeacon>(nullptr);
}

inline bool VerifySizePrefixedDSPartyBeaconBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Party::DSPartyBeacon>(nullptr);
}

inline void FinishDSPartyBeaconBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::DSPartyBeacon> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSPartyBeaconBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Party::DSPartyBeacon> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Party
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSPARTYBEACON_PACKET_PARTY_H_
