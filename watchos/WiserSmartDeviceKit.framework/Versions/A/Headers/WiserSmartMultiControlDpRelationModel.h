//
// WiserSmartMultiControlDpRelationModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMcGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *dpName;///< dp name
@property (copy, nonatomic) NSString *devId;///< device id
@property (copy, nonatomic) NSString *devName;///< Device name.
@property (assign, nonatomic) BOOL enabled;///< Availability.
@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.

@end


@interface WiserSmartMcGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.
@property (copy, nonatomic) NSString *groupName;///< Multi-control group name.
@property (strong, nonatomic) NSArray<WiserSmartMcGroupDetailModel *> *groupDetail;///< Multi-control group association details.

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< Multi-control group type.
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< Family ID.
@property (copy, nonatomic) NSString *uid;///< User ID.

@end


@interface WiserSmartMultiControlDpRelationModel : NSObject

@property (strong, nonatomic) NSArray<WiserSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<WiserSmartMcGroupModel *> *mcGroups;
@property (strong, nonatomic) NSArray<WiserSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
