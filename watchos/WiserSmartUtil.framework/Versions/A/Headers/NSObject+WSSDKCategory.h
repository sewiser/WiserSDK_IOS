//
//  NSObject+TPCategory.h
//  WSLibraryExample
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (WSSDKCategory)

- (NSInteger)wssdk_toInt;

- (NSUInteger)wssdk_toUInt;

- (NSString *)wssdk_toString;

- (float)wssdk_toFloat;

- (double)wssdk_toDouble;

- (BOOL)wssdk_toBool;

+ (BOOL)wssdk_swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

+ (BOOL)wssdk_swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;

@end
