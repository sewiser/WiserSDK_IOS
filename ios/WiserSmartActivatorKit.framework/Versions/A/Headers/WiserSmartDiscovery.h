//
// WiserSmartDiscovery.h
// WiserSmartActivatorKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartDiscovery;

@protocol WiserSmartDiscoveryDelegate<NSObject>

@required

/// Callback of device discovery.
/// @param discovery Instance of WiserSmartDiscovery class.
/// @param deviceModel Wiser smart device model.
/// @param error NSError object.
- (void)discovery:(WiserSmartDiscovery *)discovery didDiscoveryDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief WiserSmartDiscovery is used for EZ configuration.
///
/// This class provides EZ configuration capabilities for WiFi devices.
///
/// @note This EZ configuration is different form the EZ mode in 'WiserSmartActivator'. Need to call the method 'bindDeviceWithHomeId:devIds:success:' after obtaining the devices, cause configuration token has no home information
///
@interface WiserSmartDiscovery : NSObject

@property (nonatomic, weak) id<WiserSmartDiscoveryDelegate> delegate;

/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(WSSuccessString)success
                failure:(WSFailureError)failure;

/// Start discovering devices.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                      timeout:(NSTimeInterval)timeout
                      success:(WSSuccessHandler)success
                      failure:(WSFailureError)failure;

/// Start discovering devices using token.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Configuration token.
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                         token:(NSString *)token
                      timeout:(NSTimeInterval)timeout
                      success:(WSSuccessHandler)success
                      failure:(WSFailureError)failure;

/// Binding devices to home.
/// @param homeId Home ID.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Stop discovering.
- (void)stopDiscovery;

@end

NS_ASSUME_NONNULL_END
