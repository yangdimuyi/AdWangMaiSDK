//
//  TXAdSDKConfiguration.h
//  TanxSDK-iOS
//
//  Created by guqiu on 2021/12/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXAdSDKConfiguration : NSObject

/// 当前的APPID(只读)
@property (nonatomic, copy, readonly) NSString *appID;
@property (nonatomic, copy, readonly) NSString *appKey;

/// 当前是否禁止获取idfa(只读)
@property (nonatomic, assign, readonly) BOOL forbiddenUseIDFA;

///是否支持实时曝光
@property (nonatomic, assign) BOOL realTimeSwitch;

/// 媒体自定义用户质量,字段格式{"key":["value"]}
@property (nonatomic, strong) NSDictionary<NSString *,NSArray *> * userTag;

// 媒体用户ID 仅做透传给服务端
@property (nonatomic, strong) NSString * mediaUid;

/// 单例初始化
+ (instancetype)sharedConfiguration;

/// 获取SDK版本号
+ (NSString *)sdkVersion;

/// 获取SDK构建号
+ (double)sdkBuildNumber;

/// 获取SDK idfv
+ (NSString *)idfv;

/// 是否禁止SDK获取idfa
/// @param forbiddened YES:禁止获取
- (void)forbiddenUseIDFA:(BOOL)forbiddened;

/// 禁止SDK获取idfa前提下，外部媒体通过该接口传递IDFA
/// @param idfa 外部传入的idfa
- (void)setSDKIDFA:(NSString *)idfa;

/// 外部媒体通过该接口传递IDFV
- (void)setSDKIDFV:(NSString *)idfv;

/// 外部媒体通过该接口传递经纬度
/// @param lon 经度
/// @param lat 纬度
- (void)setSDKLBSLon:(NSString *)lon lat:(NSString *)lat;

/// 关闭个性化推荐控制
/// @param closed YES:禁止获取
- (void)closePersonalized:(BOOL)closed;


@property (nonatomic, assign) CGFloat titleSize;
/// 是否可以设置字体大小
@property (nonatomic, assign) BOOL customTitleSizeSwitch;

// 外部媒体通过该接口设置标题字体大小
- (void)setTitleSize:(CGFloat )titleSize;

- (void)closeCustomTitleSize;

@end

NS_ASSUME_NONNULL_END
