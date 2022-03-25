//
// WiserSmartDeviceOTAModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Device upgrade status.
typedef enum : NSUInteger {
    /// Not upgrading.
    WiserSmartDeviceOTAModelUpgradeStatusNone = 0,
    /// During the process of upgrade.
    WiserSmartDeviceOTAModelUpgradeStatusUpgrading = 2
} WiserSmartDeviceOTAModelUpgradeStatus;

@interface WiserSmartDeviceOTAModel : NSObject

/// device Id
@property (nonatomic, strong) NSString     *devId;

/// The status of device upgrading.
@property (nonatomic) WiserSmartDeviceOTAModelUpgradeStatus otaUpgradeStatus;

//针对BLEBeacon设备添加beaconCategory
@property (nonatomic, strong) NSString     *beaconCategory;

@end

NS_ASSUME_NONNULL_END
