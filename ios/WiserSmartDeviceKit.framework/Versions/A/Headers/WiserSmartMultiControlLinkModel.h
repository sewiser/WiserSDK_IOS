//
// WiserSmartMultiControlLinkModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.
@property (copy, nonatomic) NSString *devId;///< Attachment device id.
@property (copy, nonatomic) NSString *devName;///< Name of attached device.
@property (copy, nonatomic) NSString *dpId;///< The dp id of the associated attached device.
@property (copy, nonatomic) NSString *dpName;///< The dp name of the associated attached device.
@property (assign, nonatomic) BOOL enabled;///< Whether affiliated devices that have been associated can be controlled by the multi-control function.
@property (strong, nonatomic) NSArray<WiserSmartMultiControlDatapointModel *> *datapoints;

@end


@interface WiserSmartMultiControlGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.
@property (copy, nonatomic) NSString *groupName;///< Multi-control group name.
@property (strong, nonatomic) NSArray<WiserSmartMultiControlGroupDetailModel *> *groupDetail;///< Multi-control group details.

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< Multi-control group type.
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< Family id.
@property (copy, nonatomic) NSString *uid;///< User id.

@end


@interface WiserSmartMultiControlLinkModel : NSObject

@property (strong, nonatomic) WiserSmartMultiControlGroupModel *multiGroup;
@property (strong, nonatomic) NSArray<WiserSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
