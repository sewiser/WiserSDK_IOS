//
//  WiserSmartDevice.h
//  WiserSmartKit
//
//
//  Copyright (c) 2015年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartDevice
#define WiserSmart_WiserSmartDevice

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartFirmwareUpgradeModel.h"
#import "WiserSmartDeviceModel.h"
#import "WiserSmartMQTTMessageModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Device online status
/// 设备的在线状态
typedef enum : NSUInteger {
    WSDeviceOnlineModeLocal, // Local network online
    WSDeviceOnlineModeInternet, // Internet online
    WSDeviceOnlineModeOffline, // offline
} WSDeviceOnlineMode;

/// dp publish channel
/// 设备控制的方式
typedef enum : NSUInteger {
    WSDevicePublishModeLocal, // Through local network
    WSDevicePublishModeInternet, // Through internet
    WSDevicePublishModeAuto, // Auto (If local network is avaliable, use local)
} WSDevicePublishMode;

@class WiserSmartDevice;

@protocol WiserSmartDeviceDelegate<NSObject>

@optional

/**
 *  Device info update, such as the name, online
 *  设备基本信息（例如名字，在线状态等）变化代理回调
 *
 *  @param device instance
 */
- (void)deviceInfoUpdate:(WiserSmartDevice *)device;

/**
 *  Device removed
 *  设备被移除变化代理回调
 *
 *  @param device instance
 */
- (void)deviceRemoved:(WiserSmartDevice *)device;

/**
 *  dp data update
 *  设备 dps 变化代理回调
 *
 *  @param device  instance
 *  @param dps     dps
 */
- (void)device:(WiserSmartDevice *)device dpsUpdate:(NSDictionary *)dps;

/**
 *  dp data update
 *  设备 dpCodes 变化代理回调
 *
 *  @param device  instance
 *  @param dpCodes dpCodes
 */
- (void)device:(WiserSmartDevice *)device dpCommandsUpdate:(NSDictionary *)dpCodes;

/**
 *  Firmware upgrade progress.
 *  固件升级进度
 *
 *  @param device   instance
 *  @param type     device type
 *  @param progress upgrade progress
 */
- (void)device:(WiserSmartDevice *)device firmwareUpgradeProgress:(NSInteger)type progress:(double)progress;

/**
 *  the delegate of device firmware upgrade status update
 *  设备升级状态的回调
 *
 *  @param device         deviceModel
 *  @param upgradeStatus  upgrade status
 */
- (void)device:(WiserSmartDevice *)device type:(NSInteger)type upgradeStatus:(WiserSmartDeviceUpgradeStatus)upgradeStatus;

/**
 *  Wifi signal strength callback.
 *  Wifi信号强度
 *
 *  @param device   instance
 *  @param signal   Signal strength
 */
- (void)device:(WiserSmartDevice *)device signal:(NSString *)signal;

/**
 *  Recv custom message
 *  收到自定义消息
 *
 *  @param device   instance
 *  @param message  custom message
 */
- (void)device:(WiserSmartDevice *)device didReceiveCustomMessage:(WiserSmartMQTTMessageModel *)message;

/**
 *  the delegate of warning information update
 *  设备的告警信息变化的代理回调
 *
 *  @param device       instance
 *  @param warningInfo  warning info
 */
- (void)device:(WiserSmartDevice *)device warningInfoUpdate:(NSDictionary *)warningInfo;

#pragma - deprecated

/**
 *  Device firmware upgrade success
 *  固件升级成功代理回调
 *
 *  @param device instance
 *  @param type   device type
 */
- (void)deviceFirmwareUpgradeSuccess:(WiserSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

/**
 *  Device firmware upgrade failure
 *  固件升级失败代理回调
 *
 *  @param device instance
 *  @param type   device type
 */
- (void)deviceFirmwareUpgradeFailure:(WiserSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

/**
 *  Device firmware upgrading
 *  固件升级中代理回调
 *
 *  @param device instance
 *  @param type   device type
 */
- (void)deviceFirmwareUpgrading:(WiserSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

@end

/// Device-related functions.
/// 设备相关功能
@interface WiserSmartDevice : NSObject

@property (nonatomic, strong, readonly) WiserSmartDeviceModel *deviceModel;
@property (nonatomic, weak, nullable) id<WiserSmartDeviceDelegate> delegate;

/**
 *  Get WiserSmartDevice instance. If current user don't have this device, a nil will be return.
 *  获取设备实例。如果当前用户没有该设备，将会返回nil。
 *
 *  @param devId Device ID
 *  @return instance
 */
+ (nullable instancetype)deviceWithDeviceId:(NSString *)devId;

/**
 *  Get WiserSmartDevice instance. If current user don't have this device, a nil will be return.
 *  获取设备实例。如果当前用户没有该设备，将会返回nil。
 *
 *  @param devId Device ID
 *  @return instance
 */
- (nullable instancetype)initWithDeviceId:(NSString *)devId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Get device online status.
 *  获取设备在线状态
 */
- (WSDeviceOnlineMode)onlineMode;

/**
 *  dp command publish.
 *  dp命令下发
 *
 *  @param dps     dp dictionary
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)publishDps:(NSDictionary *)dps
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/**
 *  dp command publish.
 *  dp命令下发
 *
 *  @param dps     dp dictionary
 *  @param mode    Publish mode(Lan/Internet/Auto)
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)publishDps:(NSDictionary *)dps
              mode:(WSDevicePublishMode)mode
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/**
 *  Edit device name.
 *  修改设备名称
 *
 *  @param name Device name
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)updateName:(NSString *)name success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Edit device icon.
 *  修改设备图片
 *
 *  @param icon     icon
 *  @param success  Success block
 *  @param failure  Failure block
 */
- (void)updateIcon:(UIImage *)icon
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/**
 *  Sync device information.
 *  同步设备信息到缓存
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)syncWithCloud:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Sync device information.
 *  同步设备信息
 *
 *  @param devId   Device ID
 *  @param homeId  Home ID
 *  @param success Success block
 *  @param failure Failure block
 */
+ (void)syncDeviceInfoWithDevId:(NSString *)devId homeId:(long long)homeId success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Sync subdevice information.
 *  同步子设备信息
 *
 *  @param gatewayId  Gateway ID
 *  @param devId   Device ID
 *  @param success Success block
 *  @param failure Failure block
 */
+ (void)syncSubDeviceInfoWithGatewayId:(NSString *)gatewayId devId:(NSString *)devId success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Remove device. Unbind the device with current user.
 *  移除设备，解除与当前用户的关联关系。
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)remove:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Restore factory settings.
 *  恢复出厂设置
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)resetFactory:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Get sub-device list of current gateway.
 *  获取当前网关下的子设备列表
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)getSubDeviceListFromCloudWithSuccess:(nullable void (^)(NSArray <WiserSmartDeviceModel *> *subDeviceList))success failure:(nullable WSFailureError)failure;

/**
 *  Synchronize the Longitude and Latitude of the Mobile Phone to the Device
 *  将手机的经纬度同步到设备
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)syncLocationToDeviceWithSucecess:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

#pragma mark - firmware upgrade

/**
 *  Get firmware upgrade information.
 *  获取设备升级信息
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)getFirmwareUpgradeInfo:(nullable void (^)(NSArray <WiserSmartFirmwareUpgradeModel *> *upgradeModelList))success
                       failure:(nullable WSFailureError)failure;

/**
 *  Upgrade firmware. Receive success or failure callback from WiserSmartDeviceDelegate.
 *  下发升级指令，设备开始升级, 升级成功或失败会通过WiserSmartDeviceDelegate返回
 *
 *  @param type    Device type of `WiserSmartFirmwareUpgradeModel`
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)upgradeFirmware:(NSInteger)type success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Cancel firmware upgrade network request.
 *  取消未完成的固件升级接口请求
 */
- (void)cancelFirmwareRequest;


/**
 *  Report device firmware version.
 *  上报设备固件的版本号
 *
 *  @param version Version
 *  @param type    Device type
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)updateDeviceVersion:(NSString *)version type:(NSInteger)type success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;


#if TARGET_OS_IOS

/**
 *  Get wifi signal strength. Receive signal strength from`-[WiserSmartDeviceDelegate device:signal:]`.
 *  获取wifi的信号强度。通过`-[WiserSmartDeviceDelegate device:signal:]`接收回调
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)getWifiSignalStrengthWithSuccess:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  publish message in lan
 *  发送局域网消息
 *
 *  @param body     message body
 *  @param type     message type
 *  @param success  Success block
 *  @param failure  Failure block
 */
- (void)publishMessageInLanWithBody:(NSDictionary *)body type:(NSInteger)type success:(nullable WSSuccessDict)success failure:(nullable WSFailureError)failure;

/**
 *  Query dp initiative. Some dp won't report initiative when changed.
 *  获取主动查询的dp点，这些dp点只有在主动查询的时候才上报，否则不会上报。
 *
 *  @param dpsArray dpId array. If nil or empty array passed in，All dp will be queried。
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)getInitiativeQueryDpsInfoWithDpsArray:(nullable NSArray *)dpsArray success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Awake low energy device.
 *  唤醒低功耗设备
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)awakeDeviceWithSuccess:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;


#pragma mark - publish custom message

/**
 *  add custom message delegate.  Receive custom message from `- (void)device:(WiserSmartDevice *)device didReceiveCustomMessage:(WiserSmartMQTTMessageModel *)message`.
 *  添加自定义消息代理  通过`- (void)device:(WiserSmartDevice *)device didReceiveCustomMessage:(WiserSmartMQTTMessageModel *)message` 回调
 *
 *  @param delegate Delegate
 *  @param protocol Protocol
 */
- (void)addDelegate:(id<WiserSmartDeviceDelegate>)delegate forProtocol:(NSInteger)protocol;

/**
 *  remove custom message delegate
 *  删除自定义消息代理
 *
 *  @param delegate Delegate
 *  @param protocol Protocol
 */
- (void)removeDelegate:(id<WiserSmartDeviceDelegate>)delegate forProtocol:(NSInteger)protocol;

/**
 *  send to custom message
 *  自定义（非dps）消息发送
 *
 *  @param data     Data
 *  @param protocol Protocol
 *  @param success  Success block
 *  @param failure  Failure block
 */
- (void)publishCustomMessageWithData:(NSDictionary *)data
                            protocol:(NSInteger)protocol
                             success:(nullable WSSuccessHandler)success
                             failure:(nullable WSFailureError)failure;

#endif

/**
 *  dp command publish.
 *  标准 dp 命令下发
 *
 *  @param commands dpCode - value dictionary
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)publishDpWithCommands:(NSDictionary *)commands
                      success:(nullable WSSuccessHandler)success
                      failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
