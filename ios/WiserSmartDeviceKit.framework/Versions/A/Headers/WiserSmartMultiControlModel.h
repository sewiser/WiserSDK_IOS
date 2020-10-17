//
//  WiserSmartMultiControlModel.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *devId;///< 附属设备 id
@property (copy, nonatomic) NSString *dpId;///< 已关联的附属设备的 dp id
@property (assign, nonatomic) BOOL enable;///< 已关联的附属设备是否可以通过多控功能控制

@end


@interface WiserSmartMultiControlModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< 多控组 id
@property (copy, nonatomic) NSString *groupName;///< 多控组名称
@property (strong, nonatomic) NSArray<WiserSmartMultiControlDetailModel *> *groupDetail;

@property (assign, nonatomic, readonly) NSInteger groupType;///< 多控组类型。默认为 1
@property (copy, nonatomic, readonly) NSString *ownerId;///< 家庭id
@property (copy, nonatomic, readonly) NSString *uid;///< 用户id

@end

NS_ASSUME_NONNULL_END
