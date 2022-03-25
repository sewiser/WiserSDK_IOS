//
// WiserSmartRouterActivator.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartRouterActivator;

@protocol WiserSmartRouterActivatorDelegate <NSObject>

/// Callback for configuration network status update.
/// @param activator The activator instance.
/// @param deviceModel The WiserSmartDeviceModel.
/// @param error The error message.
- (void)routerActivator:(WiserSmartRouterActivator *)activator didReceiveAutoConfigDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief WiserSmartRouterActivator is used for router configuration.
///
/// This class provides router configuration capabilities.
///
@interface WiserSmartRouterActivator : NSObject

/// Return the delegate of WiserSmartRouterActivator.
@property (nonatomic, weak) id<WiserSmartRouterActivatorDelegate> delegate;


/// Get the list of all gateway router devices which support router configuration under the current home.
/// @param homeId Current home ID.
/// @return Current list of all home gateway router devices.
- (NSArray <WiserSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId;


/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(WSSuccessString)success
                failure:(WSFailureError)failure;


/// Start discovering devices.
///
/// The 'devIds' should be obtained form WiserSmartRouterActivator::autoActiveRouterDeviceListWithHomeId:
///
/// @param devIds Device ID list.
/// @param type Type, 0 to start discover device.
/// @param timeout Timeout, default 100 seconds
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;


/// Start discovering devices.
///
/// The 'devIds' should be obtained form WiserSmartRouterActivator::autoActiveRouterDeviceListWithHomeId:
///
/// @param devIds Device ID list.
/// @param token Configuration token.
/// @param type Type, 0 to start discover device.
/// @param timeout Timeout, default 100 seconds
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                token:(NSString *)token
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;


/// Stop discovering devices.
- (void)stopDiscover;


/// Binding devices to home.
/// @param homeId HomeId.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
