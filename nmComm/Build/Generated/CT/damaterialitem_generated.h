// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DAMATERIALITEM_PACKET_CHARACTER_H_
#define FLATBUFFERS_GENERATED_DAMATERIALITEM_PACKET_CHARACTER_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Character {

struct DAMaterialItem;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(8) DAMaterialItem FLATBUFFERS_FINAL_CLASS {
 private:
  int64_t sid_;
  int32_t itemid_;
  int32_t cnt_;

 public:
  DAMaterialItem() {
    memset(this, 0, sizeof(DAMaterialItem));
  }
  DAMaterialItem(int64_t _sid, int32_t _itemid, int32_t _cnt)
      : sid_(flatbuffers::EndianScalar(_sid)),
        itemid_(flatbuffers::EndianScalar(_itemid)),
        cnt_(flatbuffers::EndianScalar(_cnt)) {
  }
  int64_t sid() const {
    return flatbuffers::EndianScalar(sid_);
  }
  int32_t itemid() const {
    return flatbuffers::EndianScalar(itemid_);
  }
  int32_t cnt() const {
    return flatbuffers::EndianScalar(cnt_);
  }
};
FLATBUFFERS_STRUCT_END(DAMaterialItem, 16);

}  // namespace Character
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DAMATERIALITEM_PACKET_CHARACTER_H_
