//
//  WSUserDefault.h
//  WiserSmart
//
//
//  Copyright (c) 2015年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WSSDKUserDefault : NSObject

+ (void)wssdk_setUserDefault:(id)object forKey:(NSString *)aKey;
+ (id)wssdk_getUserDefault:(NSString *)aKey;
+ (void)wssdk_removeUserDefault:(NSString *)aKey;

@end

NS_ASSUME_NONNULL_END
