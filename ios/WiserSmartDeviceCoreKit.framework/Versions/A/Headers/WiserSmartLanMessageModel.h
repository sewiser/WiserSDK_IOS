//
// WiserSmartLanMessageModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// local network message
@interface WiserSmartLanMessageModel : NSObject

/// protocol
@property (nonatomic, assign) NSInteger    protocol;

/// device ID
@property (nonatomic, strong) NSString     *devId;

/// message body
@property (nonatomic, strong) NSDictionary *body;

/// message data
@property (nonatomic, strong) NSData       *data;

@end

NS_ASSUME_NONNULL_END
