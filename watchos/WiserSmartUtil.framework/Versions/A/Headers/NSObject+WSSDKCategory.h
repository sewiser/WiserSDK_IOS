//
//  NSObject+TPCategory.h
//  WSLibraryExample
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (WSSDKCategory)

- (NSInteger)tysdk_toInt;

- (NSUInteger)tysdk_toUInt;

- (NSString *)tysdk_toString;

- (float)tysdk_toFloat;

- (double)tysdk_toDouble;

- (BOOL)tysdk_toBool;

+ (BOOL)tysdk_swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

+ (BOOL)tysdk_swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;

@end
