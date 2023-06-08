//
//  XAdOrdinaryVideoAdDelegate.h
//  AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, AdType) {
    NORMAL_AD, // 一般图文或图片广告
    VIDEO_AD, // 视频广告
};


@protocol XAdOrdinaryVideoAdDelegate <NSObject>

@optional

/// 广告发起请求
- (void)ordinaryVideoOnAdRequest;

/// 请求成功
/// @param adType 广告类型
- (void)ordinaryVideoOnAdReadyWithAdType:(AdType)adType;

/// 请求失败
/// @param error 错误信息
- (void)ordinaryVideoOnAdError:(NSError *)error;

/// 展示
- (void)ordinaryVideoOnAdExposure;

/// 点击
- (void)ordinaryVideoOnAdClick;

/// 播放完成
- (void)ordinaryVideoOnAdPlayCompletion;

/// 播放失败
/// @param error 错误信息
- (void)ordinaryVideoOnAdPlayError:(NSError *)error;

/// 关闭
- (void)ordinaryVideoOnAdClose;

@end

NS_ASSUME_NONNULL_END
