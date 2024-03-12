//
//  WindMillNativeAdShakeView.h
//  WindMillSDK
//
//  Created by Codi on 2023/7/17.
//

#import <UIKit/UIKit.h>

@class WindMillNativeAdShakeView;

@protocol WindMillNativeAdShakeViewDelegate <NSObject>

/// 摇一摇销毁(消失)回调
- (void)nativeShakeViewDismiss:(WindMillNativeAdShakeView *)shakeView;

@end

@interface WindMillNativeAdShakeView : UIView

/// 设置摇一摇组件代理
/// 因为摇一摇组件为懒加载，需要在WindMillNativeAdView调用refreshData:方法之后设置
@property (nonatomic, weak) id<WindMillNativeAdShakeViewDelegate> delegate;

/// 开启摇动检测
- (void)startShake;

/// 停止摇动检测
- (void)stopShake;

/// 销毁摇一摇组件
- (void)destoryShakeView;

@end
