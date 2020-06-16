//
//  NSBundle+WSSDKLanguage.h
//  WiserSmartBaseKit
//
//
//  Copyright © 2018年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

#define WSSDKLocalizedString(key, comment) \
    [NSBundle tysdk_localizedStringForKey:(key) value:@"" table:nil]

@interface NSBundle (WSSDKLanguage)

+ (NSBundle *)tysdk_bundle;

+ (NSString *)tysdk_getAppleLanguages;

+ (NSString *)tysdk_localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)tableName;

@end
