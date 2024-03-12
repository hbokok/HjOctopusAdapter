#import "HjOctopusRewardedVideoAdapter.h"
#import <WindFoundation/WindFoundation.h>
#import "HjOctopusRewardedVideoAd.h"

@interface HjOctopusRewardedVideoAdapter ()
@property (nonatomic, weak) id<AWMCustomRewardedVideoAdapterBridge> bridge;
@property (nonatomic, strong) id<HjOctopusAdProtocol> ad;
@end

@implementation HjOctopusRewardedVideoAdapter
- (instancetype)initWithBridge:(id<AWMCustomRewardedVideoAdapterBridge>)bridge {
    self = [super init];
    if (self) {
        _bridge = bridge;
    }
    return self;
}
- (BOOL)mediatedAdStatus {
    return [self.ad mediatedAdStatus];
}
- (void)loadAdWithPlacementId:(NSString *)placementId parameter:(AWMParameter *)parameter {
    self.ad = [[HjOctopusRewardedVideoAd alloc] initWithBridge:self.bridge adapter:self];
    [self.ad loadAdWithPlacementId:placementId parameter:parameter];
}
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController parameter:(AWMParameter *)parameter {
    return [self.ad showAdFromRootViewController:viewController parameter:parameter];
}
- (void)didReceiveBidResult:(AWMMediaBidResult *)result {
    [self.ad didReceiveBidResult:result];
}
- (void)destory {
    self.ad = nil;
}
- (void)dealloc {
    WindmillLogDebug(@"Octopus", @"%s", __func__);
}
@end
