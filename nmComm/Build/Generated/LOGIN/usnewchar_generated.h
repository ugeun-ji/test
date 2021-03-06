// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_USNEWCHAR_PACKET_LOGIN_H_
#define FLATBUFFERS_GENERATED_USNEWCHAR_PACKET_LOGIN_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Login {

struct USNewChar;

struct USNewChar FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARNAME = 4,
    VT_GENDER = 6,
    VT_HAIR = 8,
    VT_ARMORSET = 10
  };
  const flatbuffers::String *charName() const {
    return GetPointer<const flatbuffers::String *>(VT_CHARNAME);
  }
  int8_t gender() const {
    return GetField<int8_t>(VT_GENDER, 0);
  }
  int8_t hair() const {
    return GetField<int8_t>(VT_HAIR, 0);
  }
  int8_t armorset() const {
    return GetField<int8_t>(VT_ARMORSET, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CHARNAME) &&
           verifier.VerifyString(charName()) &&
           VerifyField<int8_t>(verifier, VT_GENDER) &&
           VerifyField<int8_t>(verifier, VT_HAIR) &&
           VerifyField<int8_t>(verifier, VT_ARMORSET) &&
           verifier.EndTable();
  }
};

struct USNewCharBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_charName(flatbuffers::Offset<flatbuffers::String> charName) {
    fbb_.AddOffset(USNewChar::VT_CHARNAME, charName);
  }
  void add_gender(int8_t gender) {
    fbb_.AddElement<int8_t>(USNewChar::VT_GENDER, gender, 0);
  }
  void add_hair(int8_t hair) {
    fbb_.AddElement<int8_t>(USNewChar::VT_HAIR, hair, 0);
  }
  void add_armorset(int8_t armorset) {
    fbb_.AddElement<int8_t>(USNewChar::VT_ARMORSET, armorset, 0);
  }
  explicit USNewCharBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  USNewCharBuilder &operator=(const USNewCharBuilder &);
  flatbuffers::Offset<USNewChar> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<USNewChar>(end);
    return o;
  }
};

inline flatbuffers::Offset<USNewChar> CreateUSNewChar(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> charName = 0,
    int8_t gender = 0,
    int8_t hair = 0,
    int8_t armorset = 0) {
  USNewCharBuilder builder_(_fbb);
  builder_.add_charName(charName);
  builder_.add_armorset(armorset);
  builder_.add_hair(hair);
  builder_.add_gender(gender);
  return builder_.Finish();
}

inline flatbuffers::Offset<USNewChar> CreateUSNewCharDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *charName = nullptr,
    int8_t gender = 0,
    int8_t hair = 0,
    int8_t armorset = 0) {
  return Packet::Login::CreateUSNewChar(
      _fbb,
      charName ? _fbb.CreateString(charName) : 0,
      gender,
      hair,
      armorset);
}

inline const Packet::Login::USNewChar *GetUSNewChar(const void *buf) {
  return flatbuffers::GetRoot<Packet::Login::USNewChar>(buf);
}

inline const Packet::Login::USNewChar *GetSizePrefixedUSNewChar(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Login::USNewChar>(buf);
}

inline bool VerifyUSNewCharBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Login::USNewChar>(nullptr);
}

inline bool VerifySizePrefixedUSNewCharBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Login::USNewChar>(nullptr);
}

inline void FinishUSNewCharBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Login::USNewChar> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedUSNewCharBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Login::USNewChar> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Login
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_USNEWCHAR_PACKET_LOGIN_H_
