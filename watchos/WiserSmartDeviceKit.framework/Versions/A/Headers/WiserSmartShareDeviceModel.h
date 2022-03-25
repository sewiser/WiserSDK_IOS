//
// WiserSmartShareDeviceModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

@interface WiserSmartShareDeviceModel : NSObject

/// device icon url
@property (nonatomic, strong) NSString *iconUrl;

/// devId
@property (nonatomic, strong) NSString *devId;

/// device name or group name
@property (nonatomic, strong) NSString *name;

/// Whether or not to share
@property (nonatomic, assign) BOOL share;

/// room name
@property (nonatomic, strong) NSString *roomName;


/// home name
@property (nonatomic, strong) NSString *homeName;

@end
