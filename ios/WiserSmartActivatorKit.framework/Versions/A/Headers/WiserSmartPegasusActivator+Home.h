//
// WiserSmartPegasusActivator+Home.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartPegasusActivator (Home)

/// Devices supporting Pegasus.
/// @param homeID The home ID.
/// @return A list of devices that support Pegasus.
+ (NSArray <WiserSmartDeviceModel *> *)pegasusDeviceListWithHomeID:(long long)homeID;


@end

NS_ASSUME_NONNULL_END
