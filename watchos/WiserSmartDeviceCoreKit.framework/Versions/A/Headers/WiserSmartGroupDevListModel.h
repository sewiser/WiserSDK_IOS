//
// WSGroupDevList.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartGroupDevListModel
#define WiserSmart_WiserSmartGroupDevListModel

#import <Foundation/Foundation.h>

/// group device list information
@interface WiserSmartGroupDevListModel : NSObject


/// The device ID.
@property(nonatomic,strong) NSString    *devId;

/// The device ID.
@property(nonatomic,strong) NSString    *gwId;

/// Is the device online.
@property(nonatomic,assign) BOOL        online;

/// Device icon URL.
@property(nonatomic,strong) NSString    *iconUrl;

/// The product ID.
@property(nonatomic,strong) NSString    *productId;

/// Is the device selected.
@property(nonatomic,assign) BOOL        checked;

/// The device name.
@property(nonatomic,strong) NSString    *name;

/// The device address.
@property(nonatomic,strong) NSString    *nodeId;


@end

#endif

