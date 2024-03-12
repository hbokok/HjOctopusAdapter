//
//  WindMillBannerView.h
//  WindMillSDK
//
//  Created by Codi on 2022/3/18.
//

#import <UIKit/UIKit.h>

@class WindMillAdRequest;
@class WindMillBannerView;
@class WindMillAdInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol WindMillBannerViewDelegate <NSObject>

@optional

/// 广告自动刷新成功回调
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewDidAutoRefresh:(WindMillBannerView *)bannerAdView;

/// 广告自动刷新失败回调
/// - Parameters:
///   - bannerAdView: WindMillBannerView 实例对象
///   - error: 具体错误信息
- (void)bannerView:(WindMillBannerView *)bannerAdView failedToAutoRefreshWithError:(NSError *)error;

/// 广告加载成功回调
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewLoadSuccess:(WindMillBannerView *)bannerAdView;

/// 广告加载失败回调
/// - Parameters:
///   - bannerAdView: WindMillBannerView 实例对象
///   - error: 具体错误信息
- (void)bannerAdViewFailedToLoad:(WindMillBannerView *)bannerAdView
                           error:(NSError *)error;

/// 广告曝光回调
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewWillExpose:(WindMillBannerView *)bannerAdView;

/// 广告点击回调
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewDidClicked:(WindMillBannerView *)bannerAdView;

/// 当用户由于点击要离开您的应用程序时触发该回调,您的应用程序将移至后台
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewWillLeaveApplication:(WindMillBannerView *)bannerAdView;

/// 将打开全屏视图。在打开storekit或在应用程序中打开网页时触发
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewWillOpenFullScreen:(WindMillBannerView *)bannerAdView;

/// 将关闭全屏视图。关闭storekit或关闭应用程序中的网页时发送
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewCloseFullScreen:(WindMillBannerView *)bannerAdView;

/// 广告视图被移除
/// - Parameter bannerAdView: WindMillBannerView 实例对象
- (void)bannerAdViewDidRemoved:(WindMillBannerView *)bannerAdView;
@end

@interface WindMillBannerView : UIView

/// 广告代理对象
@property (nonatomic, weak) id<WindMillBannerViewDelegate> delegate;

/// 视图控制器
@property (nonatomic, weak) UIViewController *viewController;

/// Banner展现和轮播时的动画效果开关，默认打开 [可选]
@property (nonatomic) BOOL animated;

/// 广告位ID
@property (nonatomic, copy, readonly) NSString *placementId;

/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告过期
 */
@property (nonatomic, readonly) BOOL isAdValid;

/// 在广告展示后，描述当前播放广告源信息
@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;

/// 广告实际的大小
@property (nonatomic, assign, readonly) CGSize adSize;

/// 构造方法
/// - Parameter request: 广告请求对象
- (instancetype)initWithRequest:(WindMillAdRequest *)request;

/// 构造方法
/// - Parameters:
///   - request: 广告请求对象
///   - expectSize: 期望的广告视图大小
- (instancetype)initWithRequest:(WindMillAdRequest *)request
                     expectSize:(CGSize)expectSize;

/// 加载广告
- (void)loadAdData;

/// 填充后可调用, 返回广告缓存池内所有信息
- (NSArray<WindMillAdInfo *> *)getCacheAdInfoList;

@end

NS_ASSUME_NONNULL_END
