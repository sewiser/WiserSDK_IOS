//
// WiserSmartFirmwareUpgradeStatusModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartDeviceModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// device firmware upgrade status
@interface WiserSmartFirmwareUpgradeStatusModel : NSObject

/// firmware upgrade status
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;
/// firmware type
@property (nonatomic, assign) NSInteger type;
/// firmware upgrade explain text
@property (nonatomic, copy) NSString *statusText;
/// firmware upgrade explain text title
@property (nonatomic, copy) NSString *statusTitle;

@end

NS_ASSUME_NONNULL_END
