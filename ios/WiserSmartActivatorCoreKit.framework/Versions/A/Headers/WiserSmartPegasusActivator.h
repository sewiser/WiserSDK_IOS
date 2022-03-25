//
// WiserSmartPegasusActivator.h
// WiserSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartPegasusActivator;
@protocol WiserSmartPegasusActivatorDelegate <NSObject>

/// Devices found by Pegasus.
/// @param activator Activator instance.
/// @param serverDeviceModel The device is found, but there is no device ID at this time.
/// @param deviceModel The device is found, but there is no device ID at this time.
/// @param error Error message.
- (void)pegasusActivator:(WiserSmartPegasusActivator *)activator serverDevice:(WiserSmartDeviceModel *)serverDeviceModel didFoundDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError * __nullable)error;

/// Devices that have been configured for the network by Pegasus.
/// @param activator Activator instance.
/// @param deviceModel The found device.
/// @param error Error message.
- (void)pegasusActivator:(WiserSmartPegasusActivator *)activator didReceiveDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError * __nullable)error;

@end

@interface WiserSmartPegasusActivator : NSObject

@property (nonatomic, weak) id<WiserSmartPegasusActivatorDelegate> delegate;


/// Start Pegasus Activator discover pending device.
/// @param devIDs Device ID list
/// @param serverTimeout Configured devices, search timeout for devices to be configured.
/// @param clientTimeout Pending devices, pending devices is searched for and not added to the family timeout.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIDs:(NSArray<NSString *> *)devIDs
                  serverTimeout:(NSTimeInterval)serverTimeout
                  clientTimeout:(NSTimeInterval)clientTimeout
                        success:(WSSuccessHandler)success
                        failure:(WSFailureError)failure;


/// Already distributed devices stop continuing to discover equipment to be configured.
/// @param devIDs A list of devices that support Pegasus.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)stopDiscoverWithDevIDs:(NSArray<NSString *> *)devIDs
                        success:(WSSuccessHandler)success
                        failure:(WSFailureError)failure;


/// Configure of found devices to be configured on the network.
/// @param devIDs A list of devices that support Pegasus.
/// @param UUIDs List of UUIDs of devices to be configured.
/// @param token The token.
/// @param timeout Timeout time, default 100s.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startActivatorWithDevIDs:(NSArray<NSString *> *)devIDs
                           UUIDs:(NSArray<NSString *> *)UUIDs
                           token:(NSString *)token
                         timeout:(NSTimeInterval)timeout
                         success:(WSSuccessHandler)success
                         failure:(WSFailureError)failure;


/// Cancel the configuration of devices that being discovered by Pegasus.
/// @param devIDs A list of devices that support Pegasus.
/// @param UUIDs List of UUIDs of devices to be configured.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelActivatorWithDevIDs:(NSArray<NSString *> *)devIDs
                            UUIDs:(NSArray<NSString *> *)UUIDs
                          success:(WSSuccessHandler)success
                          failure:(WSFailureError)failure;
@end

NS_ASSUME_NONNULL_END
