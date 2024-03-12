// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/wrappers.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(WindGPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define WindGPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if WindGPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <WindFoundation/WindGPBDescriptor.h>
 #import <WindFoundation/WindGPBMessage.h>
 #import <WindFoundation/WindGPBRootObject.h>
#else
 #import "WindGPBDescriptor.h"
 #import "WindGPBMessage.h"
 #import "WindGPBRootObject.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30004
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30004 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

NS_ASSUME_NONNULL_BEGIN

#pragma mark - WindGPBWrappersRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (WindGPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c WindGPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
WindGPB_FINAL @interface WindGPBWrappersRoot : WindGPBRootObject
@end

#pragma mark - WindGPBDoubleValue

typedef WindGPB_ENUM(WindGPBDoubleValue_FieldNumber) {
  WindGPBDoubleValue_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `double`.
 *
 * The JSON representation for `DoubleValue` is JSON number.
 **/
WindGPB_FINAL @interface WindGPBDoubleValue : WindGPBMessage

/** The double value. */
@property(nonatomic, readwrite) double value;

@end

#pragma mark - WindGPBFloatValue

typedef WindGPB_ENUM(WindGPBFloatValue_FieldNumber) {
  WindGPBFloatValue_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `float`.
 *
 * The JSON representation for `FloatValue` is JSON number.
 **/
WindGPB_FINAL @interface WindGPBFloatValue : WindGPBMessage

/** The float value. */
@property(nonatomic, readwrite) float value;

@end

#pragma mark - WindGPBInt64Value

typedef WindGPB_ENUM(WindGPBInt64Value_FieldNumber) {
  WindGPBInt64Value_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `int64`.
 *
 * The JSON representation for `Int64Value` is JSON string.
 **/
WindGPB_FINAL @interface WindGPBInt64Value : WindGPBMessage

/** The int64 value. */
@property(nonatomic, readwrite) int64_t value;

@end

#pragma mark - WindGPBUInt64Value

typedef WindGPB_ENUM(WindGPBUInt64Value_FieldNumber) {
  WindGPBUInt64Value_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `uint64`.
 *
 * The JSON representation for `UInt64Value` is JSON string.
 **/
WindGPB_FINAL @interface WindGPBUInt64Value : WindGPBMessage

/** The uint64 value. */
@property(nonatomic, readwrite) uint64_t value;

@end

#pragma mark - WindGPBInt32Value

typedef WindGPB_ENUM(WindGPBInt32Value_FieldNumber) {
  WindGPBInt32Value_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `int32`.
 *
 * The JSON representation for `Int32Value` is JSON number.
 **/
WindGPB_FINAL @interface WindGPBInt32Value : WindGPBMessage

/** The int32 value. */
@property(nonatomic, readwrite) int32_t value;

@end

#pragma mark - WindGPBUInt32Value

typedef WindGPB_ENUM(WindGPBUInt32Value_FieldNumber) {
  WindGPBUInt32Value_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `uint32`.
 *
 * The JSON representation for `UInt32Value` is JSON number.
 **/
WindGPB_FINAL @interface WindGPBUInt32Value : WindGPBMessage

/** The uint32 value. */
@property(nonatomic, readwrite) uint32_t value;

@end

#pragma mark - WindGPBBoolValue

typedef WindGPB_ENUM(WindGPBBoolValue_FieldNumber) {
  WindGPBBoolValue_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `bool`.
 *
 * The JSON representation for `BoolValue` is JSON `true` and `false`.
 **/
WindGPB_FINAL @interface WindGPBBoolValue : WindGPBMessage

/** The bool value. */
@property(nonatomic, readwrite) BOOL value;

@end

#pragma mark - WindGPBStringValue

typedef WindGPB_ENUM(WindGPBStringValue_FieldNumber) {
  WindGPBStringValue_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `string`.
 *
 * The JSON representation for `StringValue` is JSON string.
 **/
WindGPB_FINAL @interface WindGPBStringValue : WindGPBMessage

/** The string value. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *value;

@end

#pragma mark - WindGPBBytesValue

typedef WindGPB_ENUM(WindGPBBytesValue_FieldNumber) {
  WindGPBBytesValue_FieldNumber_Value = 1,
};

/**
 * Wrapper message for `bytes`.
 *
 * The JSON representation for `BytesValue` is JSON string.
 **/
WindGPB_FINAL @interface WindGPBBytesValue : WindGPBMessage

/** The bytes value. */
@property(nonatomic, readwrite, copy, null_resettable) NSData *value;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)