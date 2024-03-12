// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/**
 * The Objective C runtime has complete enough info that most protos don’t end
 * up using this, so leaving it on is no cost or very little cost.  If you
 * happen to see it causing bloat, this is the way to disable it. If you do
 * need to disable it, try only disabling it for Release builds as having
 * full TextFormat can be useful for debugging.
 **/
#ifndef WindGPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
#define WindGPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS 0
#endif

// Used in the generated code to give sizes to enums. int32_t was chosen based
// on the fact that Protocol Buffers enums are limited to this range.
#if !__has_feature(objc_fixed_enum)
 #error All supported Xcode versions should support objc_fixed_enum.
#endif

// If the headers are imported into Objective-C++, we can run into an issue
// where the definition of NS_ENUM (really CF_ENUM) changes based on the C++
// standard that is in effect.  If it isn't C++11 or higher, the definition
// doesn't allow us to forward declare. We work around this one case by
// providing a local definition. The default case has to use NS_ENUM for the
// magic that is Swift bridging of enums.
#if (defined(__cplusplus) && __cplusplus && __cplusplus < 201103L)
 #define WindGPB_ENUM(X) enum X : int32_t X; enum X : int32_t
#else
 #define WindGPB_ENUM(X) NS_ENUM(int32_t, X)
#endif

/**
 * WindGPB_ENUM_FWD_DECLARE is used for forward declaring enums, for example:
 *
 * ```
 * WindGPB_ENUM_FWD_DECLARE(Foo_Enum)
 *
 * @interface BarClass : NSObject
 * @property (nonatomic) enum Foo_Enum value;
 * - (void)bazMethod:(enum Foo_Enum):value;
 * @end
 * ```
 **/
#define WindGPB_ENUM_FWD_DECLARE(X) enum X : int32_t

/**
 * Based upon CF_INLINE. Forces inlining in non DEBUG builds.
 **/
#if !defined(DEBUG)
#define WindGPB_INLINE static __inline__ __attribute__((always_inline))
#else
#define WindGPB_INLINE static __inline__
#endif

/**
 * For use in public headers that might need to deal with ARC.
 **/
#ifndef WindGPB_UNSAFE_UNRETAINED
#if __has_feature(objc_arc)
#define WindGPB_UNSAFE_UNRETAINED __unsafe_unretained
#else
#define WindGPB_UNSAFE_UNRETAINED
#endif
#endif

/**
 * Attribute used for Objective-C proto interface deprecations without messages.
 **/
#ifndef WindGPB_DEPRECATED
#define WindGPB_DEPRECATED __attribute__((deprecated))
#endif

/**
 * Attribute used for Objective-C proto interface deprecations with messages.
 **/
#ifndef WindGPB_DEPRECATED_MSG
#if __has_extension(attribute_deprecated_with_message)
#define WindGPB_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#else
#define WindGPB_DEPRECATED_MSG(msg) __attribute__((deprecated))
#endif
#endif

// If property name starts with init we need to annotate it to get past ARC.
// http://stackoverflow.com/questions/18723226/how-do-i-annotate-an-objective-c-property-with-an-objc-method-family/18723227#18723227
//
// Meant to be used internally by generated code.
#define WindGPB_METHOD_FAMILY_NONE __attribute__((objc_method_family(none)))

// Prevent subclassing of generated proto classes.
#ifndef WindGPB_FINAL
#define WindGPB_FINAL __attribute__((objc_subclassing_restricted))
#endif  // WindGPB_FINAL

// ----------------------------------------------------------------------------
// These version numbers are all internal to the ObjC Protobuf runtime; they
// are used to ensure compatibility between the generated sources and the
// headers being compiled against and/or the version of sources being run
// against.
//
// They are all #defines so the values are captured into every .o file they
// are used in and to allow comparisons in the preprocessor.

// Current library runtime version.
// - Gets bumped when the runtime makes changes to the interfaces between the
//   generated code and runtime (things added/removed, etc).
#define GOOGLE_PROTOBUF_OBJC_VERSION 30004

// Minimum runtime version supported for compiling/running against.
// - Gets changed when support for the older generated code is dropped.
#define GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION 30001


// This is a legacy constant now frozen in time for old generated code. If
// GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION ever gets moved above 30001 then
// this should also change to break code compiled with an old runtime that
// can't be supported any more.
#define GOOGLE_PROTOBUF_OBJC_GEN_VERSION 30001
