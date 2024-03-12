//
//  ToBidChannelInfo.h
//  WindMillSDK
//
//  Created by Codi on 2023/8/15.
//

typedef enum : NSUInteger {
    ToBidChannleAdTypeExpressRewardAd = 10,
    ToBidChannleAdTypeRewardAd,
    ToBidChannleAdTypeFullVideoAd,
    ToBidChannleAdTypeIntersititialAd,
    ToBidChannleAdTypeSplashAd,
    ToBidChannleAdTypeBannerAd,
} ToBidChannleAdType;

@protocol ToBidChannelInfo <NSObject>

+ (NSDictionary *)getAdInfoWithTarget:(id)target forType:(ToBidChannleAdType)type;

@end
