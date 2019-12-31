//
//  WiserSmartDeviceKit.h
//  WiserSmartDeviceKit
//
//
//

#ifndef WiserSmartDeviceKit_h
#define WiserSmartDeviceKit_h

/**
 *  当前客户端支持的最高的外网通信协议
 */
#define TUYA_CURRENT_GW_PROTOCOL_VERSION 2.2

/**
 *  当前客户端支持的最高的局域网通信协议
 */
#define TUYA_CURRENT_LAN_PROTOCOL_VERSION 3.3

#import <WiserSmartBaseKit/WiserSmartBaseKit.h>

#if TARGET_OS_IOS
    #import <WiserSmartMQTTChannelKit/WiserSmartMQTTChannelKit.h>
    #import <WiserSmartSocketChannelKit/WiserSmartSocketChannelKit.h>
#elif TARGET_OS_WATCH
    #define WiserSmartMQTTChannelDelegate NSObject
    #define WiserSmartSocketChannelDelegate NSObject
#endif

#import "WiserSmartDevice.h"
#import "WiserSmartGroup.h"
#import "WiserSmartGroup+DpCode.h"
#import "WiserSmartHome.h"
#import "WiserSmartHomeManager.h"
#import "WiserSmartHomeMember.h"
#import "WiserSmartRoom.h"
#import "WiserSmartHomeDeviceShare.h"

#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeMemberRequestModel.h"
#import "WiserSmartBleMeshModel.h"
#import "WiserSmartSingleTransfer.h"

#endif /* WiserSmartDeviceKit_h */
