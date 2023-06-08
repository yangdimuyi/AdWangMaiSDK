//
//  XAdOrdinaryVideoAd.h
//  AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol XAdOrdinaryVideoAdDelegate;

@interface XAdOrdinaryVideoAd : UIView

/// 代理
@property (nonatomic,weak) id<XAdOrdinaryVideoAdDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

// caid以及caid版本号信息
// 数组内部未字典对象,Key为caid和caidVer,对应的值均为字符串类型,示例:@{@"caid":@"",@"caidVer":@""} [可选]
@property (nonatomic, strong) NSArray *caidInfo;

/// [必选]开发者需传入用来弹出目标页的ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 初始化广告
/// - Parameters:
///   - adSize: 广告视图尺寸
///   - adSlotId: 广告位ID
- (instancetype)initWithAdSize:(CGSize)adSize adSlotId:(NSString *)adSlotId;

/// 加载广告
- (void)loadAdData;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
