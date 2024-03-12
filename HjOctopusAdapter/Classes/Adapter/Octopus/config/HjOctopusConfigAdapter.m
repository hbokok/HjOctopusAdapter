#import "HjOctopusConfigAdapter.h"
#import <OctAdSDK/OctAdManager.h>

@interface HjOctopusConfigAdapter ()
@property (nonatomic, weak) id<AWMCustomConfigAdapterBridge> bridge;
@end

@implementation HjOctopusConfigAdapter
- (instancetype)initWithBridge:(id<AWMCustomConfigAdapterBridge>)bridge {
    self = [super init];
    if (self) {
        _bridge = bridge;
    }
    return self;
}
- (AWMCustomAdapterVersion *)basedOnCustomAdapterVersion {
    return AWMCustomAdapterVersion1_0;
}
- (NSString *)adapterVersion {
    return @"1.0.0";
}
- (NSString *)networkSdkVersion {
    return [OctAdManager sdkVersion];
}
- (void)initializeAdapterWithConfiguration:(AWMSdkInitConfig *)initConfig {
    NSString *appId = [initConfig.extra objectForKey:@"appid"];
    NSLog(@"#####initializeAdapterWithConfiguration start: %@", appId);
    [OctAdManager configureWithApplicationID: appId];
    NSLog(@"#####initializeAdapterWithConfiguration end: %@", appId);
    NSLog(@"idfa=%@", [OctAdManager getIdfa]);
    [self.bridge initializeAdapterSuccess:self];
}
- (void)didRequestAdPrivacyConfigUpdate:(NSDictionary *)config {
}
@end
