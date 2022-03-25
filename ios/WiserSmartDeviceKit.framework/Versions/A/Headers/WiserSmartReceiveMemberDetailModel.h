//
// WiserSmartReceiveMemberDetailModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

@class WiserSmartShareDeviceModel;

@interface WiserSmartReceiveMemberDetailModel : NSObject

@property (nonatomic, strong) NSArray <WiserSmartShareDeviceModel *> *devices;

/// Account information, email or cell phone number.
@property (nonatomic, strong) NSString *mobile;

/// User nickname.
@property (nonatomic, strong) NSString *name;

/// Remarks.
@property (nonatomic, strong) NSString *remarkName;

@end
