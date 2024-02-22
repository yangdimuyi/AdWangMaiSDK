//
//  TXAdRewardManager.h
//  TanxSDK
//
//  Created by tongyuecheng on 2023/5/26.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TXAdRewardVideoRewardInfo.h"
#import "TXAdModel.h"
#import "TXAdManagerDelegate.h"
#import "TXAdRewardVideoSlotModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TXAdGetRewardAdsDataBlock)(NSArray <TXAdModel *> * _Nullable rewardAdModels, NSError * _Nullable error);

@protocol TXAdRewardAdsDelegate <NSObject,TXAdManagerDelegate>
@optional

/**
 * 视频下载成功回调
 * @param model 数据model
 */
- (void)onAdDidDownLoadSuccessWithModel:(TXAdModel *)model;

/**
 * 广告渲染失败回调
 * @param error 错误
 * @param model 数据model
 */
- (void)onAdDidShowFailError:(NSError *)error withModel:(TXAdModel *)model;

/**
 * 广告跳过回调
 * @param model 数据model
 */
- (void)onAdDidSkipWithModel:(TXAdModel *)model;

/**
 * 激励视频播放完成或者出错
 * @param error nil代表播放成功
 * @param model 数据model
 */
- (void)onAdDidFinishPlayingError:(nullable NSError *)error withModel:(TXAdModel *)model;

/**
 * 发奖回调
 * @param rewardInfo 发奖信息
 * @param model 数据model
 */
- (void)onAdDidReceiveRewardInfo:(TXAdRewardVideoRewardInfo *)rewardInfo withModel:(TXAdModel *)model;

@end

@interface TXAdRewardManager : NSObject

/// 回调代理
@property(nonatomic, weak) id<TXAdRewardAdsDelegate> delegate;
/**
 * 初始化方法
 * @param pid 广告pid
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *  @param slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdRewardVideoSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)getRewardAdsWithAdsDataBlock:(TXAdGetRewardAdsDataBlock)adsDataBlock;

/**
 * 上报竞价结果
 * param model 数据model(请求数据的回调里拿到的model)
 * @param  result 竞价结果yes/no
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 * 展示激励视频/激励浏览，在 rewardVideoAdDidLoad: 或者 rewardVideoAdDidDownloadVideo: 回调过后调用
 * @param viewController 当前所在VC
 * @param adModel
 * model
 */
- (void)showAdFromRootViewController:(UIViewController *)viewController withModel:(TXAdModel *)adModel;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

