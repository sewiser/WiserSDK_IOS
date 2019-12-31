//
//  NSObject+WSJSON.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKJSON)
- (id)tysdk_objectFromJSONString;
- (id)tysdk_objectFromJSONString:(NSJSONReadingOptions)serializeOptions error:(NSError **)error;
@end

@interface NSArray (WSSDKJSON)
- (NSString *)tysdk_JSONString;
- (NSString *)tysdk_JSONStringWithOptions:(NSJSONWritingOptions)serializeOptions error:(NSError **)error;
@end

@interface NSDictionary (WSSDKJSON)
- (NSString *)tysdk_JSONString;
- (NSString *)tysdk_JSONStringWithOptions:(NSJSONWritingOptions)serializeOptions error:(NSError **)error;
@end
