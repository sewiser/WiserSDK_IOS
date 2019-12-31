//
//  WiserSmartShareDeviceModel.h
//  WiserSmartKitExample
//
//
//  Copyright © 2017年 tuya. All rights reserved.
//

@interface WiserSmartShareDeviceModel : NSObject

/**
 *  device icon url
 */
@property (nonatomic, strong) NSString *iconUrl;

/**
 *  devId
 */
@property (nonatomic, strong) NSString *devId;

/**
 *  名称(设备,群组)
 *  device name or group name
 */
@property (nonatomic, strong) NSString *name;

/**
 *  Whether or not to share
 */
@property (nonatomic, assign) BOOL share;

/**
 *  room name
 */
@property (nonatomic, strong) NSString *roomName;

/**
 *  home name
 */
@property (nonatomic, strong) NSString *homeName;






@end
