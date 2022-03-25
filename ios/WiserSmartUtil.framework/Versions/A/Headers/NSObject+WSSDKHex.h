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

/// Big or Small Data Transform，like this 510a3b -> 3b0a51
- (NSString *)wssdk_dataTransformBigSmall;

@end

@interface NSData (WSSDKHex)

+ (instancetype)wssdk_dataFromHexString:(NSString *)hexString;

- (NSString *)wssdk_hexString;

@end
