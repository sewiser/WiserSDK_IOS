//
//  NSObject+WSURL.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKURL)

- (NSString *)wssdk_urlEncodeString;

- (NSString *)wssdk_urlDecodeString;

@end

@interface NSURL (WSSDKQuery)

- (NSDictionary *)wssdk_queryDict;

@end
