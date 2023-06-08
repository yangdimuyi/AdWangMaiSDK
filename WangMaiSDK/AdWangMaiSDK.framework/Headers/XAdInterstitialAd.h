//
//  XAdInterstitialAd.h
//  AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol XAdInterstitialDelegate;

@interface XAdInterstitialAd : NSObject

/// 代理
@property (weak, nonatomic) id<XAdInterstitialDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

// caid以及caid版本号信息
// 数组内部未字典对象,Key为caid和caidVer,对应的值均为字符串类型,示例:@{@"caid":@"",@"caidVer":@""} [可选]
@property (nonatomic, strong) NSArray *caidInfo;

/// 初始化广告
/// - Parameter adSlotId: 广告ID
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/// 请求广告
- (void)loadAdData;

/// 展示插屏广告
/// @param controller 控制器
- (void)showAd:(UIViewController *)controller;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
