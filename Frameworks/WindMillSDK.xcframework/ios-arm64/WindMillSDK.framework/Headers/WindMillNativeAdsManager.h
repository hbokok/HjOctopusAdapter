//
//  WindMillNativeAdsManager.h
//  WindSDK
//
//  Created by Codi on 2021/7/14.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WindMillAdInfo;
@class WindMillAdRequest;
@class WindMillNativeAd;
@class WindMillNativeAdsManager;

NS_ASSUME_NONNULL_BEGIN

@protocol WindMillNativeAdsManagerDelegate <NSObject>

@optional

/// 广告加载成功回调
/// - Parameter adsManager: WindMillNativeAdsManager 实例对象
- (void)nativeAdsManagerSuccessToLoad:(WindMillNativeAdsManager *)adsManager;

/// 广告加载出错
/// - Parameters:
///   - adsManager: WindMillNativeAdsManager 实例对象
///   - error: 具体错误信息
- (void)nativeAdsManager:(WindMillNativeAdsManager *)adsManager didFailWithError:(NSError *)error;

@end


@interface WindMillNativeAdsManager : NSObject

/// 广告代理对象
@property (nonatomic, weak) id<WindMillNativeAdsManagerDelegate> delegate;

/// 广告位ID
@property (nonatomic, strong, readonly) NSString *placementId;


/// 自定义广告扩展参数
@property (nonatomic, strong, nullable) NSDictionary *extra;

/*
 * 必传参数，为空时聚合会默认设置为width=screen.bouces.size.width; height=0
 * 穿山甲 height: 0自适应
 * 腾讯：height会在render success后自动更新到合适的高度
 * 美数：如果媒体指定size，width和height不能小于屏宽的30% ； height: 0自适应
 */
@property (nonatomic, assign, readwrite) CGSize adSize;

/// 构造器
/// - Parameter request: 广告请求模型，可以设置广告位ID等参数
- (instancetype)initWithRequest:(WindMillAdRequest *)request;

/// 加载广告
/// @param count 加载广告的个数，推荐一次性不要超过3条，默认1条
- (void)loadAdDataWithCount:(NSInteger)count;

/// 获取当前已缓存的广告数据
/// @warning 需要在广告加载成功后调用，否则为nil
- (NSArray<WindMillNativeAd *> * _Nullable)getAllNativeAds;

/// 填充后可调用, 返回广告缓存池内所有信息
- (NSArray<WindMillAdInfo *> *)getCacheAdInfoList;

@end

NS_ASSUME_NONNULL_END

