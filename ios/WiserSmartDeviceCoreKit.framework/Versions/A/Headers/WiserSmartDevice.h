//
// WiserSmartDevice.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartDevice
#define WiserSmart_WiserSmartDevice

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartFirmwareUpgradeModel.h"
#import "WiserSmartFirmwareUpgradeStatusModel.h"
#import "WiserSmartDeviceModel.h"
#import "WiserSmartMQTTMessageModel.h"
#import "WiserSmartLanMessageModel.h"
#import "WiserSmartBackupWifiModel.h"
#import "WiserSmartDeviceOTAModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Device online status
typedef enum : NSUInteger {
    /// Local network online
    WSDeviceOnlineModeLocal,
    /// Internet online
    WSDeviceOnlineModeInternet,
    /// Offline
    WSDeviceOnlineModeOffline,
} WSDeviceOnlineMode;

/// Dp publish channel
typedef enum : NSUInteger {
    /// Through local network
    WSDevicePublishModeLocal,
    /// Through internet
    WSDevicePublishModeInternet,
    /// Auto choose channel to publish
    WSDevicePublishModeAuto,
} WSDevicePublishMode;

@class WiserSmartDevice;

/// The delegate for WiserSmartDevice class, used for getting all device status updates.
@protocol WiserSmartDeviceDelegate<NSObject>

@optional

/// Device info update, such as the name, online.
/// @param device The device instance.
- (void)deviceInfoUpdate:(WiserSmartDevice *)device;

/// Device removed.
/// @param device The device instance.
- (void)deviceRemoved:(WiserSmartDevice *)device;

/// Dp data update.
/// @param device The device instance.
/// @param dps Command dictionary.
- (void)device:(WiserSmartDevice *)device dpsUpdate:(NSDictionary *)dps;

/// Dp data update.
/// @param device The device instance.
/// @param dpCodes dpCodes.
- (void)device:(WiserSmartDevice *)device dpCommandsUpdate:(NSDictionary *)dpCodes;

/// Firmware upgrade progress.
/// @param device The device instance.
/// @param type The device type.
/// @param progress Upgrade progress
- (void)device:(WiserSmartDevice *)device firmwareUpgradeProgress:(NSInteger)type progress:(double)progress;

/// The delegate of device firmware upgrade status update.
/// @param device The device instance.
/// @param upgradeStatusModel Equipment upgrade status model.
- (void)device:(WiserSmartDevice *)device firmwareUpgradeStatusModel:(WiserSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;

/// Wifi signal strength callback.
/// @param device The device instance.
/// @param signal Signal strength.
- (void)device:(WiserSmartDevice *)device signal:(NSString *)signal;

/// Receive MQTT custom message.
/// @param device The device instance.
/// @param message Custom message.
- (void)device:(WiserSmartDevice *)device didReceiveCustomMessage:(WiserSmartMQTTMessageModel *)message;

/// Receive LAN custom message.
- (void)device:(WiserSmartDevice *)device didReceiveLanMessage:(WiserSmartLanMessageModel *)message;

/// The delegate of warning information update.
/// @param device The device instance.
/// @param warningInfo Warning info.
- (void)device:(WiserSmartDevice *)device warningInfoUpdate:(NSDictionary *)warningInfo;

#pragma - deprecated

/// The delegate of device firmware upgrade status update.
/// @param device The device instance.
/// @param type The device type.
/// @param upgradeStatus The device upgrade status.
/// @deprecated This method is deprecated, Use WiserSmartDeviceDelegate::device:firmwareUpgradeStatusModel: instead.
- (void)device:(WiserSmartDevice *)device type:(NSInteger)type upgradeStatus:(WiserSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use device:firmwareUpgradeStatusModel: instead");

/// Device firmware upgrade success.
/// @param device The device instance.
/// @param type The device type.
/// @deprecated This method is deprecated, Use WiserSmartDeviceDelegate::device:upgradeStatus: instead.
- (void)deviceFirmwareUpgradeSuccess:(WiserSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

/// Device firmware upgrade failure.
/// @param device The device instance.
/// @param type The device type.
/// @deprecated This method is deprecated, Use WiserSmartDeviceDelegate::device:upgradeStatus: instead
- (void)deviceFirmwareUpgradeFailure:(WiserSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

/// Device firmware upgrading.
/// @param device The device instance.
/// @param type The device type.
/// @deprecated This method is deprecated, Use WiserSmartDeviceDelegate::device:upgradeStatus: instead.
- (void)deviceFirmwareUpgrading:(WiserSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

@end

/// @brief The basic operation class of the Wiser Smart Device contains the basic information model of the device, commands to publish, update device information and other common operation interfaces.
///
/// No matter what type of device, can be operated by initializing an instance of this class if the function supports it.
///
@interface WiserSmartDevice : NSObject

/// Get the basic device information model
@property (nonatomic, strong, readonly) WiserSmartDeviceModel *deviceModel;

@property (nonatomic, weak, nullable) id<WiserSmartDeviceDelegate> delegate;

/// Get WiserSmartDevice instance. If current user don't have this device, a nil will be return.
/// @param devId The device ID.
+ (nullable instancetype)deviceWithDeviceId:(NSString *)devId;

/// Get WiserSmartDevice instance. If current user don't have this device, a nil will be return.
/// @param devId The device ID.
- (nullable instancetype)initWithDeviceId:(NSString *)devId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Get device online status.
- (WSDeviceOnlineMode)onlineMode;

/// Dp command publish.
/// @param dps The dp dictionary.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/// Dp command publish.
/// @param dps The dp dictionary.
/// @param mode Publish mode(Lan/Internet/Auto).
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps
              mode:(WSDevicePublishMode)mode
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/// Edit device name.
/// @param name The device name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateName:(NSString *)name
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/// Edit device icon.
/// @param icon The device icon.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/// Edit device icon.
/// @param cloudKey Cloud Key.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIconWithCloudKey:(NSString *)cloudKey
                       success:(nullable WSSuccessHandler)success
                       failure:(nullable WSFailureError)failure;

/// Sync device information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)syncWithCloud:(nullable WSSuccessHandler)success
              failure:(nullable WSFailureError)failure;


/// Sync device information.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncDeviceInfoWithDevId:(NSString *)devId
                        success:(nullable void (^)(WiserSmartDeviceModel *device))success
                        failure:(nullable WSFailureError)failure;

/// Sync subdevice information.
/// @param gatewayId The gateway ID.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncSubDeviceInfoWithGatewayId:(NSString *)gatewayId
                                 devId:(NSString *)devId
                               success:(nullable WSSuccessHandler)success
                               failure:(nullable WSFailureError)failure;

/// Remove device. Unbind the device with current user.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)remove:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Restore factory settings.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)resetFactory:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Get sub-device list of current gateway.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSubDeviceListFromCloudWithSuccess:(nullable void (^)(NSArray <WiserSmartDeviceModel *> *subDeviceList))success failure:(nullable WSFailureError)failure;

/// Synchronize the Longitude and Latitude of the Mobile Phone to the Device.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)syncLocationToDeviceWithSucecess:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

#pragma mark - firmware upgrade

/// Get firmware upgrade information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getFirmwareUpgradeInfo:(nullable void (^)(NSArray <WiserSmartFirmwareUpgradeModel *> *upgradeModelList))success
                       failure:(nullable WSFailureError)failure;

/// Upgrade firmware. Receive success or failure callback from WiserSmartDeviceDelegate.
/// @param type The device type of "WiserSmartFirmwareUpgradeModel".
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)upgradeFirmware:(NSInteger)type success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Cancel firmware upgrade, currently only supports canceling upgrade tasks that have not been published
/// @param type Device type of `WiserSmartFirmwareUpgradeModel`
/// @param success  Called when the task finishes successfully.
/// @param failure  Called when the task is interrupted by an error.
- (void)cancelUpgradeFirmware:(NSInteger)type success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Cancel firmware upgrade network request.
- (void)cancelFirmwareRequest;

/// Report device firmware version.
/// @param version The device version.
/// @param type The device type.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateDeviceVersion:(NSString *)version
                       type:(NSInteger)type
                    success:(nullable WSSuccessHandler)success
                    failure:(nullable WSFailureError)failure;

/// Get the switch value for the device OTA auto-upgrade
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getAutoUpgradeSwitchInfoWithSuccess:(nullable WSSuccessID)success
                                    failure:(nullable WSFailureError)failure;

/// Save the switch value for automatic device OTA upgrade.
/// @param switchValue The value of the auto switch. 0 represents off, and 1 means on.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)saveUpgradeInfoWithSwitchValue:(NSInteger)switchValue
                               success:(nullable WSSuccessHandler)success
                               failure:(nullable WSFailureError)failure;


/// Access to the device's custom data, such as recording and storing custom data information
/// @param success  Called when the task finishes successfully. The device property will return.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevPropertyWithSuccess:(WSSuccessDict)success
                          failure:(nullable WSFailureError)failure;


/// Set the device's custom data, which can be used to record and store custom data information
/// @param code The custom data key
/// @param value The custom data value
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)setDevPropertyWithCode:(NSString *)code
                         value:(id)value
                       success:(WSSuccessBOOL)success
                       failure:(nullable WSFailureError)failure;

#if TARGET_OS_IOS

/// Get wifi signal strength. Receive signal strength from`-[WiserSmartDeviceDelegate device:signal:]`.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getWifiSignalStrengthWithSuccess:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Publish message in LAN.
/// @param body The message body.
/// @param type The message type.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishMessageInLanWithBody:(NSDictionary *)body
                               type:(NSInteger)type
                            success:(nullable WSSuccessDict)success
                            failure:(nullable WSFailureError)failure;

/// Query dp initiative. Some dp won't report initiative when changed.
/// @param dpsArray DpId array. If nil or empty array passed in, All dp will be queried.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getInitiativeQueryDpsInfoWithDpsArray:(nullable NSArray *)dpsArray
                                      success:(nullable WSSuccessHandler)success
                                      failure:(nullable WSFailureError)failure;

/// Awake low energy device.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)awakeDeviceWithSuccess:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

#pragma mark - publish custom message

/// Add custom message delegate.  Receive custom message from `- (void)device:(WiserSmartDevice *)device didReceiveCustomMessage:(WiserSmartMQTTMessageModel *)message`.
/// @param delegate The delegate of WiserSmartDevice.
/// @param protocol Protocol.
- (void)addDelegate:(id<WiserSmartDeviceDelegate>)delegate forProtocol:(NSInteger)protocol;

/// Remove custom message delegate.
/// @param delegate The delegate of WiserSmartDevice.
/// @param protocol Protocol
- (void)removeDelegate:(id<WiserSmartDeviceDelegate>)delegate forProtocol:(NSInteger)protocol;

/// Send to custom message.
/// @param data Data.
/// @param protocol Protocol.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishCustomMessageWithData:(NSDictionary *)data
                            protocol:(NSInteger)protocol
                             success:(nullable WSSuccessHandler)success
                             failure:(nullable WSFailureError)failure;

#endif

/// Dp command publish.
/// @param commands DpCode - value dictionary.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpWithCommands:(NSDictionary *)commands
                      success:(nullable WSSuccessHandler)success
                      failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
