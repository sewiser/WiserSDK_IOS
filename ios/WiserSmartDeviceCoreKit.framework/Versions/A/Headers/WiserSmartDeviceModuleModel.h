//
//  WiserSmartDeviceModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#ifndef WiserSmart_BleMeshSubDeviceModuleModel
#define WiserSmart_BleMeshSubDeviceModuleModel

#import <Foundation/Foundation.h>
#import "WiserSmartDeviceModelUtils.h"

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
