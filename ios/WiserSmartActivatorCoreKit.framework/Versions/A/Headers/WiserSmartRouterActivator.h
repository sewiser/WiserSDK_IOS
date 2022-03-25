//
// WiserSmartRouterActivator.h
// WiserSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartRouterActivator;

@protocol WiserSmartRouterActivatorDelegate <NSObject>

/// Callback for configuration network status update.
/// @param activator The activator instance.
/// @param deviceModel The WiserSmartDeviceModel.
/// @param error The error message.
- (void)routerActivator:(WiserSmartRouterActivator *)activator didReceiveAutoConfigDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface WiserSmartRouterActivator : NSObject

/// Return the delegate of WiserSmartRouterActivator.
@property (nonatomic, weak) id<WiserSmartRouterActivatorDelegate> delegate;


/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(WSSuccessString)success
                failure:(WSFailureError)failure;


/// Start discovering devices.
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

@end

NS_ASSUME_NONNULL_END
