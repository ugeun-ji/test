// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_EXCEPTION_PACKET_EXCEPTION_H_
#define FLATBUFFERS_GENERATED_EXCEPTION_PACKET_EXCEPTION_H_

#include "flatbuffers/flatbuffers.h"

namespace Packet {
namespace Exception {

struct ErrorCode;

enum Code {
  Code_OK = 0,
  Code_IO_BUFFER_OVERFLOW = 1,
  Code_INVALID_CHANNEL = 2,
  Code_INVALID_CHARACTER = 3,
  Code_INVALID_PARTY = 4,
  Code_OVERFLOW_PARTY = 5,
  Code_ALREADY_PARTY = 6,
  Code_NOT_PARTY = 7,
  Code_PARTY_DESTROYED = 8,
  Code_EXPIRED_DSSERVER = 9,
  Code_MUTEX_VIOLATION_DS = 10,
  Code_MUTEX_VIOLATION_CHAR = 11,
  Code_EXPIRED_CLIENT = 12,
  Code_INVALID_DSSERVER = 13,
  Code_INVALID_SA = 14,
  Code_UNKNOWN_EXCEPTION = 15,
  Code_UNKNOWN_DB_EXCEPTION = 16,
  Code_EXIST_CHARNAME = 17,
  Code_INVALID_CHARNAME_RULE = 18,
  Code_INVALID_VERIFICATION = 19,
  Code_FAILED_PVP_REGISTER_MATCH = 20,
  Code_FAILED_PARTY_MATCH = 21,
  Code_FAILED_PARTY_JOIN = 22,
  Code_INVALID_ITEMID = 23,
  Code_INVALID_ITEM = 24,
  Code_INVALID_PRODUCTION = 25,
  Code_NOT_ENOUGH_GOLD = 26,
  Code_NOT_ENOUGH_MATERIAL = 27,
  Code_INVALID_AMMO_ID = 28,
  Code_FAIL_PRODUCTION = 29,
  Code_INVALID_QUEST = 30,
  Code_INVALID_QUEST_OBJECTIVE = 31,
  Code_NOT_PARTY_MASTER = 32,
  Code_ALREADY_REGISTER = 33,
  Code_INVALID_TARGET = 34,
  Code_INVALID_DSSERVER_TYPE = 35,
  Code_TIMEOUT = 36,
  Code_INVALID_KEY = 37,
  Code_FAIL_CREATE_PARTY = 38,
  Code_VIOLATION_QUEST = 39,
  Code_EXIST_LOGIN = 40,
  Code_SAME_TARGET = 41,
  Code_INVALID_SELF = 42,
  Code_ALREADY_QUEST = 43,
  Code_VIOLATION_WAYPOINT = 44,
  Code_MIN = Code_OK,
  Code_MAX = Code_VIOLATION_WAYPOINT
};

inline const Code (&EnumValuesCode())[45] {
  static const Code values[] = {
    Code_OK,
    Code_IO_BUFFER_OVERFLOW,
    Code_INVALID_CHANNEL,
    Code_INVALID_CHARACTER,
    Code_INVALID_PARTY,
    Code_OVERFLOW_PARTY,
    Code_ALREADY_PARTY,
    Code_NOT_PARTY,
    Code_PARTY_DESTROYED,
    Code_EXPIRED_DSSERVER,
    Code_MUTEX_VIOLATION_DS,
    Code_MUTEX_VIOLATION_CHAR,
    Code_EXPIRED_CLIENT,
    Code_INVALID_DSSERVER,
    Code_INVALID_SA,
    Code_UNKNOWN_EXCEPTION,
    Code_UNKNOWN_DB_EXCEPTION,
    Code_EXIST_CHARNAME,
    Code_INVALID_CHARNAME_RULE,
    Code_INVALID_VERIFICATION,
    Code_FAILED_PVP_REGISTER_MATCH,
    Code_FAILED_PARTY_MATCH,
    Code_FAILED_PARTY_JOIN,
    Code_INVALID_ITEMID,
    Code_INVALID_ITEM,
    Code_INVALID_PRODUCTION,
    Code_NOT_ENOUGH_GOLD,
    Code_NOT_ENOUGH_MATERIAL,
    Code_INVALID_AMMO_ID,
    Code_FAIL_PRODUCTION,
    Code_INVALID_QUEST,
    Code_INVALID_QUEST_OBJECTIVE,
    Code_NOT_PARTY_MASTER,
    Code_ALREADY_REGISTER,
    Code_INVALID_TARGET,
    Code_INVALID_DSSERVER_TYPE,
    Code_TIMEOUT,
    Code_INVALID_KEY,
    Code_FAIL_CREATE_PARTY,
    Code_VIOLATION_QUEST,
    Code_EXIST_LOGIN,
    Code_SAME_TARGET,
    Code_INVALID_SELF,
    Code_ALREADY_QUEST,
    Code_VIOLATION_WAYPOINT
  };
  return values;
}

inline const char * const *EnumNamesCode() {
  static const char * const names[] = {
    "OK",
    "IO_BUFFER_OVERFLOW",
    "INVALID_CHANNEL",
    "INVALID_CHARACTER",
    "INVALID_PARTY",
    "OVERFLOW_PARTY",
    "ALREADY_PARTY",
    "NOT_PARTY",
    "PARTY_DESTROYED",
    "EXPIRED_DSSERVER",
    "MUTEX_VIOLATION_DS",
    "MUTEX_VIOLATION_CHAR",
    "EXPIRED_CLIENT",
    "INVALID_DSSERVER",
    "INVALID_SA",
    "UNKNOWN_EXCEPTION",
    "UNKNOWN_DB_EXCEPTION",
    "EXIST_CHARNAME",
    "INVALID_CHARNAME_RULE",
    "INVALID_VERIFICATION",
    "FAILED_PVP_REGISTER_MATCH",
    "FAILED_PARTY_MATCH",
    "FAILED_PARTY_JOIN",
    "INVALID_ITEMID",
    "INVALID_ITEM",
    "INVALID_PRODUCTION",
    "NOT_ENOUGH_GOLD",
    "NOT_ENOUGH_MATERIAL",
    "INVALID_AMMO_ID",
    "FAIL_PRODUCTION",
    "INVALID_QUEST",
    "INVALID_QUEST_OBJECTIVE",
    "NOT_PARTY_MASTER",
    "ALREADY_REGISTER",
    "INVALID_TARGET",
    "INVALID_DSSERVER_TYPE",
    "TIMEOUT",
    "INVALID_KEY",
    "FAIL_CREATE_PARTY",
    "VIOLATION_QUEST",
    "EXIST_LOGIN",
    "SAME_TARGET",
    "INVALID_SELF",
    "ALREADY_QUEST",
    "VIOLATION_WAYPOINT",
    nullptr
  };
  return names;
}

inline const char *EnumNameCode(Code e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesCode()[index];
}

struct ErrorCode FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_REQ = 4,
    VT_CODE = 6,
    VT_CONDITION = 8,
    VT_STRV = 10
  };
  uint16_t req() const {
    return GetField<uint16_t>(VT_REQ, 0);
  }
  Code code() const {
    return static_cast<Code>(GetField<uint32_t>(VT_CODE, 0));
  }
  int64_t condition() const {
    return GetField<int64_t>(VT_CONDITION, 0);
  }
  const flatbuffers::String *strv() const {
    return GetPointer<const flatbuffers::String *>(VT_STRV);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_REQ) &&
           VerifyField<uint32_t>(verifier, VT_CODE) &&
           VerifyField<int64_t>(verifier, VT_CONDITION) &&
           VerifyOffset(verifier, VT_STRV) &&
           verifier.VerifyString(strv()) &&
           verifier.EndTable();
  }
};

struct ErrorCodeBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_req(uint16_t req) {
    fbb_.AddElement<uint16_t>(ErrorCode::VT_REQ, req, 0);
  }
  void add_code(Code code) {
    fbb_.AddElement<uint32_t>(ErrorCode::VT_CODE, static_cast<uint32_t>(code), 0);
  }
  void add_condition(int64_t condition) {
    fbb_.AddElement<int64_t>(ErrorCode::VT_CONDITION, condition, 0);
  }
  void add_strv(flatbuffers::Offset<flatbuffers::String> strv) {
    fbb_.AddOffset(ErrorCode::VT_STRV, strv);
  }
  explicit ErrorCodeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ErrorCodeBuilder &operator=(const ErrorCodeBuilder &);
  flatbuffers::Offset<ErrorCode> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ErrorCode>(end);
    return o;
  }
};

inline flatbuffers::Offset<ErrorCode> CreateErrorCode(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t req = 0,
    Code code = Code_OK,
    int64_t condition = 0,
    flatbuffers::Offset<flatbuffers::String> strv = 0) {
  ErrorCodeBuilder builder_(_fbb);
  builder_.add_condition(condition);
  builder_.add_strv(strv);
  builder_.add_code(code);
  builder_.add_req(req);
  return builder_.Finish();
}

inline flatbuffers::Offset<ErrorCode> CreateErrorCodeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t req = 0,
    Code code = Code_OK,
    int64_t condition = 0,
    const char *strv = nullptr) {
  return Packet::Exception::CreateErrorCode(
      _fbb,
      req,
      code,
      condition,
      strv ? _fbb.CreateString(strv) : 0);
}

inline const Packet::Exception::ErrorCode *GetErrorCode(const void *buf) {
  return flatbuffers::GetRoot<Packet::Exception::ErrorCode>(buf);
}

inline const Packet::Exception::ErrorCode *GetSizePrefixedErrorCode(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Packet::Exception::ErrorCode>(buf);
}

inline bool VerifyErrorCodeBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Packet::Exception::ErrorCode>(nullptr);
}

inline bool VerifySizePrefixedErrorCodeBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Packet::Exception::ErrorCode>(nullptr);
}

inline void FinishErrorCodeBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Exception::ErrorCode> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedErrorCodeBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Packet::Exception::ErrorCode> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Exception
}  // namespace Packet

#endif  // FLATBUFFERS_GENERATED_EXCEPTION_PACKET_EXCEPTION_H_
