//
//  TXAdTestInterface.h
//  TanxSDK
//
//  Created by Evan on 2023/5/6.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  仅为sdk测试使用，不对外开放
 */
@interface TXAdTestInterface : NSObject

/* ----------- videoCaches ----------- */
// 2 ---- 信息流；3 ---- 激励视频
+ (NSArray *)videoCache_getAllCacheURLWithType:(NSUInteger)type;
+ (void)videoCache_cleanAllCachesWithType:(NSUInteger)type;
+ (void)videoCache_cacheDeleteWithType:(NSUInteger)type url:(NSURL *)url;
+ (void)videoCache_downLoadCacheFilesWithType:(NSUInteger)type url:(NSString *)url;

/* ----------- splash Caches action ----------- */
+ (NSArray *)splash_getMaterials;
+ (NSString *)splash_loadResponse:(NSString *)pid;
+ (void)splash_saveResponse:(NSString *)res pid:(NSString *)pid;
+ (void)splash_deleteResponse:(NSString *)pid;
+ (void)splash_deleteMaterial:(NSString *)path;


@end


