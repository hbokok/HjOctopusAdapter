#import "HjOctopusInterstitialAdapter.h"
#import "HjOctopusFullscreenVideoAd.h"
#import <WindFoundation/WindFoundation.h>

@interface HjOctopusInterstitialAdapter()
@property (nonatomic, weak) id<AWMCustomInterstitialAdapterBridge> bridge;
@property (nonatomic, strong) id<HjOctopusAdProtocol> ad;
@end

@implementation HjOctopusInterstitialAdapter
- (instancetype)initWithBridge:(id<AWMCustomInterstitialAdapterBridge>)bridge {
    self = [super init];
    if (self) {
        _bridge = bridge;
    }
    return self;
}
- (void)loadAdWithPlacementId:(NSString *)placementId parameter:(AWMParameter *)parameter {
    self.ad = [self adWithParameter:parameter];
    [self.ad loadAdWithPlacementId:placementId parameter:parameter];
}
- (BOOL)mediatedAdStatus {
    return [self.ad mediatedAdStatus];
}
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController parameter:(AWMParameter *)parameter {
    return [self.ad showAdFromRootViewController:viewController parameter:parameter];
}
- (void)didReceiveBidResult:(AWMMediaBidResult *)result {
    [self.ad didReceiveBidResult:result];
}
- (id<HjOctopusAdProtocol>)adWithParameter:(AWMParameter *)parameter {
    return [[HjOctopusFullscreenVideoAd alloc] initWithBridge:self.bridge adapter:self];
}
- (void)destory {
    self.ad = nil;
}
- (void)dealloc {
    WindmillLogDebug(@"Octopus", @"%s", __func__);
}
@end
