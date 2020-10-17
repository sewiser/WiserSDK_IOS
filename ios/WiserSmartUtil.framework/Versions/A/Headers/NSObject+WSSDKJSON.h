//
//  NSObject+WSJSON.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKJSON)
- (id)wssdk_objectFromJSONString;
- (id)wssdk_objectFromJSONString:(NSJSONReadingOptions)serializeOptions error:(NSError **)error;
@end

@interface NSArray (WSSDKJSON)
- (NSString *)wssdk_JSONString;
- (NSString *)wssdk_JSONStringWithOptions:(NSJSONWritingOptions)serializeOptions error:(NSError **)error;
@end

@interface NSDictionary (WSSDKJSON)
- (NSString *)wssdk_JSONString;
- (NSString *)wssdk_JSONStringWithOptions:(NSJSONWritingOptions)serializeOptions error:(NSError **)error;
@end
