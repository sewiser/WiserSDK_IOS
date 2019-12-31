//
//  WiserSmartGroupModel.h
//  WiserSmartPublic
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartGroupModel
#define WiserSmart_WiserSmartGroupModel

typedef enum : NSUInteger {
    WiserSmartGroupTypeWifi = 0,
    WiserSmartGroupTypeMesh,
    WiserSmartGroupTypeZigbee,
    WiserSmartGroupTypeSIGMesh,
} WiserSmartGroupType;

#import <Foundation/Foundation.h>
#import "WiserSmartDevice.h"

@interface WiserSmartGroupModel : NSObject

// group Id
@property (nonatomic, strong) NSString  *groupId;

// product Id
@property (nonatomic, strong) NSString  *productId;

// group creation time
@property (nonatomic, assign) long long    time;

// name of group
@property (nonatomic, strong) NSString  *name;

// iconUrl
@property (nonatomic, strong) NSString  *iconUrl;

// type of group
@property (nonatomic, assign) WiserSmartGroupType  type;

@property (nonatomic, assign) BOOL      isShare;

// dps
@property (nonatomic, strong) NSDictionary *dps;

// dpCodes
@property (nonatomic, strong) NSDictionary *dpCodes;

// localKey
@property (nonatomic, strong) NSString     *localKey;

// pv
@property (nonatomic, assign) float        pv;

// deviceNum
@property (nonatomic, assign) NSInteger    deviceNum;

// productInfo
@property (nonatomic, strong) NSDictionary *productInfo;

// homeId
@property (nonatomic, assign) long long    homeId;

// roomId
@property (nonatomic, assign) long long    roomId;

// customize DP name
@property (nonatomic, copy)   NSDictionary *dpName;

// order
@property (nonatomic, assign) NSInteger displayOrder;

// home all group order
@property (nonatomic, assign) NSInteger homeDisplayOrder;

// device list
@property (nonatomic, strong) NSArray<WiserSmartDeviceModel *> *deviceList;

// local Short Address of Groups
@property (nonatomic, strong) NSString     *localId;

// subclass
@property (nonatomic, strong) NSString     *pcc;

// meshId or gwId
@property (nonatomic, strong) NSString     *meshId;

// schema array
@property (nonatomic, strong) NSArray      *schemaArray;

// is standard dp code
@property (nonatomic, assign) BOOL         standard;

@end

#endif
