//
//  WindMillAds.h
//  WindMillSDK
//
//  Created by Codi on 2021/10/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindMillSDK/AWMDeviceProtocol.h>

@class AWMSDKConfigure;

typedef NS_ENUM (NSInteger, WindMillCCPAStatus) {
    WindMillCCPAUnknown = 0,
    WindMillCCPAAccepted,
    WindMillCCPADenied,
};

typedef NS_ENUM (NSInteger, WindMillConsentStatus) {
    WindMillConsentUnknown = 0,
    WindMillConsentAccepted,
    WindMillConsentDenied,
};

typedef NS_ENUM (NSInteger, WindMillAgeRestrictedStatus) {
    WindMillAgeRestrictedStatusUnknow = 0,
    WindMillAgeRestrictedStatusYES, //年龄受限制
    WindMillAgeRestrictedStatusNO,  //成年人，年龄不受限制
};

typedef enum : NSUInteger {
    WindMillAdult = 0,
    WindMillChildren = 1,
} WindMillAdultState;

typedef enum : NSUInteger {
    WindMillPersonalizedAdvertisingOn = 0,
    WindMillPersonalizedAdvertisingOff = 1,
} WindMillPersonalizedAdvertisingState;



@interface WindMillAds : NSObject

+ (NSString *)sdkVersion;

// 获取平台唯一ID，需要在一次广告请求后调研，否则返回为nil
+ (NSString *)getUid;

// 获取初始化状态
+ (BOOL)hasInitSuccessed;

/// 设置广告位预置策略所在的Bundle路径
+ (void)setPresetPlacementConfigPathBundle:(NSBundle *)bundle;

// Initialize WindMill Ads SDK
+ (void)setupSDKWithAppId:(NSString *)appId;

// Initialize WindMill Ads SDK
// configure: The configuration information is initialized in advance
+ (void)setupSDKWithAppId:(NSString *)appId
            sdkConfigures:(NSArray<AWMSDKConfigure *> *)configures;

// 扩展字段
// 设置时机：初始化时
// 目前支持美数渠道 支持唤起微信小程序的能力 的传值 key用WindMillWXAppId，value用WindMillWXUniversalLink
+ (void)setExt:(NSDictionary<NSString *, NSString *> *)ext;

/// 场景曝光，sceneId由平台生成
+ (void)sceneExposeWithSceneId:(NSString *)sceneId sceneName:(NSString *)sceneName;

/// 设置流量分组自定义规则【应用级设置】
/// (在线文档：https://doc.sigmob.com/#/ToBid使用指南/高级功能说明/流量分组/)
+ (void)initCustomGroup:(NSDictionary<NSString *, NSString *> *)group;

/// 设置流量分组自定义规则【聚合广告位级设置】
/// (在线文档：https://doc.sigmob.com/#/ToBid使用指南/高级功能说明/流量分组/)
+ (void)initCustomGroup:(NSDictionary<NSString *, NSString *> *)group forPlacementId:(NSString *)placementId;

/// 设置自定义信息
/// @param delegate 自定义代理对象
/// @warning  初始化前调用，否则有可能不生效
+ (void)setCustomDeviceController:(id<AWMDeviceProtocol>)delegate;

/**
 *   DeBug开关显示
 *
 *  @param enable true 开启debug，false 关闭debug
 */
+ (void)setDebugEnable:(BOOL)enable;

/**
 *  @param placementId  聚合广告位ID，不可为空
 *  @param channelIds  过滤掉某个广告位下的对应广告平台的广告源请求，示例@[@"1",@"12",@"23"]]
 */
+ (void)setFilterNetworkChannelIdList:(NSArray<NSString *> *)channelIds forPlacementId:(NSString *)placementId;

/**
 *  获取渠道ID列表
 */
+ (NSArray<NSString *> *)getFilterNetworkChannelIdListWithPlacement:(NSString *)placementId;
/*********  CCPA加州消费者隐私保护法案  *********/
/// Custom set the CCPA of the user,CCPA is the short of General Data Protection Regulation,the interface only works in USA.
+ (void)setCCPAStatus:(WindMillCCPAStatus)status;
+ (WindMillCCPAStatus)getCCPAStatus;

/*********  GDPR  *********/
///Custom set the GDPR of the user,GDPR is the short of General Data Protection Regulation,the interface only works in The European.
+ (void)setUserGDPRConsentStatus:(WindMillConsentStatus)status;
+ (WindMillConsentStatus)getUserGDPRConsentStatus;

/*********  COPPA儿童在线隐私权保护法  *********/
///Set the COPPA of the user, COPPA is the short of Children's Online Privacy Protection Rule, the interface only works in the United States.
+ (void)setIsAgeRestrictedUser:(WindMillAgeRestrictedStatus)status;
+ (WindMillAgeRestrictedStatus)getAgeRestrictedStatus;

/*********  设置是否是成年人  *********/
/// WindAdult: 成年人， WindChildren: 未成年人 default=WindAdult
+ (void)setAdult:(WindMillAdultState)state;
+ (WindMillAdultState)getAdultState;

/********* 个性化推荐设置  *********/
/// WindPersonalizedAdvertisingOn: 开启个性化推荐
/// WindPersonalizedAdvertisingOff: 关闭个性化推荐,
/// default=WindPersonalizedAdvertisingOn
+ (void)setPersonalizedAdvertising:(WindMillPersonalizedAdvertisingState)state;
+ (WindMillPersonalizedAdvertisingState)getPersonalizedAdvertisingState;

+ (NSUInteger)getUserAge;
+ (void)setUserAge:(NSUInteger)age;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;


@end
