//
// WiserSmartDeviceCoreKit.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartDeviceCoreKit_h
#define WiserSmartDeviceCoreKit_h

/// @brief Header files for WiserSmartDeviceCoreKit.

/// The highest currently supported extranet communication protocol for clients.
#define WISER_CURRENT_GW_PROTOCOL_VERSION 2.2

/// Highest currently supported LAN communication protocol for clients.
#define WISER_CURRENT_LAN_PROTOCOL_VERSION 3.4

#import <WiserSmartBaseKit/WiserSmartBaseKit.h>

#if TARGET_OS_IOS
    #import <WiserSmartMQTTChannelKit/WiserSmartMQTTChannelKit.h>
    #import <WiserSmartSocketChannelKit/WiserSmartSocketChannelKit.h>

    #import "WiserSmartDevice+WiFiBackup.h"

#elif TARGET_OS_WATCH
    #define WiserSmartMQTTChannelDelegate NSObject
    #define WiserSmartSocketChannelDelegate NSObject
#endif

#import "WiserSmartDevice.h"
#import "WiserSmartGroup.h"
#import "WiserSmartBleMeshModel.h"
#import "WiserSmartSingleTransfer.h"
#import "WSCoreCacheService.h"

#import "WiserSmartDevice+OfflineReminder.h"
#import "WiserSmartDeviceCoreKitErrors.h"
#import "WiserSmartDevice+OfflineReminder.h"
#import "WiserSmartCommunication.h"
#import "WiserSmartDeviceEventUtil.h"

#import "WiserSmartCommunication.h"

#endif /* WiserSmartDeviceCoreKit_h */
