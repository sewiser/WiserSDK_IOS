//
//  WiserSmartMultiControlDeviceModel.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlDeviceModel : NSObject

@property (copy, nonatomic) NSString *devId;///< 设备 id
@property (copy, nonatomic) NSString *productId;///< 产品 id
@property (copy, nonatomic) NSString *name;///< 设备名称
@property (copy, nonatomic) NSString *iconUrl;///< 设备图标下载链接
@property (copy, nonatomic) NSString *roomName;///< 所在房间名
@property (assign, nonatomic) BOOL inRule;///< 该设备是否在自动化的条件中
@property (strong, nonatomic) NSArray<WiserSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<NSString *> *multiControlIds;///< 设备已被关联的多控组 id 数组

@end

NS_ASSUME_NONNULL_END
