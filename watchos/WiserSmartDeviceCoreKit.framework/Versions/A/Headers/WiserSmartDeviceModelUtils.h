//
// WiserSmartDeviceModelUtils.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartDeviceModelUtils_h
#define WiserSmartDeviceModelUtils_h

/// device upgrade status
typedef enum : NSUInteger {
    WiserSmartDeviceUpgradeStatusDefault = 0,    // Default. No upgrade required by default.
    WiserSmartDeviceUpgradeStatusReady,          // Ready. Hardware readiness.
    WiserSmartDeviceUpgradeStatusUpgrading,      // Upgrading. Upgrade in progress.
    WiserSmartDeviceUpgradeStatusSuccess,        // Success. Upgrade completed.
    WiserSmartDeviceUpgradeStatusFailure,        // Failure. Upgrade Exception.
    WiserSmartDeviceUpgradeStatusWaitingExectue, // For nb,waiting execute nb. Equipment tasks have been issued, but not yet executed.
    WiserSmartDeviceUpgradeStatusDownloaded,     // For nb,downloaded nb. Device firmware has been downloaded.
    WiserSmartDeviceUpgradeStatusTimeout         // Timeout. Upgrade timeout.
} WiserSmartDeviceUpgradeStatus;

#endif /* WiserSmartDeviceModelUtils_h */
