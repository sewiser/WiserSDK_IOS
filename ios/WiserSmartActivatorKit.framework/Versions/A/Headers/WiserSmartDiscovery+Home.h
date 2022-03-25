//
// WiserSmartDiscovery+Home.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartDiscovery (Home)

/// Binding devices to home.
/// @param homeId Home ID.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;


@end

NS_ASSUME_NONNULL_END
