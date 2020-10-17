//
//  WiserSmartDeviceModelUtils.h
//  WiserSmartDeviceKit
//
//
//

#ifndef WiserSmartDeviceModelUtils_h
#define WiserSmartDeviceModelUtils_h

typedef enum : NSUInteger {
    WiserSmartDeviceUpgradeStatusDefault = 0,    // default 默认不需要升级的
    WiserSmartDeviceUpgradeStatusReady,          // ready  硬件准备就绪
    WiserSmartDeviceUpgradeStatusUpgrading,      // upgrading  升级中
    WiserSmartDeviceUpgradeStatusSuccess,        // success  升级完成
    WiserSmartDeviceUpgradeStatusFailure,        // failure 升级异常
    WiserSmartDeviceUpgradeStatusWaitingExectue, // for nb, waiting exectue nb设备任务已下发，但还未执行
    WiserSmartDeviceUpgradeStatusDownloaded,     // for nb, downloaded nb设备固件已下载
    WiserSmartDeviceUpgradeStatusTimeout         // timeout 升级超时
} WiserSmartDeviceUpgradeStatus;

#endif /* WiserSmartDeviceModelUtils_h */
