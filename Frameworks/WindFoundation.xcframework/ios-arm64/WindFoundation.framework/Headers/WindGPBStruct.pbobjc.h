// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/struct.proto

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

@class WindGPBListValue;
@class WindGPBStruct;
@class WindGPBValue;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum WindGPBNullValue

/**
 * `NullValue` is a singleton enumeration to represent the null value for the
 * `Value` type union.
 *
 *  The JSON representation for `NullValue` is JSON `null`.
 **/
typedef WindGPB_ENUM(WindGPBNullValue) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  WindGPBNullValue_WindGPBUnrecognizedEnumeratorValue = kWindGPBUnrecognizedEnumeratorValue,
  /** Null value. */
  WindGPBNullValue_NullValue = 0,
};

WindGPBEnumDescriptor *WindGPBNullValue_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL WindGPBNullValue_IsValidValue(int32_t value);

#pragma mark - WindGPBStructRoot

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
WindGPB_FINAL @interface WindGPBStructRoot : WindGPBRootObject
@end

#pragma mark - WindGPBStruct

typedef WindGPB_ENUM(WindGPBStruct_FieldNumber) {
  WindGPBStruct_FieldNumber_Fields = 1,
};

/**
 * `Struct` represents a structured data value, consisting of fields
 * which map to dynamically typed values. In some languages, `Struct`
 * might be supported by a native representation. For example, in
 * scripting languages like JS a struct is represented as an
 * object. The details of that representation are described together
 * with the proto support for the language.
 *
 * The JSON representation for `Struct` is JSON object.
 **/
WindGPB_FINAL @interface WindGPBStruct : WindGPBMessage

/** Unordered map of dynamically typed values. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableDictionary<NSString*, WindGPBValue*> *fields;
/** The number of items in @c fields without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger fields_Count;

@end

#pragma mark - WindGPBValue

typedef WindGPB_ENUM(WindGPBValue_FieldNumber) {
  WindGPBValue_FieldNumber_NullValue = 1,
  WindGPBValue_FieldNumber_NumberValue = 2,
  WindGPBValue_FieldNumber_StringValue = 3,
  WindGPBValue_FieldNumber_BoolValue = 4,
  WindGPBValue_FieldNumber_StructValue = 5,
  WindGPBValue_FieldNumber_ListValue = 6,
};

typedef WindGPB_ENUM(WindGPBValue_Kind_OneOfCase) {
  WindGPBValue_Kind_OneOfCase_WindGPBUnsetOneOfCase = 0,
  WindGPBValue_Kind_OneOfCase_NullValue = 1,
  WindGPBValue_Kind_OneOfCase_NumberValue = 2,
  WindGPBValue_Kind_OneOfCase_StringValue = 3,
  WindGPBValue_Kind_OneOfCase_BoolValue = 4,
  WindGPBValue_Kind_OneOfCase_StructValue = 5,
  WindGPBValue_Kind_OneOfCase_ListValue = 6,
};

/**
 * `Value` represents a dynamically typed value which can be either
 * null, a number, a string, a boolean, a recursive struct value, or a
 * list of values. A producer of value is expected to set one of that
 * variants, absence of any variant indicates an error.
 *
 * The JSON representation for `Value` is JSON value.
 **/
WindGPB_FINAL @interface WindGPBValue : WindGPBMessage

/** The kind of value. */
@property(nonatomic, readonly) WindGPBValue_Kind_OneOfCase kindOneOfCase;

/** Represents a null value. */
@property(nonatomic, readwrite) WindGPBNullValue nullValue;

/** Represents a double value. */
@property(nonatomic, readwrite) double numberValue;

/** Represents a string value. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *stringValue;

/** Represents a boolean value. */
@property(nonatomic, readwrite) BOOL boolValue;

/** Represents a structured value. */
@property(nonatomic, readwrite, strong, null_resettable) WindGPBStruct *structValue;

/** Represents a repeated `Value`. */
@property(nonatomic, readwrite, strong, null_resettable) WindGPBListValue *listValue;

@end

/**
 * Fetches the raw value of a @c WindGPBValue's @c nullValue property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t WindGPBValue_NullValue_RawValue(WindGPBValue *message);
/**
 * Sets the raw value of an @c WindGPBValue's @c nullValue property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetWindGPBValue_NullValue_RawValue(WindGPBValue *message, int32_t value);

/**
 * Clears whatever value was set for the oneof 'kind'.
 **/
void WindGPBValue_ClearKindOneOfCase(WindGPBValue *message);

#pragma mark - WindGPBListValue

typedef WindGPB_ENUM(WindGPBListValue_FieldNumber) {
  WindGPBListValue_FieldNumber_ValuesArray = 1,
};

/**
 * `ListValue` is a wrapper around a repeated field of values.
 *
 * The JSON representation for `ListValue` is JSON array.
 **/
WindGPB_FINAL @interface WindGPBListValue : WindGPBMessage

/** Repeated field of dynamically typed values. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<WindGPBValue*> *valuesArray;
/** The number of items in @c valuesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger valuesArray_Count;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
