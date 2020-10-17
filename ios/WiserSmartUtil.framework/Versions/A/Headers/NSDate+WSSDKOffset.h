//
//  NSDate+WSOffset.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSDate (WSSDKOffset)

// 云端时间戳，每次启动会去校准云端时间
+ (NSTimeInterval)wssdk_serverTimeIntervalSince1970;

+ (NSString *)wssdk_timeZone;

@end
