// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSPVPCANCELMATCH_PACKET_MATCH_PVP_H_
#define FLATBUFFERS_GENERATED_DSPVPCANCELMATCH_PACKET_MATCH_PVP_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Match {
namespace PvP {

struct DSPvPCancelMatch;

struct DSPvPCancelMatch FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           verifier.EndTable();
  }
};

struct DSPvPCancelMatchBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(DSPvPCancelMatch::VT_CHARSID, charsid, 0);
  }
  explicit DSPvPCancelMatchBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSPvPCancelMatchBuilder &operator=(const DSPvPCancelMatchBuilder &);
  flatbuffers::Offset<DSPvPCancelMatch> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSPvPCancelMatch>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSPvPCancelMatch> CreateDSPvPCancelMatch(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0) {
  DSPvPCancelMatchBuilder builder_(_fbb);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Match::PvP::DSPvPCancelMatch *GetDSPvPCancelMatch(const void *buf) {
  return flatbuffers::GetRoot<Packet::Match::PvP::DSPvPCancelMatch>(buf);
}

inline const Packet::Match::PvP::DSPvPCancelMatch *GetSizePrefixedDSPvPCancelMatch(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Match::PvP::DSPvPCancelMatch>(buf);
}

inline bool VerifyDSPvPCancelMatchBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Match::PvP::DSPvPCancelMatch>(nullptr);
}

inline bool VerifySizePrefixedDSPvPCancelMatchBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Match::PvP::DSPvPCancelMatch>(nullptr);
}

inline void FinishDSPvPCancelMatchBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Match::PvP::DSPvPCancelMatch> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSPvPCancelMatchBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Match::PvP::DSPvPCancelMatch> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace PvP
}  // namespace Match
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSPVPCANCELMATCH_PACKET_MATCH_PVP_H_