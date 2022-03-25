//
// WiserSmartHomeKitActivator+Home.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHomeKitActivator (Home)

/// Get the token of the homeKit device wiring network.
/// @param homeID The home id
/// @param success Called when the task finishes successfully. token will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeID:(long long)homeID Success:(WSSuccessString)success failure:(WSFailureError)failure;

/// Binding HomeKit devices to the home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindHomeKitDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;


@end

NS_ASSUME_NONNULL_END
