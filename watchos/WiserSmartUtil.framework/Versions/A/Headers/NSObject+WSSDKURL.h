//
//  NSObject+WSURL.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKURL)

- (NSString *)tysdk_urlEncodeString;

- (NSString *)tysdk_urlDecodeString;

@end

@interface NSURL (WSSDKQuery)

- (NSDictionary *)tysdk_queryDict;

@end
