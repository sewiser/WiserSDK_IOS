//
//  NSObject+WSHex.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKHex)

+ (instancetype)tysdk_stringFromHexString:(NSString *)hexString;

- (NSString *)tysdk_hexString;

@end

@interface NSData (WSSDKHex)

+ (instancetype)tysdk_dataFromHexString:(NSString *)hexString;

- (NSString *)tysdk_hexString;

@end
