// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CTPRODUCTITEM_PACKET_CHARACTER_H_
#define FLATBUFFERS_GENERATED_CTPRODUCTITEM_PACKET_CHARACTER_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Character {

struct CTProductItem;

enum ProductResult {
  ProductResult_Success = 0,
  ProductResult_Fail = 1,
  ProductResult_MIN = ProductResult_Success,
  ProductResult_MAX = ProductResult_Fail
};

inline const ProductResult (&EnumValuesProductResult())[2] {
  static const ProductResult values[] = {
    ProductResult_Success,
    ProductResult_Fail
  };
  return values;
}

inline const char * const *EnumNamesProductResult() {
  static const char * const names[] = {
    "Success",
    "Fail",
    nullptr
  };
  return names;
}

inline const char *EnumNameProductResult(ProductResult e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesProductResult()[index];
}

struct CTProductItem FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARSID = 4,
    VT_TRANSACTION = 6,
    VT_ITEMID = 8,
    VT_RESULT = 10
  };
  int32_t charsid() const {
    return GetField<int32_t>(VT_CHARSID, 0);
  }
  int32_t transaction() const {
    return GetField<int32_t>(VT_TRANSACTION, 0);
  }
  int32_t itemid() const {
    return GetField<int32_t>(VT_ITEMID, 0);
  }
  ProductResult result() const {
    return static_cast<ProductResult>(GetField<uint32_t>(VT_RESULT, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CHARSID) &&
           VerifyField<int32_t>(verifier, VT_TRANSACTION) &&
           VerifyField<int32_t>(verifier, VT_ITEMID) &&
           VerifyField<uint32_t>(verifier, VT_RESULT) &&
           verifier.EndTable();
  }
};

struct CTProductItemBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charsid(int32_t charsid) {
    fbb_.AddElement<int32_t>(CTProductItem::VT_CHARSID, charsid, 0);
  }
  void add_transaction(int32_t transaction) {
    fbb_.AddElement<int32_t>(CTProductItem::VT_TRANSACTION, transaction, 0);
  }
  void add_itemid(int32_t itemid) {
    fbb_.AddElement<int32_t>(CTProductItem::VT_ITEMID, itemid, 0);
  }
  void add_result(ProductResult result) {
    fbb_.AddElement<uint32_t>(CTProductItem::VT_RESULT, static_cast<uint32_t>(result), 0);
  }
  explicit CTProductItemBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CTProductItemBuilder &operator=(const CTProductItemBuilder &);
  flatbuffers::Offset<CTProductItem> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CTProductItem>(end);
    return o;
  }
};

inline flatbuffers::Offset<CTProductItem> CreateCTProductItem(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t charsid = 0,
    int32_t transaction = 0,
    int32_t itemid = 0,
    ProductResult result = ProductResult_Success) {
  CTProductItemBuilder builder_(_fbb);
  builder_.add_result(result);
  builder_.add_itemid(itemid);
  builder_.add_transaction(transaction);
  builder_.add_charsid(charsid);
  return builder_.Finish();
}

inline const Packet::Character::CTProductItem *GetCTProductItem(const void *buf) {
  return flatbuffers::GetRoot<Packet::Character::CTProductItem>(buf);
}

inline const Packet::Character::CTProductItem *GetSizePrefixedCTProductItem(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Character::CTProductItem>(buf);
}

inline bool VerifyCTProductItemBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Character::CTProductItem>(nullptr);
}

inline bool VerifySizePrefixedCTProductItemBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Character::CTProductItem>(nullptr);
}

inline void FinishCTProductItemBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::CTProductItem> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCTProductItemBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Character::CTProductItem> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Character
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_CTPRODUCTITEM_PACKET_CHARACTER_H_
