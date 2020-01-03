// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_USSERVERLIST_PACKET_CLIENT_H_
#define FLATBUFFERS_GENERATED_USSERVERLIST_PACKET_CLIENT_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Client {

struct USServerList;

struct USServerList FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_RESERVED = 4
  };
  int32_t reserved() const {
    return GetField<int32_t>(VT_RESERVED, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_RESERVED) &&
           verifier.EndTable();
  }
};

struct USServerListBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_reserved(int32_t reserved) {
    fbb_.AddElement<int32_t>(USServerList::VT_RESERVED, reserved, 0);
  }
  explicit USServerListBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  USServerListBuilder &operator=(const USServerListBuilder &);
  flatbuffers::Offset<USServerList> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<USServerList>(end);
    return o;
  }
};

inline flatbuffers::Offset<USServerList> CreateUSServerList(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t reserved = 0) {
  USServerListBuilder builder_(_fbb);
  builder_.add_reserved(reserved);
  return builder_.Finish();
}

inline const Packet::Client::USServerList *GetUSServerList(const void *buf) {
  return flatbuffers::GetRoot<Packet::Client::USServerList>(buf);
}

inline const Packet::Client::USServerList *GetSizePrefixedUSServerList(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Client::USServerList>(buf);
}

inline bool VerifyUSServerListBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Client::USServerList>(nullptr);
}

inline bool VerifySizePrefixedUSServerListBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Client::USServerList>(nullptr);
}

inline void FinishUSServerListBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Client::USServerList> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedUSServerListBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Client::USServerList> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Client
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_USSERVERLIST_PACKET_CLIENT_H_
