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

+ (void)tysdk_setUserDefault:(id)object forKey:(NSString *)aKey;
+ (id)tysdk_getUserDefault:(NSString *)aKey;
+ (void)tysdk_removeUserDefault:(NSString *)aKey;

@end

NS_ASSUME_NONNULL_END
