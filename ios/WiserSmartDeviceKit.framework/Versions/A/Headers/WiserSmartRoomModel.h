//
// WiserSmartRoomModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

@interface WiserSmartRoomModel : NSObject

// room Id
@property (nonatomic, assign) long long roomId;

// room icon
@property (nonatomic, strong) NSString *iconUrl;

// room name
@property (nonatomic, strong) NSString *name;

// order
@property (nonatomic, assign) NSInteger displayOrder;


@end
