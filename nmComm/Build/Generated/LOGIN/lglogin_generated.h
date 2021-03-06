// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_LGLOGIN_PACKET_LOGIN_H_
#define FLATBUFFERS_GENERATED_LGLOGIN_PACKET_LOGIN_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Login {

struct LGLogin;

enum LoginErrorCode {
  LoginErrorCode_Ok = 0,
  LoginErrorCode_InvalidAuth = 1,
  LoginErrorCode_MIN = LoginErrorCode_Ok,
  LoginErrorCode_MAX = LoginErrorCode_InvalidAuth
};

inline const LoginErrorCode (&EnumValuesLoginErrorCode())[2] {
  static const LoginErrorCode values[] = {
    LoginErrorCode_Ok,
    LoginErrorCode_InvalidAuth
  };
  return values;
}

inline const char * const *EnumNamesLoginErrorCode() {
  static const char * const names[] = {
    "Ok",
    "InvalidAuth",
    nullptr
  };
  return names;
}

inline const char *EnumNameLoginErrorCode(LoginErrorCode e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesLoginErrorCode()[index];
}

struct LGLogin FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_USERID = 4,
    VT_TOKEN = 6,
    VT_CODE = 8
  };
  const flatbuffers::String *userid() const {
    return GetPointer<const flatbuffers::String *>(VT_USERID);
  }
  const flatbuffers::String *token() const {
    return GetPointer<const flatbuffers::String *>(VT_TOKEN);
  }
  LoginErrorCode code() const {
    return static_cast<LoginErrorCode>(GetField<uint32_t>(VT_CODE, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_USERID) &&
           verifier.VerifyString(userid()) &&
           VerifyOffset(verifier, VT_TOKEN) &&
           verifier.VerifyString(token()) &&
           VerifyField<uint32_t>(verifier, VT_CODE) &&
           verifier.EndTable();
  }
};

struct LGLoginBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_userid(flatbuffers::Offset<flatbuffers::String> userid) {
    fbb_.AddOffset(LGLogin::VT_USERID, userid);
  }
  void add_token(flatbuffers::Offset<flatbuffers::String> token) {
    fbb_.AddOffset(LGLogin::VT_TOKEN, token);
  }
  void add_code(LoginErrorCode code) {
    fbb_.AddElement<uint32_t>(LGLogin::VT_CODE, static_cast<uint32_t>(code), 0);
  }
  explicit LGLoginBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  LGLoginBuilder &operator=(const LGLoginBuilder &);
  flatbuffers::Offset<LGLogin> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<LGLogin>(end);
    return o;
  }
};

inline flatbuffers::Offset<LGLogin> CreateLGLogin(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> userid = 0,
    flatbuffers::Offset<flatbuffers::String> token = 0,
    LoginErrorCode code = LoginErrorCode_Ok) {
  LGLoginBuilder builder_(_fbb);
  builder_.add_code(code);
  builder_.add_token(token);
  builder_.add_userid(userid);
  return builder_.Finish();
}

inline flatbuffers::Offset<LGLogin> CreateLGLoginDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *userid = nullptr,
    const char *token = nullptr,
    LoginErrorCode code = LoginErrorCode_Ok) {
  return Packet::Login::CreateLGLogin(
      _fbb,
      userid ? _fbb.CreateString(userid) : 0,
      token ? _fbb.CreateString(token) : 0,
      code);
}

inline const Packet::Login::LGLogin *GetLGLogin(const void *buf) {
  return flatbuffers::GetRoot<Packet::Login::LGLogin>(buf);
}

inline const Packet::Login::LGLogin *GetSizePrefixedLGLogin(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Login::LGLogin>(buf);
}

inline bool VerifyLGLoginBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Login::LGLogin>(nullptr);
}

inline bool VerifySizePrefixedLGLoginBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Login::LGLogin>(nullptr);
}

inline void FinishLGLoginBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Login::LGLogin> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedLGLoginBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Login::LGLogin> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Login
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_LGLOGIN_PACKET_LOGIN_H_
