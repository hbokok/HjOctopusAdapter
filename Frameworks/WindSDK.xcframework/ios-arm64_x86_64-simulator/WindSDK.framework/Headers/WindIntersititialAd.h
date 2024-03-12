//
//  WindIntersititialAd.h
//  WindSDK
//
//  Created by Codi on 2021/11/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WindBiddingProtocol.h"

@class WindAdRequest;
@class WindIntersititialAd;

NS_ASSUME_NONNULL_BEGIN

@protocol WindIntersititialAdDelegate<NSObject>

@optional

/// 广告加载成功回调
/// - Parameter rewardVideoAd: WindIntersititialAd 实例对象
- (void)intersititialAdDidLoad:(WindIntersititialAd *)intersititialAd;

/// 广告加载出错
/// - Parameters:
///   - intersititialAd: WindIntersititialAd 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidLoad:(WindIntersititialAd *)intersititialAd didFailWithError:(NSError *)error;

/// 广告将要曝光回调
/// - Parameter rewardVideoAd: WindIntersititialAd 实例对象
- (void)intersititialAdWillVisible:(WindIntersititialAd *)intersititialAd;

/// 广告曝光回调
/// - Parameter rewardVideoAd: WindIntersititialAd 实例对象
- (void)intersititialAdDidVisible:(WindIntersititialAd *)intersititialAd;

/// 广告点击回调
/// - Parameter rewardVideoAd: WindIntersititialAd 实例对象
- (void)intersititialAdDidClick:(WindIntersititialAd *)intersititialAd;

/// 广告跳过回调
/// - Parameter rewardVideoAd: WindIntersititialAd 实例对象
- (void)intersititialAdDidClickSkip:(WindIntersititialAd *)intersititialAd;

/// 广告关闭回调
/// - Parameter rewardVideoAd: WindIntersititialAd 实例对象
- (void)intersititialAdDidClose:(WindIntersititialAd *)intersititialAd;

/// 广告视频播放完成或播放出错时回调
/// - Parameters:
///   - intersititialAd: WindIntersititialAd 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidPlayFinish:(WindIntersititialAd *)intersititialAd didFailWithError:(NSError * _Nullable)error;

/// 广告数据返回回调
/// - Parameters:
///   - rewardVideoAd: WindIntersititialAd 实例对象
///   - isFillAd: ture: 填充， false: 无广告数据
- (void)intersititialAdServerResponse:(WindIntersititialAd *)intersititialAd isFillAd:(BOOL)isFillAd;

@end

@interface WindIntersititialAd : NSObject<WindBiddingProtocol>

/// 广告代理对象
@property (nonatomic, weak) id<WindIntersititialAdDelegate> delegate;

/// 广告位ID
@property (nonatomic, strong, readonly) NSString *placementId;

/// 检查广告是否有效
@property (nonatomic, getter=isAdReady, readonly) BOOL ready;

/// 构造器 - 全屏插屏
/// - Parameter request: 广告请求模型，可以设置广告位ID等参数
- (instancetype)initWithRequest:(WindAdRequest *)request;

/// 加载广告
- (void)loadAdData;

/// 加载Bidding广告
/// @param bidToken bidding广告的唯一标识
- (void)loadAdDataWithBidToken:(NSString *)bidToken;

/// 播放广告
/// @param rootViewController 播放广告所需要的ViewController
/// @param extras 扩展参数，用于设置播放时的代码位场景
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> * _Nullable)extras;

@end

NS_ASSUME_NONNULL_END

