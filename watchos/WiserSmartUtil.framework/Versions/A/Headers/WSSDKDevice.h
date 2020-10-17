//
//  WSDevice.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface WSSDKDevice : NSObject

+ (NSString *)wssdk_UUID __deprecated_msg("Use +[WiserSmartSDK sharedInstance].uuid instead.");

+ (NSString *)wssdk_generateUUID;

+ (NSString *)wssdk_deviceNameString;

+ (NSString *)wssdk_model;

+ (NSString *)wssdk_systemName;

+ (NSString *)wssdk_systemVersion;

@end
