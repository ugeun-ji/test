// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DASERVERINFO_PACKET_CHANNEL_H_
#define FLATBUFFERS_GENERATED_DASERVERINFO_PACKET_CHANNEL_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Channel {

struct DAServerInfo;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(8) DAServerInfo FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t dsid_;
  int32_t chid_;
  uint64_t hash_;

 public:
  DAServerInfo() {
    memset(this, 0, sizeof(DAServerInfo));
  }
  DAServerInfo(int32_t _dsid, int32_t _chid, uint64_t _hash)
      : dsid_(flatbuffers::EndianScalar(_dsid)),
        chid_(flatbuffers::EndianScalar(_chid)),
        hash_(flatbuffers::EndianScalar(_hash)) {
  }
  int32_t dsid() const {
    return flatbuffers::EndianScalar(dsid_);
  }
  int32_t chid() const {
    return flatbuffers::EndianScalar(chid_);
  }
  uint64_t hash() const {
    return flatbuffers::EndianScalar(hash_);
  }
};
FLATBUFFERS_STRUCT_END(DAServerInfo, 16);

}  // namespace Channel
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DASERVERINFO_PACKET_CHANNEL_H_
