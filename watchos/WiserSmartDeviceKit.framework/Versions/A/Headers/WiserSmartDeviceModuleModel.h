//
//  WiserSmartDeviceModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#ifndef WiserSmart_BleMeshSubDeviceModuleModel
#define WiserSmart_BleMeshSubDeviceModuleModel

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

#import <Foundation/Foundation.h>

@interface WiserSmartDeviceMcuModel : NSObject

@property (nonatomic, assign) BOOL     isOnline;
@property (nonatomic, strong) NSString *verSw;

@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceZigbeeModel : NSObject

@property (nonatomic, assign) BOOL     isOnline;
@property (nonatomic, strong) NSString *verSw;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceBluetoothModel : NSObject

@property (nonatomic, assign) BOOL          isOnline;
@property (nonatomic, strong) NSString      *verSw;
@property (nonatomic, strong) NSString      *pv;
@property (nonatomic, strong) NSString      *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceWifiModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *cadv;
@property (nonatomic, strong) NSString     *cdv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceInfraredModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *cadv;
@property (nonatomic, strong) NSString     *cdv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceGprsModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceSubpiecesModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

@interface WiserSmartDeviceNBIoTModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) NSInteger    upgradeStatus;

@end

@interface WiserSmartDeviceModuleModel : NSObject

@property (nonatomic, strong) WiserSmartDeviceWifiModel           *wifi;
@property (nonatomic, strong) WiserSmartDeviceNBIoTModel          *nbIot;
@property (nonatomic, strong) WiserSmartDeviceBluetoothModel      *bluetooth;
@property (nonatomic, strong) WiserSmartDeviceMcuModel            *mcu;
@property (nonatomic, strong) WiserSmartDeviceGprsModel           *gprs;
@property (nonatomic, strong) WiserSmartDeviceZigbeeModel         *zigbee;
@property (nonatomic, strong) WiserSmartDeviceInfraredModel       *infrared;
@property (nonatomic, strong) WiserSmartDeviceSubpiecesModel      *subpieces;


@end


#endif
