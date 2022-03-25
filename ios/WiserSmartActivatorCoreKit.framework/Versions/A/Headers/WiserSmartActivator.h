//
// WiserSmartActivator.h
// WiserSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartActivator
#define WiserSmart_WiserSmartActivator

#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

/// This notification is sent after receiving a broadcast from a wired distribution device. Object is dictionary, @{@"productId":productId, @"gwId":gwId}
extern NSString *const WiserSmartActivatorNotificationFindGatewayDevice;

typedef enum : NSUInteger {
    WSActivatorModeEZ,///< smart config mode
    WSActivatorModeAP,///< access point mode
    WSActivatorModeQRCode,///< QR Code mode
    WSActivatorModeWired, ///< wired mode
} WSActivatorMode;

typedef enum : NSUInteger {
    WSActivatorStepFound = 1,///< device found
    WSActivatorStepRegisted = 2,///< device registered
    WSActivatorStepIntialized = 3,///< device initialized
    WSActivatorStepTimeOut = 4, ///< device config timeout
} WSActivatorStep;

@class WiserSmartActivator;

@protocol WiserSmartActivatorDelegate<NSObject>

@required

/// Callback for distribution status update, wifi single product, zigbee gateway, zigbee sub device.
/// @param activator instance
/// @param deviceModel deviceModel
/// @param error error
- (void)activator:(WiserSmartActivator *)activator didReceiveDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@optional

/// Callback for distribution status update, wifi single product, zigbee gateway, zigbee sub device.
/// @param activator instance
/// @param deviceModel deviceModel
/// @param step activator step
/// @param error error
- (void)activator:(WiserSmartActivator *)activator didReceiveDevice:(WiserSmartDeviceModel *)deviceModel step:(WSActivatorStep)step error:(NSError *)error;

/// Callback for distribution status update mesh gateway, deprecated.
/// @param activator instance
/// @param deviceId devId
/// @param meshId meshId
/// @param error error
/// @deprecated This method is deprecated, Use WiserSmartActivatorDelegate::activator:didReceiveDevice:error: instead `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.
- (void)meshActivator:(WiserSmartActivator *)activator didReceiveDeviceId:(NSString *)deviceId meshId:(NSString *)meshId error:(NSError *)error __deprecated_msg("Use -[WiserSmartActivatorDelegate activator:didReceiveDevice:error:] instead. `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.");

@end

@interface WiserSmartActivator : NSObject

/// Returns a singleton of the class.
+ (instancetype)sharedInstance;

#pragma mark - SSID

/// Get the SSID of the current Wi-Fi.
///
/// Starting with iOS 12, calls to this function will return nil by default, and will only return the correct value if "Access WiFi Information" is enabled in the Xcode project. This function needs to be activated in the App IDs on the developer page in order to use it.
/// Starting with iOS 13, at least one of the following three conditions must also be met.
///   - An app that has been granted Location Services permissions.
///   - A VPN application that is currently enabled.
///   - Use of NEHotspotConfiguration (only Wi-Fi networks configured through the app are supported).
///
/// @see https://developer.apple.com/videos/play/wwdc2019/713/
///
/// @return Wi-Fi SSID
+ (NSString *)currentWifiSSID;

/// Get the BSSID of the current Wi-Fi.
/// @see WiserSmartActivator::currentWifiSSID.
/// @return Wi-Fi BSSID
+ (NSString *)currentWifiBSSID;

/// Get the SSID of the current Wi-Fi asynchronously.
/// @see WiserSmartActivator::currentWifiSSID
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getSSID:(WSSuccessString)success
        failure:(WSFailureError)failure;

/// Asynchronously get the BSSID of the current Wi-Fi.
/// @param success Called when the task finishes successfully. WSSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBSSID:(WSSuccessString)success
         failure:(WSFailureError)failure;

#pragma mark - Delegate

@property (nonatomic, weak) id<WiserSmartActivatorDelegate> delegate;

#pragma mark - active gateway

/// Start configuration (Wireless config).
/// @param mode Config mode, EZ or AP.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Config Token.
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFi:(WSActivatorMode)mode
                   ssid:(NSString *)ssid
               password:(NSString *)password
                  token:(NSString *)token
                timeout:(NSTimeInterval)timeout;

/// Start configuration (Wired config).
/// @param token Token
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFiWithToken:(NSString *)token
                         timeout:(NSTimeInterval)timeout;

/// Start configuring the network to activate only one category of devices (Wired config).
/// @param token Config Token.
/// @param productId ProductId of device.
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFiWithToken:(NSString *)token
                       productId:(NSString *)productId
                         timeout:(NSTimeInterval)timeout;

/// Start EZ mode multi-device configuration network
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Config Token.
/// @param timeout Timeout, default 100 seconds.
- (void)startEZMultiConfigWiFiWithSsid:(NSString *)ssid
                              password:(NSString *)password
                                 token:(NSString *)token
                               timeout:(NSTimeInterval)timeout;

/// Stop configuring the network.
- (void)stopConfigWiFi;

#pragma mark - active sub device

/// Activate sub-devices e.g. zigbee, Wi-Fi sub-devices.
/// @param gwId     Gateway Id
/// @param timeout  Timeout, default 100 seconds
- (void)activeSubDeviceWithGwId:(NSString *)gwId timeout:(NSTimeInterval)timeout;

/// Stop activate sub device with gateway ID.
/// @param gwId Gateway Id
- (void)stopActiveSubDeviceWithGwId:(NSString *)gwId;

@end

#endif
