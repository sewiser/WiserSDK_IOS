//
//  WiserSmartDevice+Home.h
//  WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartDevice (Home)

/// Sync device information.
/// @param devId The device ID.
/// @param homeId The home ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncDeviceInfoWithDevId:(NSString *)devId
                         homeId:(long long)homeId
                        success:(nullable WSSuccessHandler)success
                        failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
