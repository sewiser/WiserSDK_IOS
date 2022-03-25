//
// WiserSmartMultiControlModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *devId;///< Attachment device id.
@property (copy, nonatomic) NSString *dpId;///< The dp id of the associated attached device.
@property (assign, nonatomic) BOOL enable;///< Whether affiliated devices that have been associated can be controlled by the multi-control function.

@end


@interface WiserSmartMultiControlModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.
@property (copy, nonatomic) NSString *groupName;///< Multi-control group name.
@property (strong, nonatomic) NSArray<WiserSmartMultiControlDetailModel *> *groupDetail;

@property (assign, nonatomic, readonly) NSInteger groupType;///< Multi-control group type. Default is 1.
@property (copy, nonatomic, readonly) NSString *ownerId;///< Family id.
@property (copy, nonatomic, readonly) NSString *uid;///< User id.

@end

NS_ASSUME_NONNULL_END
