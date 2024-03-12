//
//  WindMillSkipView.h
//  WindMillSDK
//
//  Created by happyelements on 2023/8/28.
//

#import <UIKit/UIKit.h>
#import "WindMillEnum.h"

@class WindMillSkipView;

@protocol ToBidSkipViewDelegate <NSObject>
/// 倒计时
- (void)skipView:(WindMillSkipView *)skipView
           countdown:(NSUInteger)duration;

/// 倒计时结束
- (void)skipView:(WindMillSkipView *)skipView
   countdownZero:(NSDictionary *)params;

/// 点击跳过
- (void)skipView:(WindMillSkipView *)skipView
   clicked:(NSUInteger)duration;

/// 点击关闭
- (void)skipView:(WindMillSkipView *)skipView
   closed:(NSDictionary *)params;

@end

@interface WindMillSkipView : UIView

@property (nonatomic, weak) id<ToBidSkipViewDelegate> delegate;

- (instancetype)initWithTimeInterval:(NSUInteger)duration;

- (void)changeCountdownType:(WindMillCountdownType)type;

- (void)setCountdownWidthType:(WindMillCountdownWidthType)type;

/// 启用定时器
- (void)fire;

/// 暂停定时器
/// @note 调用本方法之后，可以用 resume 恢复定时器
- (void)pause;

/// 恢复定时器
/// @note 调用本方法之后，可以用 fire 重启定时器
- (void)resume;

- (void)destroy;

@end
