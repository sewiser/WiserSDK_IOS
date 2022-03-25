//
// WiserSmartShareMemberDetailModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

@class WiserSmartShareDeviceModel;

@interface WiserSmartShareMemberDetailModel : NSObject

/// deviceModel list
@property (nonatomic, strong) NSArray <WiserSmartShareDeviceModel *> *devices;

/// mobile
@property (nonatomic, strong) NSString *mobile;

/// name
@property (nonatomic, strong) NSString *name;

/// remark name
@property (nonatomic, strong) NSString *remarkName;

/// auto sharing
@property (nonatomic, assign) BOOL autoSharing;


@end
