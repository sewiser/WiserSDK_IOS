//
//  NSNumber+WSRandom.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSNumber (WSSDKRandom)

+ (NSInteger)tysdk_randomIntBetweenMin:(NSInteger)minValue andMax:(NSInteger)maxValue;

+ (float)tysdk_randomFloat;

+ (float)tysdk_randomFloatBetweenMin:(float)minValue andMax:(float)maxValue;

@end
