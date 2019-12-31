//
//  WSNotification.h
//  WSLibraryExample
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSSDKNotification : NSObject

+ (void)tysdk_postNotificationName:(nonnull NSString *)aName;

+ (void)tysdk_postNotificationName:(nonnull NSString *)aName object:(nullable id)anObject;

+ (void)tysdk_postNotificationName:(nonnull NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;


@end
