#import "HjOctopusRewardedVideoAd.h"
#import <WindMillSDK/WindMillSDK.h>
#import <WindFoundation/WindFoundation.h>
#import <OctAdSDK/OctAdRewardVideo.h>

@interface HjOctopusRewardedVideoAd ()<OctAdRewardVideoDelegate>
@property (nonatomic, weak) id<AWMCustomRewardedVideoAdapterBridge> bridge;
@property (nonatomic, weak) id<AWMCustomRewardedVideoAdapter> adapter;
@property (nonatomic, strong) OctAdRewardVideo *rewardedVideoAd;
@property (nonatomic, assign) BOOL isReady;
@end

@implementation HjOctopusRewardedVideoAd
- (instancetype)initWithBridge:(id<AWMCustomAdapterBridge>)bridge adapter:(id<AWMCustomAdapter>)adapter {
    self = [super init];
    if (self) {
        _bridge = (id<AWMCustomRewardedVideoAdapterBridge>)bridge;
        _adapter = (id<AWMCustomRewardedVideoAdapter>)adapter;
    }
    return self;
}
- (BOOL)mediatedAdStatus {
    return self.isReady;
}
- (void)loadAdWithPlacementId:(NSString *)placementId parameter:(AWMParameter *)parameter {
    self.rewardedVideoAd = [[OctAdRewardVideo alloc] initWithSlotId:placementId];
    self.rewardedVideoAd.delegate = self;
    [self.rewardedVideoAd loadAd];
}
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController parameter:(AWMParameter *)parameter {
    [self.rewardedVideoAd showAdsInViewController:viewController];
    return YES;
}
- (void)didReceiveBidResult:(AWMMediaBidResult *)result {
}
- (void)dealloc {
    WindmillLogDebug(@"Octopus", @"%s", __func__);
}
#pragma mark - OctAdRewardVideoDelegate
// 加载成功
- (void)octad_rewardVideoSuccessToLoad:(OctAdRewardVideo *)rewardVideo {
    NSLog(@"激励视频广告加载成功");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    NSString *price = [NSString stringWithFormat:@"%d", [self.rewardedVideoAd getPrice]];
    [self.bridge rewardedVideoAd:self.adapter didAdServerResponseWithExt:@{
        AWMMediaAdLoadingExtECPM: price
    }];
    self.isReady = YES;
    [self.bridge rewardedVideoAdDidLoad:self.adapter];
}

// 加载失败
- (void)octad_rewardVideo:(OctAdRewardVideo *)rewardVideo didFailWithError:(NSError * _Nullable)error {
    NSLog(@"激励视频广告加载失败：%@", error);
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    self.isReady = NO;
    [self.bridge rewardedVideoAd:self.adapter didLoadFailWithError:error ext:nil];
}

// 广告曝光
- (void)octad_rewardVideoDidVisible:(OctAdRewardVideo *)rewardVideo {
    NSLog(@"激励视频广告曝光");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    self.isReady = NO;
    [self.bridge rewardedVideoAdDidVisible:self.adapter];
}

// 广告点击
- (void)octad_rewardVideoAdViewDidClick:(OctAdRewardVideo *)rewardVideo {
    NSLog(@"激励视频广告点击");
    WindmillLogDebug(@"CSJ", @"%@", NSStringFromSelector(_cmd));
    [self.bridge rewardedVideoAdDidClick:self.adapter];
}

// 广告关闭
- (void)octad_rewardVideoDidClose:(OctAdRewardVideo *)rewardVideo {
    NSLog(@"激励视频广告关闭");
    WindmillLogDebug(@"CSJ", @"%@", NSStringFromSelector(_cmd));
    [self.bridge rewardedVideoAdDidClose:self.adapter];
}

// 广告播放完成
- (void)octad_rewardVideoDidFinished:(OctAdRewardVideo *)rewardVideo {
    NSLog(@"激励视频广告播放完成");
    WindmillLogDebug(@"CSJ", @"%@", NSStringFromSelector(_cmd));
    [self.bridge rewardedVideoAd:self.adapter didPlayFinishWithError:nil];
}

// 广告发放奖励
- (void)octad_rewardVideoDidReward:(OctAdRewardVideo *)rewardVideo {
    NSLog(@"激励视频广告发放奖励");
    WindmillLogDebug(@"CSJ", @"%@", NSStringFromSelector(_cmd));
    WindMillRewardInfo *info = [[WindMillRewardInfo alloc] init];
    info.isCompeltedView = YES;
    [self.bridge rewardedVideoAd:self.adapter didRewardSuccessWithInfo:info];
}
@end
