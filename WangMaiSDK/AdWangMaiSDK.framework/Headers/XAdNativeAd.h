//
//  XAdNativeAd.h
//  AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol XAdNativeDelegete;

@interface XAdNativeAd : NSObject

/// 代理
@property (weak, nonatomic) id<XAdNativeDelegete>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

/// 视频物料是否静音  [可选]  默认为NO
@property (nonatomic,assign) BOOL videoMuted;

/// 是否自动播放  [可选] 默认为YES
@property (nonatomic,assign) BOOL automaticallyPlay;

/// [必选]开发者需传入用来弹出目标页的ViewController
@property (nonatomic, weak) UIViewController *controller;

/// cd以及cd版本号信息  [可选]
/// 数组内部未字典对象,Key为cd(参数)和version(版本号),对应的值均为字符串类型,示例:@{@"cd":@"",@"version":@""}
@property (nonatomic, strong) NSArray *cdInfo;

/// 初始化广告
/// - Parameter adSlotId: 广告位ID
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/**
 加载广告数据
 */
- (void)loadAdData;

/// 视图注册方法
/// - Parameter clickableViews: 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
- (void)registerClickableViews:(NSArray<UIView *> *_Nonnull)clickableViews;

/// 广告数据渲染完毕，即将展示时需调用trackImpression方法。
- (void)trackImpression;

/// 播放视频
- (void)play;

/// 暂停视频
- (void)pause;

/// 播放静音开关
/// @param flag 是否静音
- (void)muteEnable:(BOOL)flag;

/// 广告销毁
- (void)onDestroy;

/// 竞价成功上报，旺脉平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo旺脉平台竞价获胜信息，可为nil。
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

@end

NS_ASSUME_NONNULL_END
