// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DAMATERIALINVENTORY_PACKET_CHARACTER_H_
#define FLATBUFFERS_GENERATED_DAMATERIALINVENTORY_PACKET_CHARACTER_H_

#include "flatbuffers/flatbuffers.h"

#include "damaterialitem_generated.h"

namespace Packet {
namespace Character {

struct DAMaterialInventory;

struct DAMaterialInventory FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ITEMS = 4
  };
  const flatbuffers::Vector<const DAMaterialItem *> *items() const {
    return GetPointer<const flatbuffers::Vector<const DAMaterialItem *> *>(VT_ITEMS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ITEMS) &&
           verifier.VerifyVector(items()) &&
           verifier.EndTable();
  }
};

struct DAMaterialInventoryBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_items(flatbuffers::Offset<flatbuffers::Vector<const DAMaterialItem *>> items) {
    fbb_.AddOffset(DAMaterialInventory::VT_ITEMS, items);
  }
  explicit DAMaterialInventoryBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DAMaterialInventoryBuilder &operator=(const DAMaterialInventoryBuilder &);
  flatbuffers::Offset<DAMaterialInventory> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DAMaterialInventory>(end);
    return o;
  }
};

inline flatbuffers::Offset<DAMaterialInventory> CreateDAMaterialInventory(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<const DAMaterialItem *>> items = 0) {
  DAMaterialInventoryBuilder builder_(_fbb);
  builder_.add_items(items);
  return builder_.Finish();
}

inline flatbuffers::Offset<DAMaterialInventory> CreateDAMaterialInventoryDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<DAMaterialItem> *items = nullptr) {
  return Packet::Character::CreateDAMaterialInventory(
      _fbb,
      items ? _fbb.CreateVectorOfStructs<DAMaterialItem>(*items) : 0);
}

}  // namespace Character
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_DAMATERIALINVENTORY_PACKET_CHARACTER_H_