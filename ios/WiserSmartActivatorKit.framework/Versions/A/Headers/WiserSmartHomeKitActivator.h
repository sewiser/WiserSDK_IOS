//
// WiserSmartHomeKitActivator.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartUtil/WiserSmartUtil.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>
NS_ASSUME_NONNULL_BEGIN


@class WiserSmartHomeKitActivator;
@protocol WiserSmartHomeKitActivatorDelegate <NSObject>

/// Configure callbacks for network status updates.
/// @param activator instance
/// @param deviceModel The device model.
/// @param error error
- (void)homeKitActivator:(WiserSmartHomeKitActivator *)activator didReceiveHomeKitDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;
@end

/// @brief WiserSmartHomeKitActivator is used for HomeKit device configuration.
///
/// This class provides HomeKit device configuration capabilities.
///
@interface WiserSmartHomeKitActivator : NSObject

///Returns the singleton of the class.
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<WiserSmartHomeKitActivatorDelegate> delegate;

/// Obtain the HomeKit device configuration token.
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(WSSuccessString)success failure:(WSFailureError)failure;


/// Obtain the HomeKit device configuration token with home id.
/// @param homeID The home id
/// @param success Called when the task finishes successfully. token will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeID:(long long)homeID Success:(WSSuccessString)success failure:(WSFailureError)failure;


/// Search for HomeKit devices.
/// @param timeout Timeout time.
/// @param token Configuration token.
/// @param success Called when the task finishes successfully. WiserSmartDeviceModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout token:(NSString *)token success:(void (^)(WiserSmartDeviceModel *))success failure:(WSFailureError)failure;

/// Search for HomeKit device.
/// @param timeout Timeout time.
/// @param token Configuration token.
/// @param success Called when the task finishes successfully. WiserSmartDeviceModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout token:(NSString *)token success:(void (^)(WiserSmartDeviceModel *))success failure:(WSFailureError)failure;


/// Search for HomeKit device.
/// @param timeout Timeout time.
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout success:(WSSuccessString)success failure:(WSFailureError)failure;


/// Binding HomeKit devices to the home.
///
/// Need to call the method when using WiserSmartHomeKitActivator::getTokenSuccess:failure:, cause configuration token has no home information
///
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindHomeKitDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;


/// Get device information based on pid.
/// @param productId The product ID.
/// @param success Called when the task finishes successfully. WSSuccessDict will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId success:(WSSuccessDict)success failure:(WSFailureError)failure;


/// Get device information based on pid.
/// @param productId The product ID.
/// @param uuid The device uuid
/// @param success Called when the task finishes successfully. WSSuccessDict will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId uuid:(NSString *)uuid success:(WSSuccessDict)success failure:(WSFailureError)failure;


/// Stop discovery devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
