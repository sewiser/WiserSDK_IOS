//
//  WiserSmartMultiControl.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlLinkModel.h"
#import "WiserSmartMultiControlModel.h"
#import "WiserSmartMultiControlDpRelationModel.h"
#import "WiserSmartMultiControlDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControl : NSObject

/**
 * 查询设备下 dp 按键关联的多控和自动化
 *
 * @param devId 设备id
 * @param dpId 数据点id
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)queryDeviceLinkInfoWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                             success:(void (^)(WiserSmartMultiControlLinkModel *))success
                             failure:(WSFailureError)failure;

/**
 * 新增多控组
 *
 * @param devId 主设备id
 * @param groupName 多控组名称
 * @param groupDetail 多控组关联详情
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)addMultiControlWithDevId:(NSString *)devId
                       groupName:(NSString *)groupName
                     groupDetail:(NSArray<WiserSmartMultiControlDetailModel *> *)groupDetail
                         success:(void (^)(WiserSmartMultiControlModel *))success
                         failure:(WSFailureError)failure;

/**
 * 更新多控组
 *
 * @param devId 主设备id
 * @param model 多控组数据模型
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)updateMultiControlWithDevId:(NSString *)devId
                  multiControlModel:(WiserSmartMultiControlModel *)model
                            success:(void (^)(WiserSmartMultiControlModel *))success
                            failure:(WSFailureError)failure;

/**
 * 获取附属设备的 dp 点信息、已关联的多控、场景自动化信息
 *
 * @param devId 设备id
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)queryDeviceDpRelationWithDevId:(NSString *)devId
                               success:(void (^)(WiserSmartMultiControlDpRelationModel *))success
                               failure:(WSFailureError)failure;

/**
 * 启用或停用多控组
 *
 * @param multiControlId 多控组 Id
 * @param enable 启用或停用
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)enableMultiControlWithMultiControlId:(NSString *)multiControlId
                                      enable:(BOOL)enable
                                     success:(WSSuccessBOOL)success
                                     failure:(WSFailureError)failure;

/**
 * 查询支持执行动作的设备ID列表及设备群组列表(包括用户的和家庭的)
 *
 * @param homeId 家庭 Id
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)getMultiControlDeviceListWithHomeId:(long long)homeId
                                    success:(void (^)(NSArray<WiserSmartMultiControlDeviceModel *> *))success
                                    failure:(WSFailureError)failure;

/**
 * 获取设备下所有 dp 点信息
 *
 * @param devId 设备id
 * @param success 成功回调
 * @param failure 失败回调
 */
- (void)getDeviceDpInfoWithDevId:(NSString *)devId
                         success:(void (^)(NSArray<WiserSmartMultiControlDatapointModel *> *))success
                         failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
