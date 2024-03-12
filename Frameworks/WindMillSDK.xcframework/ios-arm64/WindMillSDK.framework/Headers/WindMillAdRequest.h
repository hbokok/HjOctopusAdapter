//
//  WindMillAdRequest.h
//  WindSDK
//
//  Created by happyelements on 2018/4/8.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WindMillAdRequest : NSObject

/// 【可选】，媒体用户ID。
@property (nonatomic,copy) NSString *userId;

/// 【比传】，广告位ID。
@property (nonatomic,copy) NSString *placementId;

/// 【可选】，服务端激励回传时，透传参数。
@property (nonatomic,strong) NSDictionary<NSString *, NSString *> *options;

+ (instancetype)request;



@end
