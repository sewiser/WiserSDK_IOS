//
//  WiserSmartFirmwareUpgradeStatusModel.h
//  CocoaAsyncSocket
//
//
//
//  固件升级状态Model

#import <Foundation/Foundation.h>
#import "WiserSmartDeviceModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartFirmwareUpgradeStatusModel : NSObject

/** 固件升级状态 firmware upgrade status */
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;
/** 固件类型 firmware type */
@property (nonatomic, assign) NSInteger type;
/** 固件升级对应状态提示文案 firmware upgrade explain text */
@property (nonatomic, copy) NSString *statusText;
/** 固件升级对应状态提示文案标题 firmware upgrade explain text title */
@property (nonatomic, copy) NSString *statusTitle;

@end

NS_ASSUME_NONNULL_END
