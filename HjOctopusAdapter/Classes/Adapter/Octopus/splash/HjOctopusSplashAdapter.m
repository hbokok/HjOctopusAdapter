#import "HjOctopusSplashAdapter.h"
#import <WindFoundation/WindFoundation.h>
#import <OctAdSDK/OctAdSplash.h>


@interface HjOctopusSplashAdapter ()<OctAdSplashDelegate>
@property (nonatomic, weak) id<AWMCustomSplashAdapterBridge> bridge;
@property (nonatomic, strong) OctAdSplash *splashAd;
@property (nonatomic, strong) AWMParameter *parameter;
@property (nonatomic, assign) BOOL isReady;
@end

@implementation HjOctopusSplashAdapter
- (instancetype)initWithBridge:(id<AWMCustomSplashAdapterBridge>)bridge {
    NSLog(@"#####initWithBridge:");
    self = [super init];
    if (self) {
        _bridge = bridge;
    }
    return self;
}
- (BOOL)mediatedAdStatus {
    NSLog(@"#####mediatedAdStatus:");
    return self.isReady;
}
- (void)loadAdWithPlacementId:(NSString *)placementId parameter:(AWMParameter *)parameter {
    NSLog(@"#####loadAdWithPlacementId");
    self.parameter = parameter;
    NSLog(@"#####placementId1: %@", parameter.placementId);
    UIViewController *viewController = [self.bridge viewControllerForPresentingModalView];
    NSLog(@"#####placementId2: %@", parameter.placementId);
    UIView *bottomView = [parameter.extra objectForKey:AWMAdLoadingParamSPCustomBottomView];
    NSLog(@"#####placementId3: %@", parameter.placementId);
    UIView *supView = viewController.navigationController ? viewController.navigationController.view : viewController.view;
    NSLog(@"#####placementId4: %@", parameter.placementId);
    NSValue *sizeValue = [parameter.extra objectForKey:AWMAdLoadingParamSPExpectSize];
    NSLog(@"#####placementId5: %@", parameter.placementId);
    CGSize adSize = [sizeValue CGSizeValue];
    NSLog(@"#####placementId6: %@", parameter.placementId);
    if (adSize.width * adSize.height == 0) {
        CGFloat h = CGRectGetHeight(bottomView.frame);
        adSize = CGSizeMake(supView.frame.size.width, supView.frame.size.height - h);
    }
    NSLog(@"#####placementId7: %@", parameter.placementId);
    self.splashAd = [[OctAdSplash alloc] initWithSlotId:parameter.placementId];
    NSLog(@"#####placementId8888: %@", [UIApplication sharedApplication].keyWindow.rootViewController);
    NSLog(@"#####placementId8: %@", parameter.placementId);
    self.splashAd.delegate = self;
    [self.splashAd loadAd];
   
}
- (void)showSplashAdInWindow:(UIWindow *)window parameter:(AWMParameter *)parameter {
    NSLog(@"#####showSplashAdInWindow");
//    UIView *bottomView = [parameter.extra objectForKey:AWMAdLoadingParamSPCustomBottomView];
    UIViewController *viewController = [self.bridge viewControllerForPresentingModalView];
    UIView *supView = viewController.navigationController ? viewController.navigationController.view : viewController.view;
//    CGRect supFrame = supView.bounds;
//    CGRect adFrame = CGRectMake(0, 0, supFrame.size.width, supFrame.size.height - bottomView.bounds.size.height);
//    if (bottomView) {
//        [supView addSubview:bottomView];
//        bottomView.frame = CGRectMake(0,
//                                      supFrame.size.height - CGRectGetHeight(bottomView.frame),
//                                      CGRectGetWidth(bottomView.frame),
//                                      CGRectGetHeight(bottomView.frame)
//                                      );
//    }
    [self.splashAd showAdsInWindow:supView];
}
- (void)didReceiveBidResult:(AWMMediaBidResult *)result {
    NSLog(@"#####didReceiveBidResult");
}
- (void)destory {
    NSLog(@"#####destory");
    [self removeSplashAdView];
}
- (void)removeSplashAdView {
    NSLog(@"#####removeSplashAdView");
    self.splashAd = nil;
}

#pragma mark - AWMCustomSplashAdapterBridge
/**
 @return 展示下部logo位置，需要给传入view设置尺寸。
 */
- (UIView *)octad_splashBottomView {
    UILabel *view = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 375, 100)];
    view.backgroundColor = [UIColor whiteColor];
    view.text = @"章鱼SDK";
    view.textAlignment = NSTextAlignmentCenter;
    view.textColor = UIColor.blackColor;
    return view;
}


- (void)octad_splashAdSuccess:(id)splashAd {
    NSLog(@"广告加载成功");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    NSString *price = [NSString stringWithFormat:@"%d", [self.splashAd getPrice]];
    [self.bridge splashAd:self didAdServerResponseWithExt:@{
        AWMMediaAdLoadingExtECPM: price
    }];
    self.isReady = YES;
    [self.bridge splashAdDidLoad:self];
}

/**
 广告已出现
 */
- (void)octad_splashAdDidVisible:(OctAdSplash *)splashAd {
    NSLog(@"广告曝光");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    self.isReady = NO;
    [self.bridge splashAdWillVisible:self];
}

/**
 广告加载失败
 */
- (void)octad_splashAd:(OctAdSplash *)splashAd didFailWithError:(NSError * _Nullable)error {
    NSLog(@"广告加载失败 %@", error);
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    self.isReady = NO;
    [self.bridge splashAd:self didLoadFailWithError:error ext:nil];
}

/**
 SDK渲染开屏广告点击回调
 */
- (void)octad_splashAdDidClick:(OctAdSplash *)splashAd {
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    [self.bridge splashAdDidClick:self];
}

/**
 SDK渲染开屏广告关闭回调，当用户点击广告时会直接触发此回调，建议在此回调方法中直接进行广告对象的移除操作
 */
- (void)octad_splashAdDidClose:(OctAdSplash *)splashAd {
    NSLog(@"广告已经关闭");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    [self.bridge splashAdDidClose:self];
}

/**
 用户点击跳过按钮时会触发此回调，可在此回调方法中处理用户点击跳转后的相关逻辑
 */
- (void)octad_splashAdDidClickSkip:(OctAdSplash *)splashAd {
    NSLog(@"广告点击跳过");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
    [self.bridge splashAdDidClickSkip:self];
}

/**
 倒计时为0时会触发此回调
 */
- (void)octad_splashAdCountdownToZero:(OctAdSplash *)splashAd {
    NSLog(@"广告倒计时归零");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
}

/**
 点击进入的广告扩展页关闭
 */
- (void)octad_splashAdOtherControllerClose:(OctAdSplash *)splashAd {
    NSLog(@"广告详情页关闭");
    WindmillLogDebug(@"Octopus", @"%@", NSStringFromSelector(_cmd));
}

- (void)dealloc {
    WindmillLogDebug(@"Octopus", @"%s", __func__);
}
@end
