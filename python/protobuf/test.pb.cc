// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

class ResponseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Response>
      _instance;
} _Response_default_instance_;
namespace protobuf_test_2eproto {
static void InitDefaultsResponse() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Response_default_instance_;
    new (ptr) ::Response();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Response::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Response =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsResponse}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Response.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Response, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Response, status_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Response, wait_time_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Response, fail_reson_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Response, door_opened_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Response)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Response_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "test.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\ntest.proto\"\312\002\n\010Response\022 \n\006status\030\001 \001("
      "\0162\020.Response.Status\022\021\n\twait_time\030\002 \001(\r\022("
      "\n\nfail_reson\030\003 \001(\0162\024.Response.FailReason"
      "\022\023\n\013door_opened\030\004 \001(\010\"m\n\006Status\022\013\n\007INVAL"
      "ID\020\000\022\022\n\016START_POWEROFF\020\001\022\024\n\020PROCESS_POWE"
      "ROFF\020\002\022\023\n\017CANCLE_POWEROFF\020\003\022\013\n\007SUCCESS\020\004"
      "\022\n\n\006FAILED\020\005\"[\n\nFailReason\022\010\n\004NONE\020\000\022\016\n\n"
      "GEAR_STATE\020\001\022\t\n\005SPEED\020\002\022\007\n\003EPB\020\003\022\020\n\014DEST"
      "INATIONS\020\004\022\r\n\tAUTO_MODE\020\005b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 353);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "test.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_test_2eproto
const ::google::protobuf::EnumDescriptor* Response_Status_descriptor() {
  protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_test_2eproto::file_level_enum_descriptors[0];
}
bool Response_Status_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const Response_Status Response::INVALID;
const Response_Status Response::START_POWEROFF;
const Response_Status Response::PROCESS_POWEROFF;
const Response_Status Response::CANCLE_POWEROFF;
const Response_Status Response::SUCCESS;
const Response_Status Response::FAILED;
const Response_Status Response::Status_MIN;
const Response_Status Response::Status_MAX;
const int Response::Status_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
const ::google::protobuf::EnumDescriptor* Response_FailReason_descriptor() {
  protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_test_2eproto::file_level_enum_descriptors[1];
}
bool Response_FailReason_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const Response_FailReason Response::NONE;
const Response_FailReason Response::GEAR_STATE;
const Response_FailReason Response::SPEED;
const Response_FailReason Response::EPB;
const Response_FailReason Response::DESTINATIONS;
const Response_FailReason Response::AUTO_MODE;
const Response_FailReason Response::FailReason_MIN;
const Response_FailReason Response::FailReason_MAX;
const int Response::FailReason_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void Response::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Response::kStatusFieldNumber;
const int Response::kWaitTimeFieldNumber;
const int Response::kFailResonFieldNumber;
const int Response::kDoorOpenedFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Response::Response()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_test_2eproto::scc_info_Response.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Response)
}
Response::Response(const Response& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&status_, &from.status_,
    static_cast<size_t>(reinterpret_cast<char*>(&door_opened_) -
    reinterpret_cast<char*>(&status_)) + sizeof(door_opened_));
  // @@protoc_insertion_point(copy_constructor:Response)
}

void Response::SharedCtor() {
  ::memset(&status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&door_opened_) -
      reinterpret_cast<char*>(&status_)) + sizeof(door_opened_));
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:Response)
  SharedDtor();
}

void Response::SharedDtor() {
}

void Response::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Response::descriptor() {
  ::protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_test_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Response& Response::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_test_2eproto::scc_info_Response.base);
  return *internal_default_instance();
}


void Response::Clear() {
// @@protoc_insertion_point(message_clear_start:Response)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&door_opened_) -
      reinterpret_cast<char*>(&status_)) + sizeof(door_opened_));
  _internal_metadata_.Clear();
}

bool Response::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Response)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .Response.Status status = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_status(static_cast< ::Response_Status >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 wait_time = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &wait_time_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .Response.FailReason fail_reson = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_fail_reson(static_cast< ::Response_FailReason >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool door_opened = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &door_opened_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Response)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Response)
  return false;
#undef DO_
}

void Response::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Response)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Response.Status status = 1;
  if (this->status() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->status(), output);
  }

  // uint32 wait_time = 2;
  if (this->wait_time() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->wait_time(), output);
  }

  // .Response.FailReason fail_reson = 3;
  if (this->fail_reson() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->fail_reson(), output);
  }

  // bool door_opened = 4;
  if (this->door_opened() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->door_opened(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Response)
}

::google::protobuf::uint8* Response::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Response)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Response.Status status = 1;
  if (this->status() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->status(), target);
  }

  // uint32 wait_time = 2;
  if (this->wait_time() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->wait_time(), target);
  }

  // .Response.FailReason fail_reson = 3;
  if (this->fail_reson() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->fail_reson(), target);
  }

  // bool door_opened = 4;
  if (this->door_opened() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->door_opened(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Response)
  return target;
}

size_t Response::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Response)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .Response.Status status = 1;
  if (this->status() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->status());
  }

  // uint32 wait_time = 2;
  if (this->wait_time() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->wait_time());
  }

  // .Response.FailReason fail_reson = 3;
  if (this->fail_reson() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->fail_reson());
  }

  // bool door_opened = 4;
  if (this->door_opened() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Response::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Response)
  GOOGLE_DCHECK_NE(&from, this);
  const Response* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Response>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Response)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Response)
    MergeFrom(*source);
  }
}

void Response::MergeFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Response)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.status() != 0) {
    set_status(from.status());
  }
  if (from.wait_time() != 0) {
    set_wait_time(from.wait_time());
  }
  if (from.fail_reson() != 0) {
    set_fail_reson(from.fail_reson());
  }
  if (from.door_opened() != 0) {
    set_door_opened(from.door_opened());
  }
}

void Response::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Response::CopyFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {
  return true;
}

void Response::Swap(Response* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Response::InternalSwap(Response* other) {
  using std::swap;
  swap(status_, other->status_);
  swap(wait_time_, other->wait_time_);
  swap(fail_reson_, other->fail_reson_);
  swap(door_opened_, other->door_opened_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Response::GetMetadata() const {
  protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_test_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Response* Arena::CreateMaybeMessage< ::Response >(Arena* arena) {
  return Arena::CreateInternal< ::Response >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)