// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DSPVPFINISHGAME_PACKET_MATCH_PVP_H_
#define FLATBUFFERS_GENERATED_DSPVPFINISHGAME_PACKET_MATCH_PVP_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Match {
namespace PvP {

struct PvPFinishMember;

struct DSPvPFinishGame;

struct PvPFinishMember FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_KILL = 6,
    VT_DEATH = 8
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int32_t kill() const {
    return GetField<int32_t>(VT_KILL, 0);
  }
  int32_t death() const {
    return GetField<int32_t>(VT_DEATH, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int32_t>(verifier, VT_KILL) &&
           VerifyField<int32_t>(verifier, VT_DEATH) &&
           verifier.EndTable();
  }
};

struct PvPFinishMemberBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(PvPFinishMember::VT_CHARSID, charsid, 0);
  }
  void add_kill(int32_t kill) {
    fbb_.AddElement<int32_t>(PvPFinishMember::VT_KILL, kill, 0);
  }
  void add_death(int32_t death) {
    fbb_.AddElement<int32_t>(PvPFinishMember::VT_DEATH, death, 0);
  }
  explicit PvPFinishMemberBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PvPFinishMemberBuilder &operator=(const PvPFinishMemberBuilder &);
  flatbuffers::Offset<PvPFinishMember> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PvPFinishMember>(end);
    return o;
  }
};

inline flatbuffers::Offset<PvPFinishMember> CreatePvPFinishMember(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int32_t kill = 0,
    int32_t death = 0) {
  PvPFinishMemberBuilder builder_(_fbb);
  builder_.add_death(death);
  builder_.add_kill(kill);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

struct DSPvPFinishGame FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MATCHID = 4,
    VT_WINTEAM = 6,
    VT_MEMBERS = 8
  };
  int32_t matchid() const {
    return GetField<int32_t>(VT_MATCHID, 0);
  }
  int32_t winteam() const {
    return GetField<int32_t>(VT_WINTEAM, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<PvPFinishMember>> *members() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<PvPFinishMember>> *>(VT_MEMBERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_MATCHID) &&
           VerifyField<int32_t>(verifier, VT_WINTEAM) &&
           VerifyOffset(verifier, VT_MEMBERS) &&
           verifier.VerifyVector(members()) &&
           verifier.VerifyVectorOfTables(members()) &&
           verifier.EndTable();
  }
};

struct DSPvPFinishGameBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_matchid(int32_t matchid) {
    fbb_.AddElement<int32_t>(DSPvPFinishGame::VT_MATCHID, matchid, 0);
  }
  void add_winteam(int32_t winteam) {
    fbb_.AddElement<int32_t>(DSPvPFinishGame::VT_WINTEAM, winteam, 0);
  }
  void add_members(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PvPFinishMember>>> members) {
    fbb_.AddOffset(DSPvPFinishGame::VT_MEMBERS, members);
  }
  explicit DSPvPFinishGameBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DSPvPFinishGameBuilder &operator=(const DSPvPFinishGameBuilder &);
  flatbuffers::Offset<DSPvPFinishGame> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DSPvPFinishGame>(end);
    return o;
  }
};

inline flatbuffers::Offset<DSPvPFinishGame> CreateDSPvPFinishGame(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t matchid = 0,
    int32_t winteam = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PvPFinishMember>>> members = 0) {
  DSPvPFinishGameBuilder builder_(_fbb);
  builder_.add_members(members);
  builder_.add_winteam(winteam);
  builder_.add_matchid(matchid);
  return builder_.Finish();
}

inline flatbuffers::Offset<DSPvPFinishGame> CreateDSPvPFinishGameDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t matchid = 0,
    int32_t winteam = 0,
    const std::vector<flatbuffers::Offset<PvPFinishMember>> *members = nullptr) {
  return Packet::Match::PvP::CreateDSPvPFinishGame(
      _fbb,
      matchid,
      winteam,
      members ? _fbb.CreateVector<flatbuffers::Offset<PvPFinishMember>>(*members) : 0);
}

inline const Packet::Match::PvP::DSPvPFinishGame *GetDSPvPFinishGame(const void *buf) {
  return flatbuffers::GetRoot<Packet::Match::PvP::DSPvPFinishGame>(buf);
}

inline const Packet::Match::PvP::DSPvPFinishGame *GetSizePrefixedDSPvPFinishGame(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Match::PvP::DSPvPFinishGame>(buf);
}

inline bool VerifyDSPvPFinishGameBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Match::PvP::DSPvPFinishGame>(nullptr);
}

inline bool VerifySizePrefixedDSPvPFinishGameBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Match::PvP::DSPvPFinishGame>(nullptr);
}

inline void FinishDSPvPFinishGameBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Match::PvP::DSPvPFinishGame> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDSPvPFinishGameBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Match::PvP::DSPvPFinishGame> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace PvP
}  // namespace Match
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DSPVPFINISHGAME_PACKET_MATCH_PVP_H_
