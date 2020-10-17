//
//  WiserSmartDeviceCoreKit.h
//  WiserSmartDeviceCoreKit
//
//
//

#ifndef WiserSmartDeviceCoreKit_h
#define WiserSmartDeviceCoreKit_h

/**
 *  当前客户端支持的最高的外网通信协议
 */
#define WISER_CURRENT_GW_PROTOCOL_VERSION 2.2

/**
 *  当前客户端支持的最高的局域网通信协议
 */
#define WISER_CURRENT_LAN_PROTOCOL_VERSION 3.4

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
#import "WiserSmartBleMeshModel.h"
#import "WiserSmartSingleTransfer.h"
#import "WSCoreCacheService.h"

#endif /* WiserSmartDeviceCoreKit_h */
