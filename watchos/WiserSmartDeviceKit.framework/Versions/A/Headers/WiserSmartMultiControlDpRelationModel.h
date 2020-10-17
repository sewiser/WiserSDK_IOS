//
//  WiserSmartMultiControlDpRelationModel.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMcGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *dpName;///< dp 名称
@property (copy, nonatomic) NSString *devId;///< 设备 id
@property (copy, nonatomic) NSString *devName;///< 设备名称
@property (assign, nonatomic) BOOL enabled;///< 是否可用
@property (copy, nonatomic) NSString *multiControlId;///< 多控组 id

@end


@interface WiserSmartMcGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< 多控组id
@property (copy, nonatomic) NSString *groupName;///< 多控组名称
@property (strong, nonatomic) NSArray<WiserSmartMcGroupDetailModel *> *groupDetail;///< 多控组关联详情

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< 多控组类型
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< 家庭id
@property (copy, nonatomic) NSString *uid;///< 用户id

@end


@interface WiserSmartMultiControlDpRelationModel : NSObject

@property (strong, nonatomic) NSArray<WiserSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<WiserSmartMcGroupModel *> *mcGroups;
@property (strong, nonatomic) NSArray<WiserSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
