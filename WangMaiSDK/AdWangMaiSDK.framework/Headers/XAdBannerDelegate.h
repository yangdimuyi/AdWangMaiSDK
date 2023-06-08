//
//  XAdBannerDelegate.h
//  AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/2/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XAdBannerDelegate <NSObject>

@optional
/// 发起请求
- (void)bannerOnAdRequest;

/// 请求成功
- (void)bannerOnAdReady;

/// 请求失败
- (void)bannerOnError:(NSError *)error;

/// 展现
-(void)bannerOnExposure;

/// 点击
-(void)bannerOnClick;

/// 关闭
-(void)bannerOnAdClose;

@end

NS_ASSUME_NONNULL_END
