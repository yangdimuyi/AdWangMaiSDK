//
//  XAdWangMaiSDk.h
//  adwangmai_sdk
//
//  Created by 周泽浩 on 2022/11/30.
//  Copyright © 2022 YD. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XAdWangMaiSDk : NSObject


+ (instancetype)sharedInstance;

/**
  @brief 初始化SDK
 @param appToken 平台生成的appToken
 @param appKey 应用key
 @param appId 小程序跳转所需appId,用于向微信注册应用
 @param universalLink 小程序跳转所需universalLink,用于向微信注册应用
 */
- (void)initWithAppToken:(NSString *)appToken appKey:(NSString *)appKey appId:(NSString *_Nullable)appId universalLink:(NSString *_Nullable)universalLink;



/// sdk版本号
+ (NSString *)sdkVersion;
@end

NS_ASSUME_NONNULL_END
