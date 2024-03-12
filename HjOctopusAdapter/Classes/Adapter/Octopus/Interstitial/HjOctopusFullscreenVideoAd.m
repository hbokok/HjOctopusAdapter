#import "HjOctopusFullscreenVideoAd.h"
#import <OctAdSDK/OctAdIntersitital.h>
#import <WindMillSDK/WindMillSDK.h>
#import <WindFoundation/WindFoundation.h>

@interface HjOctopusFullscreenVideoAd ()<OctAdIntersititalDelegate>
@property (nonatomic, weak) id<AWMCustomInterstitialAdapterBridge> bridge;
@property (nonatomic, weak) id<AWMCustomInterstitialAdapter> adapter;
@property (nonatomic, strong) OctAdIntersitital *interstitialAd;
@property (nonatomic, assign) BOOL isReady;
@end

@implementation HjOctopusFullscreenVideoAd
- (instancetype)initWithBridge:(id<AWMCustomAdapterBridge>)bridge adapter:(id<AWMCustomAdapter>)adapter {
    self = [super init];
    if (self) {
        _bridge = (id<AWMCustomInterstitialAdapterBridge>)bridge;
        _adapter = (id<AWMCustomInterstitialAdapter>)adapter;
    }
    return self;
}
- (BOOL)mediatedAdStatus {
    return self.isReady;
}
- (void)loadAdWithPlacementId:(NSString *)placementId
                    parameter:(AWMParameter *)parameter {
    self.interstitialAd = [[OctAdIntersitital alloc] initWithSlotId:placementId];
    self.interstitialAd.delegate = self;
    [self.interstitialAd loadAd];
}
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController parameter:(AWMParameter *)parameter {
    [self.interstitialAd showAdsInViewController:viewController];
    return YES;
}
- (void)didReceiveBidResult:(AWMMediaBidResult *)result {
}
#pragma mark - OctAdIntersititalDelegate
- (void)octad_intersititalSuccessToLoad:(OctAdIntersitital *)intersititalAd {
    NSLog(@"插屏广告加载成功");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    NSString *price = [NSString stringWithFormat:@"%d", [self.interstitialAd getPrice]];
    [self.bridge interstitialAd:self.adapter didAdServerResponseWithExt:@{
        AWMMediaAdLoadingExtECPM: price
    }];
    self.isReady = YES;
    [self.bridge interstitialAdDidLoad:self.adapter];
}

- (void)octad_intersitital:(OctAdIntersitital *)intersititalAd didFailWithError:(NSError *)error {
    NSLog(@"插屏广告加载失败");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    self.isReady = NO;
    [self.bridge interstitialAd:self.adapter didLoadFailWithError:error ext:nil];
}

- (void)octad_intersititalDidVisible:(OctAdIntersitital *)intersititalAd {
    NSLog(@"插屏广告曝光");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    self.isReady = NO;
    [self.bridge interstitialAdDidVisible:self.adapter];
}

- (void)octad_intersititalAdViewDidClick:(OctAdIntersitital *)intersititalAd {
    NSLog(@"插屏广告点击");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    [self.bridge interstitialAdDidClick:self.adapter];
}

- (void)octad_intersititalDidClose:(OctAdIntersitital *)intersititalAd {
    NSLog(@"插屏广告关闭");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    [self.bridge interstitialAdDidClose:self.adapter];
}

- (void)octad_intersititalWillCloseOtherView:(OctAdIntersitital *)intersititalAd {
    NSLog(@"插屏广告落地页关闭");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    [self.bridge interstitialAdDidClose:self.adapter];
}
@end
