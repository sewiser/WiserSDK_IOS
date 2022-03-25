//
// WiserSmartShareMemberModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

@interface WiserSmartShareMemberModel : NSObject

/// Relationship Id
@property (nonatomic, assign) NSInteger memberId;

/// Remark name
@property (nonatomic, strong) NSString  *nickName;

/// User name (cell phone number/email number)
@property (nonatomic, strong) NSString  *userName;

/// Avatar address.
@property (nonatomic, strong) NSString *iconUrl;

@end
