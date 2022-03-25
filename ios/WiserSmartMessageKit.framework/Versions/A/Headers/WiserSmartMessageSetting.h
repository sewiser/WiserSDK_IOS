//
// WiserSmartMessageSetting.h
// WiserSmartMessageKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartBaseKit/WiserSmartBaseKit.h>
#import "WiserSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN


/// @brief WiserSmartMessageSetting provides methods for device DND.
///
@interface WiserSmartMessageSetting : NSObject

/// Set device Do Not Disturb status.
/// @param flags switch status.
/// @param success When successfully set device Do Not Disturb status, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)setDeviceDNDSettingStatus:(BOOL)flags success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Get device Do Not Disturb status.
/// @param success When successfully get device Do Not Disturb status, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)getDeviceDNDSettingstatusSuccess:(WSSuccessBOOL)success failure:(WSFailureError)failure;

/// Get Do Not Disturb list.
/// @param success When successfully get Do Not Disturb list, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)getDNDListSuccess:(WSSuccessList)success failure:(WSFailureError)failure;

/// Get device list.
/// @param success When successfully get device list, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)getDNDDeviceListSuccess:(WSSuccessList)success failure:(WSFailureError)failure;

/// Add device Do Not Disturb time.
/// @param requestModel DND request model.
/// @param success When successfully add Do Not Disturb time, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)addDNDWithDNDRequestModel:(WiserSmartMessageSettingDNDRequestModel *)requestModel success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Modify device  Do Not Disturb time.
/// @param timerID  time ID.
/// @param requestModel DND request model.
/// @param success When successfully modify device Do Not Disturb time, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)modifyDNDWithTimerID:(long)timerID DNDRequestModel:(WiserSmartMessageSettingDNDRequestModel *)requestModel success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Remove Do Not Disturb time.
/// @param timerID time ID.
/// @param success When successfully remove Do Not Disturb time, this block will be called.
/// @param failure When error occurred, return WSFailureError.
- (void)removeDNDWithTimerID:(long)timerID success:(WSSuccessHandler)success failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
