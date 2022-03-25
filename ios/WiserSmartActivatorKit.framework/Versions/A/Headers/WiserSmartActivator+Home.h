//
// WiserSmartActivator+Home.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartActivator (Home)

/// Obtain allocation token using home ID (valid for 10 minutes).
/// @param homeId Home Id
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeId:(long long)homeId
                   success:(WSSuccessString)success
                   failure:(WSFailureError)failure;


/// Obtain allocation token using product ID (valid for 10 minutes).
/// @param productKey Product Id
/// @param homeId Home Id
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithProductKey:(NSString *)productKey
                        homeId:(long long)homeId
                       success:(WSSuccessString)success
                       failure:(WSFailureError)failure;

/// Obtain allocation token using UUID (valid for 10 minutes).
/// @param uuid Device uuid
/// @param homeId Home Id
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithUUID:(NSString *)uuid
                  homeId:(long long)homeId
                 success:(WSSuccessString)success
                 failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
