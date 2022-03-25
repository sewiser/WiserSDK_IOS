//
// WiserSmartDeviceModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_BleMeshSubDeviceModuleModel
#define WiserSmart_BleMeshSubDeviceModuleModel

#import <Foundation/Foundation.h>
#import "WiserSmartDeviceModelUtils.h"

/// mcu device
@interface WiserSmartDeviceMcuModel : NSObject

@property (nonatomic, assign) BOOL     isOnline;
@property (nonatomic, strong) NSString *verSw;

@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

/// zigbee device
@interface WiserSmartDeviceZigbeeModel : NSObject

@property (nonatomic, assign) BOOL     isOnline;
@property (nonatomic, strong) NSString *verSw;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

/// bluetooth device
@interface WiserSmartDeviceBluetoothModel : NSObject

@property (nonatomic, assign) BOOL          isOnline;
@property (nonatomic, strong) NSString      *verSw;
@property (nonatomic, strong) NSString      *pv;
@property (nonatomic, strong) NSString      *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

/// wifi device
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

/// infrared device
@interface WiserSmartDeviceInfraredModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *cadv;
@property (nonatomic, strong) NSString     *cdv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

/// gprs device
@interface WiserSmartDeviceGprsModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

/// subpieces device
@interface WiserSmartDeviceSubpiecesModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) WiserSmartDeviceUpgradeStatus upgradeStatus;

@end

/// nbiot device
@interface WiserSmartDeviceNBIoTModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) NSInteger    upgradeStatus;

@end

/// device module
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
