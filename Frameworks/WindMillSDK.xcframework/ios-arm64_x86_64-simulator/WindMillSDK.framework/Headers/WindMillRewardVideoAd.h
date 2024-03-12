//
//  WindMillRewardVideoAd.h
//  WindSDK
//
//  Created by Codi on 2021/4/19.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WindMillAdInfo;
@class WindMillAdRequest;
@class WindMillRewardInfo;
@class WindMillRewardVideoAd;

NS_ASSUME_NONNULL_BEGIN

@protocol WindMillRewardVideoAdDelegate<NSObject>

@required

/// 广告获得激励时回调
/// - Parameters:
///   - rewardVideoAd: WindMillRewardVideoAd 实例对象
///   - reward: 激励信息
- (void)rewardVideoAd:(WindMillRewardVideoAd *)rewardVideoAd reward:(WindMillRewardInfo *)reward;

@optional

/// 广告加载成功
/// - Parameter rewardVideoAd: WindMillRewardVideoAd 实例对象
- (void)rewardVideoAdDidLoad:(WindMillRewardVideoAd *)rewardVideoAd;

/// 广告加载失败
/// - Parameters:
///   - rewardVideoAd: WindMillRewardVideoAd 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidLoad:(WindMillRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error;

/// 广告曝光回调
/// - Parameter rewardVideoAd: WindMillRewardVideoAd 实例对象
- (void)rewardVideoAdDidVisible:(WindMillRewardVideoAd *)rewardVideoAd;

/// 广告播放失败回调
/// - Parameters:
///   - rewardVideoAd: WindMillRewardVideoAd 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidShowFailed:(WindMillRewardVideoAd *)rewardVideoAd error:(NSError *)error;

/// 广告点击回调
/// - Parameter rewardVideoAd: WindMillRewardVideoAd 实例对象
- (void)rewardVideoAdDidClick:(WindMillRewardVideoAd *)rewardVideoAd;

/// 广告跳过回调
/// - Parameter rewardVideoAd: WindMillRewardVideoAd 实例对象
- (void)rewardVideoAdDidClickSkip:(WindMillRewardVideoAd *)rewardVideoAd;

/// 广告闭关回调
/// - Parameter rewardVideoAd: WindMillRewardVideoAd 实例对象
- (void)rewardVideoAdDidClose:(WindMillRewardVideoAd *)rewardVideoAd;

/// 广告视频播放完成或者视频播放出错
/// - Parameters:
///   - rewardVideoAd: WindMillRewardVideoAd 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidPlayFinish:(WindMillRewardVideoAd *)rewardVideoAd didFailWithError:(NSError * _Nullable)error;

@end

@interface WindMillRewardVideoAd : NSObject

/// 广告代理对象
@property (nonatomic, weak) id<WindMillRewardVideoAdDelegate> delegate;

/// 广告位ID
@property (nonatomic, strong, readonly) NSString *placementId;

/// 广告是否有效
@property (nonatomic, getter=isAdReady, readonly) BOOL ready;

/// 当前播放广告的相关信息
@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;

/// 构造器
/// - Parameter request: 广告请求模型，可以设置广告位ID等参数
- (instancetype)initWithRequest:(WindMillAdRequest *)request;

/// 可重复传入自定义参数
- (void)resetRequestOptions:(NSDictionary<NSString *, NSString *> *)options;

/// 加载广告
- (void)loadAdData;

/// 填充后可调用, 返回广告缓存池内所有信息
- (NSArray<WindMillAdInfo *> *)getCacheAdInfoList;

/// 播放广告
/// @param rootViewController 播放广告所需要的ViewController
/// @param extras 扩展参数，用于设置播放时的代码位场景
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> * _Nullable)extras;

@end

NS_ASSUME_NONNULL_END
