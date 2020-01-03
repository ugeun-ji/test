// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CTSERVERLIST_PACKET_CLIENT_H_
#define FLATBUFFERS_GENERATED_CTSERVERLIST_PACKET_CLIENT_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Client {

struct DSInfo;

struct CTServerList;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) DSInfo FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t id_;
  int32_t userCnt_;

 public:
  DSInfo() {
    memset(this, 0, sizeof(DSInfo));
  }
  DSInfo(int32_t _id, int32_t _userCnt)
      : id_(flatbuffers::EndianScalar(_id)),
        userCnt_(flatbuffers::EndianScalar(_userCnt)) {
  }
  int32_t id() const {
    return flatbuffers::EndianScalar(id_);
  }
  int32_t userCnt() const {
    return flatbuffers::EndianScalar(userCnt_);
  }
};
FLATBUFFERS_STRUCT_END(DSInfo, 8);

struct CTServerList FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_DS = 4
  };
  const flatbuffers::Vector<const DSInfo *> *ds() const {
    return GetPointer<const flatbuffers::Vector<const DSInfo *> *>(VT_DS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_DS) &&
           verifier.VerifyVector(ds()) &&
           verifier.EndTable();
  }
};

struct CTServerListBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_ds(flatbuffers::Offset<flatbuffers::Vector<const DSInfo *>> ds) {
    fbb_.AddOffset(CTServerList::VT_DS, ds);
  }
  explicit CTServerListBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CTServerListBuilder &operator=(const CTServerListBuilder &);
  flatbuffers::Offset<CTServerList> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CTServerList>(end);
    return o;
  }
};

inline flatbuffers::Offset<CTServerList> CreateCTServerList(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<const DSInfo *>> ds = 0) {
  CTServerListBuilder builder_(_fbb);
  builder_.add_ds(ds);
  return builder_.Finish();
}

inline flatbuffers::Offset<CTServerList> CreateCTServerListDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<DSInfo> *ds = nullptr) {
  return Packet::Client::CreateCTServerList(
      _fbb,
      ds ? _fbb.CreateVectorOfStructs<DSInfo>(*ds) : 0);
}

inline const Packet::Client::CTServerList *GetCTServerList(const void *buf) {
  return flatbuffers::GetRoot<Packet::Client::CTServerList>(buf);
}

inline const Packet::Client::CTServerList *GetSizePrefixedCTServerList(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Client::CTServerList>(buf);
}

inline bool VerifyCTServerListBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Client::CTServerList>(nullptr);
}

inline bool VerifySizePrefixedCTServerListBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Client::CTServerList>(nullptr);
}

inline void FinishCTServerListBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Client::CTServerList> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCTServerListBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Client::CTServerList> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Client
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_CTSERVERLIST_PACKET_CLIENT_H_