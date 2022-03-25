//
// WiserSmartAutoActivator.h
// WiserSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartAutoActivator;

@protocol WiserSmartAutoActivatorDelegate <NSObject>

/// Configure callbacks for status updates of the network.
/// @param activator instance
/// @param deviceModel Device model.
/// @param error error
- (void)autoActivator:(WiserSmartAutoActivator *)activator didReceiveAutoConfigDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface WiserSmartAutoActivator : NSObject

/// Return the delegate of WiserSmartAutoActivator.
@property (nonatomic, weak) id<WiserSmartAutoActivatorDelegate> delegate;

/// Returns the single of the class.
+ (instancetype)sharedInstance;

/// Start discovering devices.
/// @param devIds Device Id list
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                        timeout:(NSTimeInterval)timeout
                        success:(WSSuccessHandler)success
                        failure:(WSFailureError)failure;

/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(WSSuccessString)success
                failure:(WSFailureError)failure;

/// Start discovering devices.
/// @param devIds Device ID list.
/// @param token Configuration token.
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                          token:(NSString *)token
                        timeout:(NSTimeInterval)timeout
                        success:(WSSuccessHandler)success
                        failure:(WSFailureError)failure;

/// Start discovering gateway routers.
/// @param devIds Device ID list.
/// @param type Type,  0 to start discover device.
/// @param timeout Timeout, default 100 seconds
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartRouterActivator::startDiscoverRouterWithDevIds:type:timeout:success:failure: instead.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure __deprecated_msg("Use -[WiserSmartRouterActivator startDiscoverRouterWithDevIds:type:timeout:success:failure:] instead.");

/// Stop discovery devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
