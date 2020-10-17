//
//  NSObject+WSHex.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKHex)

+ (instancetype)wssdk_stringFromHexString:(NSString *)hexString;

- (NSString *)wssdk_hexString;

@end

@interface NSData (WSSDKHex)

+ (instancetype)wssdk_dataFromHexString:(NSString *)hexString;

- (NSString *)wssdk_hexString;

@end
