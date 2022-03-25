//
// WiserSmartDevice+WiFiBackup.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#if TARGET_OS_IOS

#import "WiserSmartDevice.h"

/// @brief Smart Device Wi-Fi Alternative Switching feature to get alternative Wi-Fi.
///
/// When one of the Wi-Fi is not available, the device will automatically switch to the alternative Wi-Fi to ensure the device can work properly.
///
API_AVAILABLE(ios(10.0))
@interface WiserSmartDevice (WiFiBackup)

/// Get current Wi-Fi info.
/// @param success Called when the task finishes successfully. WSSuccessDict will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getCurrentWifiInfoWithSuccess:(WSSuccessDict)success failure:(WSFailureError)failure;


/// Get a list of alternate networks
/// @param success Called when the task finishes successfully. WSSuccessDict will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getBackupWifiListWithSuccess:(WSSuccessDict)success failure:(WSFailureError)failure;


/// Setting up an alternate network list
/// @param list Backup wifi list.
/// @param success Called when the task finishes successfully. A list of WiserSmartBackupWifiModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)setBackupWifiList:(NSArray<WiserSmartBackupWifiModel *> *)list success:(WSSuccessDict)success failure:(WSFailureError)failure;


/// Switching to a saved alternate network
/// @param hash Hash for the SSID + password, returned from device.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)switchToBackupWifiWithHash:(NSString *)hash success:(WSSuccessDict)success failure:(WSFailureError)failure;


/// Switching to a new alternate network
/// @param ssid SSID
/// @param password SSID
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)switchToBackupWifiWithSSID:(NSString *)ssid password:(NSString *)password success:(WSSuccessDict)success failure:(WSFailureError)failure;


@end

#endif
