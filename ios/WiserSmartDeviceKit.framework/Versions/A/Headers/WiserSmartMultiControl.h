//
// WiserSmartMultiControl.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlLinkModel.h"
#import "WiserSmartMultiControlModel.h"
#import "WiserSmartMultiControlDpRelationModel.h"
#import "WiserSmartMultiControlDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControl : NSObject

/// Query the multiple controls and automation associated with the dp button under the device.
/// @param devId Main device ID.
/// @param dpId DP ID.
/// @param success Called when the task finishes successfully. WiserSmartMultiControlLinkModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceLinkInfoWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                             success:(void (^)(WiserSmartMultiControlLinkModel *))success
                             failure:(WSFailureError)failure;

/// Adding a multi-control group.
/// @param devId Main device ID.
/// @param groupName The group name.
/// @param groupDetail Multi-control group association details.
/// @param success Called when the task finishes successfully. WiserSmartMultiControlModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addMultiControlWithDevId:(NSString *)devId
                       groupName:(NSString *)groupName
                     groupDetail:(NSArray<WiserSmartMultiControlDetailModel *> *)groupDetail
                         success:(void (^)(WiserSmartMultiControlModel *))success
                         failure:(WSFailureError)failure;

//// Update multi-Control group.
/// @param devId Main device ID.
/// @param model Multi-control group data model.
/// @param success Called when the task finishes successfully. WiserSmartMultiControlModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMultiControlWithDevId:(NSString *)devId
                  multiControlModel:(WiserSmartMultiControlModel *)model
                            success:(void (^)(WiserSmartMultiControlModel *))success
                            failure:(WSFailureError)failure;

/// Get dp point information of attached devices, associated multi-control, scene automation information.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. WiserSmartMultiControlDpRelationModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceDpRelationWithDevId:(NSString *)devId
                               success:(void (^)(WiserSmartMultiControlDpRelationModel *))success
                               failure:(WSFailureError)failure;


/// Enable or disable multiple control groups.
/// @param multiControlId Multi-control group ID.
/// @param enable A boolean value indicates whether to enable or disable the group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)enableMultiControlWithMultiControlId:(NSString *)multiControlId
                                      enable:(BOOL)enable
                                     success:(WSSuccessBOOL)success
                                     failure:(WSFailureError)failure;


/// Query the list of device IDs and the list of device groups (including user's and family's) that support performing actions.
/// @param homeId The home ID.
/// @param success Called when the task finishes successfully. A list of WiserSmartMultiControlDeviceModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiControlDeviceListWithHomeId:(long long)homeId
                                    success:(void (^)(NSArray<WiserSmartMultiControlDeviceModel *> *))success
                                    failure:(WSFailureError)failure;


/// Get information about all dp points under the device.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. A list of WiserSmartMultiControlDatapointModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceDpInfoWithDevId:(NSString *)devId
                         success:(void (^)(NSArray<WiserSmartMultiControlDatapointModel *> *))success
                         failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
