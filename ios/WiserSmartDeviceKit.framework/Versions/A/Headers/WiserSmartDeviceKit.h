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
// */
//#define WISER_CURRENT_GW_PROTOCOL_VERSION 2.2
//
///**
// *  当前客户端支持的最高的局域网通信协议
// */
//#define WISER_CURRENT_LAN_PROTOCOL_VERSION 3.4

#import <WiserSmartBaseKit/WiserSmartBaseKit.h>
#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

#if TARGET_OS_IOS
    #import <WiserSmartMQTTChannelKit/WiserSmartMQTTChannelKit.h>
    #import <WiserSmartSocketChannelKit/WiserSmartSocketChannelKit.h>
#elif TARGET_OS_WATCH
    #define WiserSmartMQTTChannelDelegate NSObject
    #define WiserSmartSocketChannelDelegate NSObject
#endif

#import "WiserSmartHome.h"
#import "WiserSmartHomeManager.h"
#import "WiserSmartHomeMember.h"
#import "WiserSmartHomeInvitation.h"
#import "WiserSmartRoom.h"
#import "WiserSmartHomeDeviceShare.h"

#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeMemberRequestModel.h"

#import "WiserSmartHome+WSDeprecatedApi.h"
#import "WiserSmartHomeMember+WSDeprecatedApi.h"

#import "WiserSmartGroup+DpCode.h"

#import "WiserSmartMultiControl.h"

#import "WiserSmartDeviceShareModel.h"
#import "WiserSmartHomeDeviceShare+WSDeprecatedApi.h"

#endif /* WiserSmartDeviceKit_h */
