//
//  XAdWMNativeAd.h
//  AdWangMaiSDK
//
//  Created by xiang shi on 2024/9/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, AdSlotType) {
    WMAdSlotTypeSplash, //开屏
    WMAdSlotTypeNative, //信息流
    WMAdSlotTypeRewardVideo, //激励视频
    WMAdSlotTypeInterstitial, //插屏
};

NS_ASSUME_NONNULL_BEGIN
@protocol XAdWMNativeAdDelegate;

@interface XAdWMNativeAd : NSObject

/// 广告类型 Ad type. [必传]
@property (nonatomic,assign) AdSlotType adSlotType;

/// 代理
@property (weak, nonatomic) id<XAdWMNativeAdDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

/// 广告尺寸 [必传]
@property (nonatomic,assign) CGSize adSize;

/// [必传]开发者需传入用来弹出目标页的ViewController
@property (nonatomic, weak) UIViewController *controller;

/// cd以及cd版本号信息  [可选 媒体通过该参数传入caid]  
/// 数组内部为字典对象,Key为cd(参数)和version(版本号),对应的值均为字符串类型,示例:@{@"cd":@"",@"version":@""}
@property (nonatomic, strong) NSArray *cdInfo;

/// 初始化广告
/// - Parameter adSlotId: 广告位id
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/// 请求广告
- (void)loadAdData;

/// 竞价成功上报，旺脉平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo旺脉平台竞价获胜信息，可为nil。
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

/// 视图注册方法
/// - Parameter containerView: 广告容器视图 容器会添加点击事件监听
/// - Parameter clickableViews: 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
- (void)registerContainer:(UIView *)containerView withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews;

/// 广告数据渲染完毕，即将展示时需调用trackImpression方法。
- (void)trackImpression;

/// 广告将要关闭
- (void)adViewWillClosed;

/// 广告销毁
- (void)onDestroy;
@end

NS_ASSUME_NONNULL_END
