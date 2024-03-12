//
//  AWMSDKConfigure.h
//  WindMillSDK
//
//  Created by Codi on 2023/6/2.
//

#import <Foundation/Foundation.h>
#import <WindMillSDK/WindMillEnum.h>

@interface AWMSDKConfigure : NSObject
/// 渠道ID
@property (nonatomic, assign, readonly) NSInteger adnId;
/// 渠道初始化所需的AppId [Required]
@property (nonatomic, strong, readonly) NSString *appId;
/// 渠道初始化所需的AppKey [Optional]
@property (nonatomic, strong, readonly) NSString *appKey;

/// 生成第三方渠道初始化对象
/// - Parameters:
///   - adnId: required 第三方渠道ID
///   - appId: optional 第三方渠道初始化appId
///   - appKey: optional 第三方渠道初始化appKey
- (instancetype)initWithAdnId:(WindMillAdn)adnId
                    appid:(NSString *)appId
                   appKey:(NSString *)appKey;

@end
