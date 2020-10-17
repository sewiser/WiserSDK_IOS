//
//  TuysSmartDeviceModel.h
//  WiserSmartKit
//
//
//  Copyright (c) 2015年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartDeviceModel
#define WiserSmart_WiserSmartDeviceModel

#import "WiserSmartSchemaModel.h"
#import "WiserSmartDeviceModuleModel.h"
#import "WiserSmartStandSchemaModel.h"

typedef enum : NSUInteger {
    
    WiserSmartDeviceModelTypeWifiDev,         /// Wi-Fi
    
    WiserSmartDeviceModelTypeBle,             /// Single Point Bluetooth Device
    
    WiserSmartDeviceModelTypeGprs,            /// Gprs
    
    WiserSmartDeviceModelTypeNBIoT,           /// NB-IoT
    
    WiserSmartDeviceModelTypeZigbeeGateway,   /// Zigbee Gateway
    
    WiserSmartDeviceModelTypeZigbeeSubDev,    /// Zigbee subDevice
    
    WiserSmartDeviceModelTypeMeshBleSubDev,   /// Mesh
    
    WiserSmartDeviceModelTypeInfraredGateway, /// Infrared gateway
    
    WiserSmartDeviceModelTypeInfraredSubDev,  /// Infrared subDevice
    
    WiserSmartDeviceModelTypeWifiGateway,     /// Wi-Fi Gateway
    
    WiserSmartDeviceModelTypeWifiSubDev,      /// Wi-Fi subDevice
    
    WiserSmartDeviceModelTypeSIGMeshGateway,  /// SIG Mesh Gateway
    
    WiserSmartDeviceModelTypeSIGMeshSubDev,   /// SIG Mesh subDevice
    
} WiserSmartDeviceModelType;

@interface WiserSmartDeviceModel : NSObject

// device Id
@property (nonatomic, strong) NSString     *devId;

// name of device
@property (nonatomic, strong) NSString     *name;

// link of device icon
@property (nonatomic, strong) NSString     *iconUrl;

// ability of device
@property (nonatomic, assign) NSInteger    ability;

// online of device
@property (nonatomic, assign) BOOL         isOnline;

// cloud online of device
@property (nonatomic, assign) BOOL         isCloudOnline;

// whether the device is shared
@property (nonatomic, assign) BOOL         isShare;

//
@property (nonatomic, strong) NSString     *verSw;

// data point of device
@property (nonatomic, strong) NSDictionary *dps;

// data point execution time of device
@property (nonatomic, strong) NSDictionary *dpsTime;

// product Id
@property (nonatomic, strong) NSString     *productId;

// whether to support group
@property (nonatomic, assign) BOOL         supportGroup;

// whether to support standard group
@property (nonatomic, assign) BOOL         supportSGroup;

// type of gateway
@property (nonatomic, strong) NSString     *gwType;

// protocol version of gateway
@property (nonatomic, assign) double       pv;

#if TARGET_OS_IOS

// online status of LAN
@property (nonatomic, assign) BOOL         isLocalOnline;

// gateway protocol version of LAN
@property (nonatomic, assign) double       lpv;

#endif

// hardware baseline version
@property (nonatomic, assign) double       bv;

// lat, lon
@property (nonatomic, strong) NSString     *latitude;
@property (nonatomic, strong) NSString     *longitude;

// dp name
@property (nonatomic, strong) NSDictionary *dpName;

// schema of device
@property (nonatomic, strong) NSString     *schema;
@property (nonatomic, strong) NSString     *schemaExt;
@property (nonatomic, strong) NSArray<WiserSmartSchemaModel *> *schemaArray;

@property (nonatomic, strong) NSString     *runtimeEnv;

// attribute
@property (nonatomic, assign) NSUInteger    attribute;

@property (nonatomic, strong) NSString     *localKey;

@property (nonatomic, strong) NSString     *uuid;
// The network communication ability:0.wifi;1.cable;2.gprs;3.nb-iot; 10:bluetooth;11.blemesh;12.zigbee
@property (nonatomic, assign) NSUInteger   capability;

@property (nonatomic, strong) NSString     *timezoneId;

@property (nonatomic, assign) long long    homeId;
@property (nonatomic, assign) long long    roomId;
@property (nonatomic, assign) long long    sharedTime;

// order
@property (nonatomic, assign) NSInteger    displayOrder;
@property (nonatomic, assign) NSInteger    homeDisplayOrder;

@property (nonatomic, strong) NSString     *ip;

// skills
@property (nonatomic, strong) NSDictionary *skills;

@property (nonatomic, strong) NSString     *cloudId;

#pragma mark - panel

@property (nonatomic, assign) BOOL         rnFind;
@property (nonatomic, assign) long long    i18nTime;
@property (nonatomic, strong) NSString     *ui;
@property (nonatomic, strong) NSString     *uiId;
@property (nonatomic, strong) NSString     *uiVersion;
@property (nonatomic, strong) NSString     *uiPhase;
@property (nonatomic, strong) NSString     *uiType;
@property (nonatomic, strong) NSString     *uiName;
@property (nonatomic, strong) NSDictionary *uiConfig;
@property (nonatomic, strong) NSDictionary *panelConfig;
@property (nonatomic, strong) NSString     *category;
@property (nonatomic, strong) NSString     *categoryCode;
@property (nonatomic, strong) NSArray      *quickOpDps;
@property (nonatomic, strong) NSArray      *displayDps;
@property (nonatomic, strong) NSArray      *faultDps;
@property (nonatomic, strong) NSDictionary *displayMsgs;
@property (nonatomic, strong) NSString     *switchDp;

@property (nonatomic, assign) BOOL         isNewFirmware;
@property (nonatomic, assign) NSTimeInterval activeTime;
@property (nonatomic, assign) long         errorCode;

@property (nonatomic, assign) WiserSmartDeviceModelType deviceType;
@property (nonatomic, assign) BOOL         upgrading;

@property (nonatomic, strong) NSDictionary *originJson;

@property (nonatomic, strong) WiserSmartDeviceModuleModel *moduleMap;

- (BOOL)attributeIsSupport:(NSUInteger)i;
- (BOOL)capabilityIsSupport:(NSUInteger)i;
- (BOOL)devAttributeIsSupport:(NSUInteger)i;

#pragma mark - subdevice
// node Id
@property (nonatomic, strong) NSString     *nodeId;
@property (nonatomic, strong) NSString     *parentId;

// mesh
@property (nonatomic, strong) NSString     *vendorInfo;
@property (nonatomic, assign) BOOL         isMeshBleOnline;
@property (nonatomic, strong) NSString     *pcc;

#pragma mark - discovery device
// mark:  0: 1<<0 auto  3：1<<3 route
@property (nonatomic, assign) NSUInteger devAttribute;

// sig mesh dev key
@property (nonatomic, strong) NSString     *devKey;

/// 是否标准化
@property (nonatomic, assign) BOOL standard;
@property (nonatomic, strong) WiserSmartStandSchemaModel *standSchemaModel;

// dpCodes
@property (nonatomic, strong, readonly) NSDictionary *dpCodes;

@end

#endif
