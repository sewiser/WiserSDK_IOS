//
// WiserSmartMultiControlDeviceModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlDeviceModel : NSObject

@property (copy, nonatomic) NSString *devId;///< Device ID.
@property (copy, nonatomic) NSString *productId;///< Product ID.
@property (copy, nonatomic) NSString *name;///< Device name.
@property (copy, nonatomic) NSString *iconUrl;///< Device Icon download link.
@property (copy, nonatomic) NSString *roomName;///< Room name.
@property (assign, nonatomic) BOOL inRule;///< A boolean value indicates whether the device in an automated condition.
@property (strong, nonatomic) NSArray<WiserSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<NSString *> *multiControlIds;///< Multiple control group ID arrays that the device has been associated with.

@end

NS_ASSUME_NONNULL_END
