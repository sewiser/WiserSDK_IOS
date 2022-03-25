//
// WiserSmartHomeKitActivator.h
// WiserSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartUtil/WiserSmartUtil.h>
#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>
NS_ASSUME_NONNULL_BEGIN


@class WiserSmartHomeKitActivator;
@protocol WiserSmartHomeKitActivatorDelegate <NSObject>

/// Configure callbacks for network status updates.
/// @param activator instance
/// @param deviceModel The device model.
/// @param error error
- (void)homeKitActivator:(WiserSmartHomeKitActivator *)activator didReceiveHomeKitDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;
@end

@interface WiserSmartHomeKitActivator : NSObject

///Returns the singleton of the class.
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<WiserSmartHomeKitActivatorDelegate> delegate;

/// Get the HomeKit device configuration token.
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(WSSuccessString)success failure:(WSFailureError)failure;


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
