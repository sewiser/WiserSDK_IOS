//
// WiserSmartAutoActivator+Home.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartAutoActivator (Home)

/// Get a list of all the devices under the current household that support password-free configuration.
/// @param homeId HomeId
/// @return Current list of all devices in the home that support password-free configuration.
- (NSArray <WiserSmartDeviceModel *> *)autoActiveSupportedDeviceListWithHomeId:(long long)homeId;

/// Get the list of all gateway router devices under the current family.
/// @param homeId Current home ID.
/// @return Current list of all home gateway router devices.
/// @deprecated This method is deprecated, Use WiserSmartRouterActivator::autoActiveRouterDeviceListWithHomeId: instead.
- (NSArray <WiserSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId __deprecated_msg("Use -[WiserSmartRouterActivator autoActiveRouterDeviceListWithHomeId:] instead.");


/// Binding devices to a specified home.
/// @param homeId HomeId
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
