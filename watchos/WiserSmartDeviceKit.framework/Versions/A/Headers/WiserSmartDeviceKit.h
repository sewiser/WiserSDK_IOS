//
// WiserSmartDeviceKit.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartDeviceKit_h
#define WiserSmartDeviceKit_h

/// The highest currently supported extranet communication protocol for clients.
//#define WISER_CURRENT_GW_PROTOCOL_VERSION 2.2

/// Highest currently supported LAN communication protocol for clients.
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
#import "WiserSmartHome+Weather.h"
#import "WiserSmartHome+WSDeprecatedApi.h"
#import "WiserSmartWeatherModel.h"
#import "WiserSmartWeatherOptionModel.h"
#import "WiserSmartWeatherSketchModel.h"

#import "WiserSmartHomeManager.h"
#import "WiserSmartHomeMember.h"
#import "WiserSmartHomeInvitation.h"
#import "WiserSmartRoom.h"
#import "WiserSmartHomeDeviceShare.h"

#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeMemberRequestModel.h"
#import "WiserSmartHomeMember+WSDeprecatedApi.h"

#import "WiserSmartGroup+DpCode.h"

#import "WiserSmartMultiControl.h"

#import "WiserSmartDeviceShareModel.h"
#import "WiserSmartHomeDeviceShare+WSDeprecatedApi.h"

#import "WiserSmartDevice+Home.h"
#import "WiserSmartDeviceModel+Home.h"
#import "WiserSmartGroup+Home.h"

#import "WiserSmartHome+BleMesh.h"
#import "WiserSmartHome+SIGMesh.h"

#endif /* WiserSmartDeviceKit_h */
