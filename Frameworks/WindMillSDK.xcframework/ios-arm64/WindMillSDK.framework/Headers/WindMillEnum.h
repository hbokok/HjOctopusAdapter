//
//  WindMillEnum.h
//  WindMillSDK
//
//  Created by Codi on 2021/10/21.
//


typedef enum : NSUInteger {
    WindMillAdSlotTypeNone = 0,
    WindMillAdSlotTypeRewardVideo=1,
    WindMillAdSlotTypeSplash=2,
    WindMillAdSlotTypeIntersititial=4,
    WindMillAdSlotTypeNative=5,
    WindMillAdSlotTypeBanner=7,
} WindMillAdSlotType;

typedef NS_ENUM(NSUInteger, WindMillMediaPlayerStatus) {
    WindMillMediaPlayerStatusInitial = 0,         // 初始状态
    WindMillMediaPlayerStatusLoading = 1,         // 加载中
    WindMillMediaPlayerStatusStarted = 2,         // 开始播放
    WindMillMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    WindMillMediaPlayerStatusError = 4,           // 播放出错
    WindMillMediaPlayerStatusStoped = 5,          // 播放停止
};

typedef enum : NSUInteger {
    WindMillAdLoadStatusNone = 0,
    WindMillAdLoadStatusLoading,
    WindMillAdLoadStatusFinished,
    WindMillAdLoadStatusError,
    WindMillAdLoadStatusPlaying,
} WindMillAdLoadStatus;

typedef enum : NSUInteger {
    WindMillAdReadyStatusNotReady = 0,
    WindMillAdReadyStatusReady,
} WindMillAdReadyStatus;

typedef enum : NSUInteger {
    WindNotifyTypeNone,
    WindNotifyTypeReady,
    WindNotifyTypeError,
} WindNotifyType;

typedef enum : NSUInteger {
    WindMillBidTypeS2S = 0,
    WindMillBidTypeC2S = 1,
} WindMillBidType;


typedef enum : NSUInteger {
    WindMillTemplateId2002001=2002001, //开屏
    WindMillTemplateId4012001=4012001, //竖版方型
    WindMillTemplateId4012002=4012002, //竖版上图下文（小）
    WindMillTemplateId4012003=4012003, //竖版上图下文（中）
} WindMillTemplateId;

typedef enum : NSUInteger {
    WindMillAdapterNone = 0,
    WindMillAdapterRewardVideo = 10,
    WindMillAdapterBiddingRewardVideo = 11,
    WindMillAdapterSplash = 20,
    WindMillAdapterIntersititial = 30,
    WindMillAdapterBiddingIntersititial = 31,
    WindMillAdapterNative = 40,
} WindMillAdapter;

typedef enum : NSInteger {
    WindMillAdnNoData   = -2,       // 暂时无真实数据，未获取到最佳广告，一般在未展示之前提前调用
    WindMillAdnCustom = -1,         // 自定义adn
    WindMillAdnNone = 0,            // 未知adn
    WindMillAdnMTG = 1,             // Mintegral
    WindMillAdnVungle = 4,          // Vungle
    WindMillAdnApplovin = 5,        // applovin
    WindMillAdnUnityAds = 6,        // unityads
    WindMillAdnIronsource = 7,      // ironsource
    WindMillAdnSigmob = 9,          // Sigmob
    WindMillAdnAdmob = 11,          // 谷歌Admob
    WindMillAdnCSJ = 13,            // 穿山甲
    WindMillAdnGDT = 16,            // 腾讯广点通
    WindMillAdnKs = 19,             // 快手
    WindMillAdnKlevin = 20,         // 游可赢
    WindMillAdnBaidu = 21,          // 百度联盟
    WindMillAdnGroMore = 22,        // GroMore
    WindMillAdnBeiZi = 27,          // AdScope
    WindMillAdnPangle = 30,         // Pangle
    WindMillAdnMax = 31,            // Max
    WindMillAdnReklamup = 33,       // Reklamup
    WindMillAdnAdMate = 35,         // admate
    WindMillAdnInMobi = 37,         // InMobi

} WindMillAdn;

typedef enum : NSUInteger {
    WindMillCountdownTime = 0,
    WindMillCountdownSkip,
    WindMillCountdownClose,
} WindMillCountdownType;

typedef enum : NSUInteger {
    WindMillCountdownWidthMiddle = 0,
    WindMillCountdownWidthBig,
    WindMillCountdownWidthSmall,
} WindMillCountdownWidthType;

typedef enum : NSUInteger  {
    WindMillInteractionTypeCustorm = 0,
    WindMillInteractionTypeNO_INTERACTION = 1,  // pure ad display
    WindMillInteractionTypeURL = 2,             // open the webpage using a browser
    WindMillInteractionTypePage = 3,            // open the webpage within the app
    WindMillInteractionTypeDownload = 4,        // download the app
    WindMillInteractionTypePhone = 5,           // make a call
    WindMillInteractionTypeMessage = 6,         // send messages
    WindMillInteractionTypeEmail = 7,           // send email
    WindMillInteractionTypeVideoAdDetail = 8,    // video ad details page
    WindMillInteractionTypeMediationOthers  = 100 //聚合其他广告sdk返回的类型
} WindMillInteractionType;


