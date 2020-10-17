//
//  NSMutableDictionary+WSSDKCategory.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableDictionary (WSSDKCategory)

- (void)wssdk_safeSetObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end

NS_ASSUME_NONNULL_END
