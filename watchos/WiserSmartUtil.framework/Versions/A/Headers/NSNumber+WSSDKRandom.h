//
//  NSNumber+WSRandom.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSNumber (WSSDKRandom)

+ (NSInteger)wssdk_randomIntBetweenMin:(NSInteger)minValue andMax:(NSInteger)maxValue;

+ (float)wssdk_randomFloat;

+ (float)wssdk_randomFloatBetweenMin:(float)minValue andMax:(float)maxValue;

@end
