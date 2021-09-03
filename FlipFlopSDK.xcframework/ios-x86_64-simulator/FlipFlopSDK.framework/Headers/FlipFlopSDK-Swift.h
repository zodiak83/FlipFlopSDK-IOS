// Generated by Apple Swift version 5.4 (swiftlang-1205.0.26.9 clang-1205.0.19.55)
#ifndef FLIPFLOPSDK_SWIFT_H
#define FLIPFLOPSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import AVFoundation;
@import AVKit;
@import CoreGraphics;
@import CoreMedia;
@import Foundation;
@import GLKit;
@import MetalKit;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="FlipFlopSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSString;

/// The ASUndefined class represents an undefined for ActionScript.
SWIFT_CLASS("_TtC11FlipFlopSDK11ASUndefined")
@interface ASUndefined : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// ActionScript 3.0 introduces a new XML type.
/// seealso:
/// 3.13 XML type (amf-file-format-spec.pdf)
SWIFT_CLASS("_TtC11FlipFlopSDK5ASXML")
@interface ASXML : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// ActionScript 1.0 and 2.0 and flash.xml.XMLDocument in ActionScript 3.0
/// seealso:
///
/// <ul>
///   <li>
///     2.17 XML Document Type (amf0-file-format-specification.pdf)
///   </li>
///   <li>
///     3.9 XMLDocument type (amf-file-format-spec.pdf)
///   </li>
/// </ul>
SWIFT_CLASS("_TtC11FlipFlopSDK13ASXMLDocument")
@interface ASXMLDocument : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end





SWIFT_CLASS("_TtC11FlipFlopSDK10AVRecorder")
@interface AVRecorder : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC11FlipFlopSDK11AudioEffect")
@interface AudioEffect : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@class NSNumber;

/// It allows asynchronous tasks, has a pause and resume states,
/// can be easily added to a queue and can be created with a block.
SWIFT_CLASS("_TtC11FlipFlopSDK19ConcurrentOperation")
@interface ConcurrentOperation : NSOperation
/// Set the <code>Operation</code> as asynchronous.
@property (nonatomic, readonly, getter=isAsynchronous) BOOL asynchronous;
/// Set if the <code>Operation</code> is executing.
@property (nonatomic, readonly, getter=isExecuting) BOOL executing;
/// Set if the <code>Operation</code> is finished.
@property (nonatomic, readonly, getter=isFinished) BOOL finished;
/// Start the <code>Operation</code>.
- (void)start;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC11FlipFlopSDK25DefaultAVRecorderDelegate")
@interface DefaultAVRecorderDelegate : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class AVAssetWriterInput;
@class AVAssetWriterInputPixelBufferAdaptor;

@interface DefaultAVRecorderDelegate (SWIFT_EXTENSION(FlipFlopSDK))
- (void)rotateFile:(AVRecorder * _Nonnull)recorder withPresentationTimeStamp:(CMTime)withPresentationTimeStamp mediaType:(AVMediaType _Nonnull)mediaType;
- (AVAssetWriterInputPixelBufferAdaptor * _Nullable)getPixelBufferAdaptor:(AVRecorder * _Nonnull)recorder withWriterInput:(AVAssetWriterInput * _Nullable)withWriterInput SWIFT_WARN_UNUSED_RESULT;
- (AVAssetWriterInput * _Nullable)getWriterInput:(AVRecorder * _Nonnull)recorder mediaType:(AVMediaType _Nonnull)mediaType sourceFormatHint:(CMFormatDescriptionRef _Nullable)sourceFormatHint SWIFT_WARN_UNUSED_RESULT;
- (void)didFinishWriting:(AVRecorder * _Nonnull)recorder;
- (void)didStartRunning:(AVRecorder * _Nonnull)recorder;
- (void)didStopRunning:(AVRecorder * _Nonnull)recorder;
@end


SWIFT_CLASS("_TtC11FlipFlopSDK12FFConference")
@interface FFConference : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC11FlipFlopSDK7FFError")
@interface FFError : NSObject
@property (nonatomic, readonly) NSInteger code;
@property (nonatomic, readonly, copy) NSString * _Nonnull message;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC11FlipFlopSDK9FFMessage")
@interface FFMessage : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull type;
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
@property (nonatomic, readonly, copy) NSString * _Nonnull message;
@property (nonatomic, readonly) uint64_t createAt;
@property (nonatomic, readonly, copy) NSString * _Nonnull userID;
@property (nonatomic, copy) NSString * _Nonnull userName;
@property (nonatomic, copy) NSString * _Nullable avatarProfileURL;
@property (nonatomic, readonly, copy) NSString * _Nullable data;
@property (nonatomic, readonly, copy) NSString * _Nullable customType;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface FFMessage (SWIFT_EXTENSION(FlipFlopSDK))
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
@end

typedef SWIFT_ENUM(NSInteger, FFMessageType, open) {
  FFMessageTypeMsg = 0,
  FFMessageTypeJoin = 1,
  FFMessageTypeLeave = 2,
  FFMessageTypeAdmin = 3,
  FFMessageTypeStat = 4,
  FFMessageTypeWhisper = 5,
  FFMessageTypeCommand = 6,
  FFMessageTypeUnknown = 7,
};

@class FFVideoInfo;
@class FFStreamEvent;

SWIFT_CLASS("_TtC11FlipFlopSDK9FFMyLives")
@interface FFMyLives : NSObject
@property (nonatomic, readonly, strong) FFVideoInfo * _Nullable video;
@property (nonatomic, readonly, strong) FFStreamEvent * _Nullable stream_event;
@property (nonatomic, readonly) NSInteger available_live_count;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface FFMyLives (SWIFT_EXTENSION(FlipFlopSDK))
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
@end


SWIFT_CLASS("_TtC11FlipFlopSDK8FFPlayer")
@interface FFPlayer : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end





SWIFT_CLASS("_TtC11FlipFlopSDK6FFStat")
@interface FFStat : NSObject
@property (nonatomic) int64_t participantCount;
@property (nonatomic) int64_t totalUserCount;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface FFStat (SWIFT_EXTENSION(FlipFlopSDK))
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
@end


SWIFT_PROTOCOL("_TtP11FlipFlopSDK14FFStreamConfig_")
@protocol FFStreamConfig
@property (nonatomic) NSInteger width;
@property (nonatomic) NSInteger height;
@property (nonatomic) NSInteger videoBitrate;
@property (nonatomic) NSInteger keyFrameInterval;
@property (nonatomic) NSInteger fps;
@property (nonatomic) NSInteger sampleRate;
@property (nonatomic) NSInteger audioBitrate;
@property (nonatomic) AVCaptureDevicePosition cameraPos;
@end


SWIFT_CLASS("_TtC11FlipFlopSDK13FFStreamEvent")
@interface FFStreamEvent : NSObject
@property (nonatomic, readonly) int64_t id;
@property (nonatomic, readonly, copy) NSString * _Nonnull video_key;
@property (nonatomic, readonly, copy) NSString * _Nonnull stream_key;
@property (nonatomic, readonly, copy) NSString * _Nonnull state;
@property (nonatomic, readonly) uint64_t created_at;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC11FlipFlopSDK10FFStreamer")
@interface FFStreamer : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end





SWIFT_CLASS("_TtC11FlipFlopSDK16FFStreamerConfig")
@interface FFStreamerConfig : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
@end


SWIFT_CLASS("_TtC11FlipFlopSDK10FFVideoEnd")
@interface FFVideoEnd : NSObject
@property (nonatomic, readonly) uint64_t like_count;
@property (nonatomic, readonly) uint64_t total_message_count;
@property (nonatomic, readonly) uint64_t total_watcher_count;
@property (nonatomic, readonly) uint64_t duration;
@property (nonatomic, readonly) uint64_t created_at;
@property (nonatomic, readonly, copy) NSString * _Nonnull vod_url;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC11FlipFlopSDK11FFVideoInfo")
@interface FFVideoInfo : NSObject
/// video key
@property (nonatomic, readonly, copy) NSString * _Nonnull video_key;
/// video type. ‘BROADCASTED’ or ‘UPLOADED’
@property (nonatomic, readonly, copy) NSString * _Nonnull type;
/// owner ID
@property (nonatomic, readonly, copy) NSString * _Nonnull user_id;
/// owner name
@property (nonatomic, readonly, copy) NSString * _Nonnull user_name;
/// owner avatar url
@property (nonatomic, readonly, copy) NSString * _Nonnull user_avatar_url;
/// video title
@property (nonatomic, readonly, copy) NSString * _Nonnull title;
/// video description
@property (nonatomic, readonly, copy) NSString * _Nonnull content;
/// video state. ‘CREATED’ or ‘LIVE’ or ‘VOD’
@property (nonatomic, readonly, copy) NSString * _Nonnull state;
/// video duration, if the broadcast status is ‘VOD’, in miliseconds unit
@property (nonatomic, readonly) uint64_t duration;
/// Public scope, ‘PUBLIC’, ‘PRIVATE’
@property (nonatomic, readonly, copy) NSString * _Nonnull visibility;
/// mute audio, true | false
@property (nonatomic, readonly) BOOL muted;
/// lock video, true | false
@property (nonatomic, readonly) BOOL locked;
/// repository url
@property (nonatomic, readonly, copy) NSString * _Nonnull url;
/// video thumbnail url
@property (nonatomic, readonly, copy) NSString * _Nonnull thumbnail_url;
@property (nonatomic, readonly, copy) NSString * _Nullable stream_key;
@property (nonatomic, readonly, copy) NSString * _Nullable live_key;
/// custom data
@property (nonatomic, readonly, copy) NSString * _Nonnull data;
@property (nonatomic, readonly, copy) NSString * _Nonnull data2;
/// live video view count
@property (nonatomic, readonly) uint64_t watch_count;
/// live video heart count
@property (nonatomic, readonly) uint64_t heart_count;
/// VOD video view count
@property (nonatomic, readonly) uint64_t view_count;
/// VOD video like count
@property (nonatomic, readonly) uint64_t like_count;
/// liked by me
@property (nonatomic, readonly) BOOL liked_by_me;
/// created video time. Unix timestamp value in milliseconds.
@property (nonatomic, readonly) uint64_t created_at;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface FFVideoInfo (SWIFT_EXTENSION(FlipFlopSDK))
- (NSString * _Nonnull)getGoods SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC11FlipFlopSDK17FFVideoListLoader")
@interface FFVideoListLoader : NSObject
- (void)reset;
- (void)nextOnSuccess:(void (^ _Nullable)(NSArray<FFVideoInfo *> * _Nonnull))onSuccess onFailure:(void (^ _Nullable)(NSError * _Nonnull))onFailure;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC11FlipFlopSDK8FlipFlop")
@interface FlipFlop : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@class NSStream;

SWIFT_CLASS("_TtC11FlipFlopSDK19FoundationTransport")
@interface FoundationTransport : NSObject <NSStreamDelegate>
- (void)stream:(NSStream * _Nonnull)aStream handleEvent:(NSStreamEvent)eventCode;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class NSCoder;
@class EAGLContext;

/// A view that displays a video content of a NetStream object which uses OpenGL api. This class is deprecated. Please consider to use the MTHKView.
SWIFT_CLASS("_TtC11FlipFlopSDK8GLHKView")
@interface GLHKView : GLKView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)awakeFromNib;
- (nonnull instancetype)initWithFrame:(CGRect)frame context:(EAGLContext * _Nonnull)context SWIFT_UNAVAILABLE;
@end


@interface GLHKView (SWIFT_EXTENSION(FlipFlopSDK)) <GLKViewDelegate>
- (void)glkView:(GLKView * _Nonnull)view drawInRect:(CGRect)rect;
@end

@class AVCaptureVideoPreviewLayer;

SWIFT_CLASS("_TtC11FlipFlopSDK6HKView")
@interface HKView : UIView
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) Class _Nonnull layerClass;)
+ (Class _Nonnull)layerClass SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, strong) AVCaptureVideoPreviewLayer * _Nonnull layer;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)awakeFromNib;
@end



SWIFT_CLASS("_TtC11FlipFlopSDK9HLSPlayer")
@interface HLSPlayer : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface HLSPlayer (SWIFT_EXTENSION(FlipFlopSDK)) <AVPictureInPictureControllerDelegate>
@end


@interface HLSPlayer (SWIFT_EXTENSION(FlipFlopSDK))
- (void)observeValueForKeyPath:(NSString * _Nullable)keyPath ofObject:(id _Nullable)object change:(NSDictionary<NSKeyValueChangeKey, id> * _Nullable)change context:(void * _Nullable)context;
@end

@protocol MTLDevice;

/// A view that displays a video content of a NetStream object which uses Metal api.
SWIFT_CLASS("_TtC11FlipFlopSDK8MTHKView")
@interface MTHKView : MTKView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)awakeFromNib;
- (nonnull instancetype)initWithFrame:(CGRect)frameRect device:(id <MTLDevice> _Nullable)device SWIFT_UNAVAILABLE;
@end


@interface MTHKView (SWIFT_EXTENSION(FlipFlopSDK)) <MTKViewDelegate>
- (void)mtkView:(MTKView * _Nonnull)view drawableSizeWillChange:(CGSize)size;
- (void)drawInMTKView:(MTKView * _Nonnull)view;
@end

@class NSURLSession;
@class NSURLSessionWebSocketTask;
@class NSData;

SWIFT_CLASS("_TtC11FlipFlopSDK12NativeEngine") SWIFT_AVAILABILITY(tvos,introduced=13.0) SWIFT_AVAILABILITY(watchos,introduced=6.0) SWIFT_AVAILABILITY(ios,introduced=13.0) SWIFT_AVAILABILITY(macos,introduced=10.15)
@interface NativeEngine : NSObject <NSURLSessionDataDelegate, NSURLSessionWebSocketDelegate>
- (void)URLSession:(NSURLSession * _Nonnull)session webSocketTask:(NSURLSessionWebSocketTask * _Nonnull)webSocketTask didOpenWithProtocol:(NSString * _Nullable)protocol;
- (void)URLSession:(NSURLSession * _Nonnull)session webSocketTask:(NSURLSessionWebSocketTask * _Nonnull)webSocketTask didCloseWithCode:(NSURLSessionWebSocketCloseCode)closeCode reason:(NSData * _Nullable)reason;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// The NetSocket class creates a two-way connection  between a client and a server. This class is wrapper for a InputStream and an OutputStream.
SWIFT_CLASS("_TtC11FlipFlopSDK9NetSocket")
@interface NetSocket : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// The NetClient class creates a two-way connection  between a NetService.
SWIFT_CLASS("_TtC11FlipFlopSDK9NetClient")
@interface NetClient : NetSocket
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC11FlipFlopSDK10NetService")
@interface NetService : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class NSNetService;
@class NSInputStream;
@class NSOutputStream;

@interface NetService (SWIFT_EXTENSION(FlipFlopSDK)) <NSNetServiceDelegate>
- (void)netService:(NSNetService * _Nonnull)sender didAcceptConnectionWithInputStream:(NSInputStream * _Nonnull)inputStream outputStream:(NSOutputStream * _Nonnull)outputStream;
@end






@interface NetSocket (SWIFT_EXTENSION(FlipFlopSDK)) <NSStreamDelegate>
- (void)stream:(NSStream * _Nonnull)aStream handleEvent:(NSStreamEvent)eventCode;
@end


/// The <code>NetStream</code> class is the foundation of a RTMPStream, HTTPStream.
SWIFT_CLASS("_TtC11FlipFlopSDK9NetStream")
@interface NetStream : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


typedef SWIFT_ENUM(NSInteger, Preset, open) {
  PresetHd1920x1080 = 0,
  PresetHd1280x720 = 1,
  PresetVga640x480 = 2,
  PresetCif352x288 = 3,
};


/// flash.net.NetStream for Swift
SWIFT_CLASS("_TtC11FlipFlopSDK10RTMPStream")
@interface RTMPStream : NetStream
/// The number of frames per second being displayed.
@property (nonatomic, readonly) uint16_t currentFPS;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end





@class CADisplayLink;

SWIFT_CLASS("_TtC11FlipFlopSDK20ScreenCaptureSession")
@interface ScreenCaptureSession : NSObject
- (void)onScreen:(CADisplayLink * _Nonnull)displayLink;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@class UIImage;
@class NSURL;

SWIFT_PROTOCOL("_TtP11FlipFlopSDK17SwiftyGifDelegate_")
@protocol SwiftyGifDelegate
@optional
- (void)gifDidStartWithSender:(UIImage * _Nonnull)sender;
- (void)gifDidLoopWithSender:(UIImage * _Nonnull)sender;
- (void)gifDidStopWithSender:(UIImage * _Nonnull)sender;
- (void)gifURLDidFinishWithSender:(UIImage * _Nonnull)sender;
- (void)gifURLDidFailWithSender:(UIImage * _Nonnull)sender url:(NSURL * _Nonnull)url error:(NSError * _Nullable)error;
@end


/// It allows synchronous tasks, has a pause and resume states, can be easily added to a queue and can be created with a block.
SWIFT_CLASS("_TtC11FlipFlopSDK20SynchronousOperation")
@interface SynchronousOperation : ConcurrentOperation
/// Set the <code>Operation</code> as synchronous.
@property (nonatomic, readonly, getter=isAsynchronous) BOOL asynchronous;
/// Advises the <code>Operation</code> object that it should stop executing its task.
- (void)cancel;
@end









SWIFT_CLASS("_TtC11FlipFlopSDK11VideoEffect")
@interface VideoEffect : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11FlipFlopSDK16WebRTCConference")
@interface WebRTCConference : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC11FlipFlopSDK12WebRTCPlayer")
@interface WebRTCPlayer : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC11FlipFlopSDK14WebRTCStreamer")
@interface WebRTCStreamer : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
