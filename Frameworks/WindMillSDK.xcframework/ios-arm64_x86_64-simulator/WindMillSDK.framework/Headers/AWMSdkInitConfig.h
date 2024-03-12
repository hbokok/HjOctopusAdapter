//
//  AWMSdkInitConfig.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/10.
//

#import <Foundation/Foundation.h>

@interface AWMSdkInitConfig : NSObject
/// appID (自定义渠道请从extra中获取)
@property (nonatomic, copy, readonly) NSString *appID;

/// appKey (自定义渠道请从extra中获取)
@property (nonatomic, copy, readonly) NSString *appKey;

/// adnId (自定义渠道请从extra中获取)
@property (nonatomic, assign, readonly) NSInteger adnId;

/// publisherId (自定义渠道请从extra中获取)
@property (nonatomic, copy, readonly) NSString *publisherId;

/// 是否是自定义adapter
@property (nonatomic, assign, readonly) BOOL custom;

/// 自定义参数
@property (nonatomic, strong, readonly) NSDictionary *extra;

@end
