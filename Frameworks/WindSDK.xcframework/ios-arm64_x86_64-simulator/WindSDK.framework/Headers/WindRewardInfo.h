//
//  WindRewardInfo.h
//  WindSDK
//
//  Created by Codi on 2021/4/7.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WindRewardInfo : NSObject

/// 开发者可以根据激励回调中该参数进行奖励的发放
/// 对应激励回调：- (void)rewardVideoAd:reward:
@property (nonatomic,assign) BOOL isCompeltedView;

///
@property (nonatomic, strong) NSError *error;


@end
