//
//  WiserSmartMultiControlLinkModel.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *multiControlId;///< 多控组id
@property (copy, nonatomic) NSString *devId;///< 附属设备 id
@property (copy, nonatomic) NSString *devName;///< 附属设备名称
@property (copy, nonatomic) NSString *dpId;///< 已关联的附属设备的 dp id
@property (copy, nonatomic) NSString *dpName;///< 已关联的附属设备的 dp 名称
@property (assign, nonatomic) BOOL enabled;///< 已关联的附属设备是否可以通过多控功能控制
@property (strong, nonatomic) NSArray<WiserSmartMultiControlDatapointModel *> *datapoints;

@end


@interface WiserSmartMultiControlGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< 多控组id
@property (copy, nonatomic) NSString *groupName;///< 多控组名称
@property (strong, nonatomic) NSArray<WiserSmartMultiControlGroupDetailModel *> *groupDetail;///< 多控组详情

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< 多控组类型
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< 家庭id
@property (copy, nonatomic) NSString *uid;///< 用户id

@end


@interface WiserSmartMultiControlLinkModel : NSObject

@property (strong, nonatomic) WiserSmartMultiControlGroupModel *multiGroup;
@property (strong, nonatomic) NSArray<WiserSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
