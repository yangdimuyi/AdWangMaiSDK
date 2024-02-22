//
//  TXAdRewardVideoSlotModel.h
//  TanxSDK
//
//  Created by tongyuecheng on 2023/3/30.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import "TXAdSlotModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TXAdRewardVideoAdDefaultAudioState) {
    // 以有声状态开始播放
    TXAdRewardVideoAdDefaultAudioStateVocal = 0,
    // 以静音状态开始播放
    TXAdRewardVideoAdDefaultAudioStateMuted,
};

@interface TXAdRewardVideoSlotModel : TXAdSlotModel

/// 媒体自定义loadAd超时时间，默认没有超时时间，单位秒
@property(nonatomic, assign) NSTimeInterval loadAdTimeoutInterval;

/// 激励视频开始播放时，音频默认状态，可设成以静音状态开始播放。
@property(nonatomic, assign) TXAdRewardVideoAdDefaultAudioState defaultAudioState;

@end

NS_ASSUME_NONNULL_END
