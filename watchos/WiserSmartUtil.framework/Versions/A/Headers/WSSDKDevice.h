//
//  WSDevice.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface WSSDKDevice : NSObject

+ (NSString *)tysdk_UUID __deprecated_msg("Use +[WiserSmartSDK SharedInstance].uuid instead.");

+ (NSString *)tysdk_generateUUID;

+ (NSString *)tysdk_deviceNameString;

+ (NSString *)tysdk_model;

+ (NSString *)tysdk_systemName;

+ (NSString *)tysdk_systemVersion;

@end
