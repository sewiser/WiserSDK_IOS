//
//  NSBundle+WSSDKLanguage.h
//  WiserSmartBaseKit
//
//
//  Copyright © 2018年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

#define WSSDKLocalizedString(key, comment) \
    [NSBundle wssdk_localizedStringForKey:(key) value:@"" table:nil]

@interface NSBundle (WSSDKLanguage)

+ (NSBundle *)wssdk_bundle;

+ (NSString *)wssdk_getAppleLanguages;

+ (NSString *)wssdk_localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)tableName;

@end
