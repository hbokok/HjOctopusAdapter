//
//  WindNativeView.h
//  WindSDK
//
//  Created by Codi on 2021/7/27.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillEnum.h>

@class WindMillAdInfo;
@class WindMillNativeAdView;
@class WindMillNativeAd;
@class WindMillDislikeWords;
@class WindMillNativeAdShakeView;

@protocol WindMillNativeAdViewDelegate <NSObject>

@optional
/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 * （只针对模版渲染）
 */
- (void)nativeExpressAdViewRenderSuccess:(WindMillNativeAdView *)nativeExpressAdView;

/**
 * 原生模板广告渲染失败
 * （只针对模版渲染）
 */
- (void)nativeExpressAdViewRenderFail:(WindMillNativeAdView *)nativeExpressAdView error:(NSError *)error;

/**
 广告曝光回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdViewWillExpose:(WindMillNativeAdView *)nativeAdView;

/**
 广告点击回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdViewDidClick:(WindMillNativeAdView *)nativeAdView;

/**
 广告详情页关闭回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdDetailViewClosed:(WindMillNativeAdView *)nativeAdView;

/**
 广告详情页面即将展示回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdDetailViewWillPresentScreen:(WindMillNativeAdView *)nativeAdView;

/**
 视频广告播放状态更改回调

 @param nativeAdView WindMillNativeAdView 实例
 @param status 视频广告播放状态
 @param userInfo 视频广告信息
 */
- (void)nativeAdView:(WindMillNativeAdView *)nativeAdView playerStatusChanged:(WindMillMediaPlayerStatus)status userInfo:(NSDictionary *)userInfo;

/**
 点击dislike回调
 开发者需要在这个回调中移除视图，否则，会出现用户点击叉无效的情况
 
 @param filterWords : 选择不喜欢的原因
 */
- (void)nativeAdView:(WindMillNativeAdView *)nativeAdView dislikeWithReason:(NSArray<WindMillDislikeWords *> *)filterWords;
@end


@interface WindMillNativeAdView : UIView

/// 广告数据对象
@property (nonatomic, strong, readonly) WindMillNativeAd *nativeAd;

/// 当前播放广告的广告信息
@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;

/// 广告代理对象
@property (nonatomic, weak) id<WindMillNativeAdViewDelegate> delegate;

/// 广告点击弹出新页面所依赖的ViewController
@property (nonatomic, weak) UIViewController *viewController;

/// 视频组件
@property (nonatomic, strong, readonly) UIView *mediaView;

/// 广告平台logo组件
@property (nonatomic, strong, readonly) UIView *logoView;

/// dislike组件
@property (nonatomic, strong, readonly) UIButton *dislikeButton;

/// 单图广告对应的图片组件
@property (nonatomic, strong, readonly) UIImageView *mainImageView;

/// 摇一摇组件 [Optional] [仅支持百度]
/// 因为是懒加载方式，需要在refreshData之后确认渲染渠道后才会创建对应的摇一摇组件
/// 组件高度需要大于80pt。摇一摇文案内容为：摇动手机 了解更多 如果组件宽度不够，则会自动将宽度适配文字长度。
@property (nonatomic, strong, readonly) WindMillNativeAdShakeView *shakeView;

/// 3图广告时对应的ImageView组件list
@property (nonatomic, strong, readonly) NSArray<UIImageView *> *imageViewList;

/// 刷新广告数据
/// @param nativeAd 广告模型数据
/// @warning 每次获取物料信息后需要刷新调用refreshData:方法
- (void)refreshData:(WindMillNativeAd *)nativeAd;

/**
 刷新media视图frame，百度渠道
 */
- (void)mediaViewResize;

/**
 设置media视图frame，需要在refreshData之后调用，美数渠道
 */
- (void)setMediaViewSize:(CGSize)size;

/// 绑定点击的View
/// @param clickableViews 需要注册点击View的集合
- (void)setClickableViews:(NSArray<UIView *> *)clickableViews;

/// 设置占位图
/// @param placeholderImage 占位图UIImage *
- (void)setPlaceholderImage:(UIImage *)placeholderImage;

/// 注销数据对象
/// @warning 在 tableView、collectionView 等场景需要复用 WindNativeAdView 时，需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，将广告对象与 WindNativeAdView 解绑
- (void)unregisterDataObject;

@end
