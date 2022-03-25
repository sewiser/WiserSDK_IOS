//
// WiserSmartHomeDeviceShare.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <UIKit/UIKit.h>
#import "WiserSmartShareMemberModel.h"
#import "WiserSmartShareMemberDetailModel.h"
#import "WiserSmartReceiveMemberDetailModel.h"
#import "WiserSmartReceivedShareUserModel.h"
#import "WiserSmartShareDeviceModel.h"
#import "WiserSmartDeviceShareModel.h"


/// Sharing device related functions (based on device dimension sharing).
@interface WiserSmartHomeDeviceShare : NSObject

/// Device add sharing.
/// @param requestModel Adding a shared device model
/// @param success Called when the task finishes successfully. WiserSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addDeviceShareWithRequestModel:(WiserSmartDeviceShareRequestModel *)requestModel
                               success:(void(^)(WiserSmartShareMemberModel *model))success
                               failure:(WSFailureError)failure;


/// Add Share (New, does not overwrite old share)
/// @param memberId memberId
/// @param devIds devId list
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addShareWithMemberId:(NSInteger)memberId
                      devIds:(NSArray <NSString *> *)devIds
                     success:(WSSuccessHandler)success
                     failure:(WSFailureError)failure;


/// Get a list of all users actively sharing under family.
/// @param homeId homeId
/// @param success Called when the task finishes successfully. A list of WiserSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareMemberListWithHomeId:(long long)homeId
                             success:(void(^)(NSArray<WiserSmartShareMemberModel *> *list))success
                             failure:(WSFailureError)failure;


/// Get a list of all users who have received a share.
/// @param success Called when the task finishes successfully. A list of WiserSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getReceiveMemberListWithSuccess:(void(^)(NSArray<WiserSmartShareMemberModel *> *list))success
                                failure:(WSFailureError)failure;


/// Get the shared data of a single active share user.
/// @param memberId memberId
/// @param success Called when the task finishes successfully. WiserSmartShareMemberDetailModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareMemberDetailWithMemberId:(NSInteger)memberId
                                 success:(void(^)(WiserSmartShareMemberDetailModel *model))success
                                 failure:(WSFailureError)failure;


/// Get the shared data of a single user who received a share.
/// @param memberId memberId
/// @param success Called when the task finishes successfully. WiserSmartShareMemberDetailModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getReceiveMemberDetailWithMemberId:(NSInteger)memberId
                                   success:(void(^)(WiserSmartReceiveMemberDetailModel *model))success
                                   failure:(WSFailureError)failure;



/// Remove active sharers.
/// @param memberId memberId
/// @param success  Called when the task finishes successfully.
/// @param failure  If error occurred while adding the task, this block will be called.
- (void)removeShareMemberWithMemberId:(NSInteger)memberId
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;


/// Remove received sharer
/// @param memberId Shared member ID.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeReceiveShareMemberWithMemberId:(NSInteger)memberId
                                     success:(WSSuccessHandler)success
                                     failure:(WSFailureError)failure;


/// Change the nickname of an active shared user.
/// @param memberId memberId
/// @param name nickname
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)renameShareMemberNameWithMemberId:(NSInteger)memberId
                                     name:(NSString *)name
                                  success:(WSSuccessHandler)success
                                  failure:(WSFailureError)failure;


/// Change the nickname of the person who received the share.
/// @param memberId memberId
/// @param name nickname
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)renameReceiveShareMemberNameWithMemberId:(NSInteger)memberId
                                            name:(NSString *)name
                                         success:(WSSuccessHandler)success
                                         failure:(WSFailureError)failure;


#pragma mark - 

/// Remove Received Shared.
/// @param devId   DevId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeReceiveDeviceShareWithDevId:(NSString *)devId
                                  success:(WSSuccessHandler)success
                                  failure:(WSFailureError)failure;


/// Delete shared devices.
/// @param memberId member ID
/// @param devId Device ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeDeviceShareWithMemberId:(NSInteger)memberId
                                devId:(NSString *)devId
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;


/// Get a list of device share users.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. A list of WiserSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getDeviceShareMemberListWithDevId:(NSString *)devId
                                  success:(void(^)(NSArray<WiserSmartShareMemberModel *> *list))success
                                  failure:(WSFailureError)failure;


/// Get users for device sharing.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. WiserSmartReceivedShareUserModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareInfoWithDevId:(NSString *)devId
                      success:(void(^)(WiserSmartReceivedShareUserModel *model))success
                      failure:(WSFailureError)failure;


/// Invitation to share to other users
/// @param countryCode countryCode
/// @param userAccount userAccount
/// @param devId Device ID.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)inviteShareWithCountryCode:(NSString *)countryCode
                       userAccount:(NSString *)userAccount
                             devId:(NSString *)devId
                           success:(WSSuccessInt)success
                           failure:(WSFailureError)failure;


/// Confirm invite share.
/// @param shareId The shareId returned by the invite share interface.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)confirmInviteShareWithShareId:(NSInteger)shareId
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;

#pragma mark - Group Share

/// Get a list of shared users for a single group (reflected in the panel).
/// @param groupId groupId
/// @param success Called when the task finishes successfully. A list of WiserSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getGroupShareMemberListWithGroupId:(NSString *)groupId
                                   success:(void(^)(NSArray<WiserSmartShareMemberModel *> *list))success
                                   failure:(WSFailureError)failure;


/// Share groups to other users.
/// @param homeId HomeId
/// @param countryCode Country Code
/// @param userAccount User Account
/// @param groupId GroupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addGroupShareToMemberWithHomeId:(long long)homeId
                             countyCode:(NSString *)countryCode
                            userAccount:(NSString *)userAccount
                                groupId:(NSString *)groupId
                                success:(WSSuccessID)success
                                failure:(WSFailureError)failure;


/// Get sharing information of the group.
/// @param groupId groupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareGroupFromInfoWithGroupId:(NSString *)groupId
                                 success:(WSSuccessID)success
                                 failure:(WSFailureError)failure;


/// Remove sharing groups.
/// @param groupId groupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeShareGroupWithGroupId:(NSString *)groupId
                            success:(WSSuccessID)success
                            failure:(WSFailureError)failure;


/// Remove group shares from other members.
/// @param relationId relationId
/// @param groupId groupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeGroupShareWithRelationId:(NSInteger)relationId
                               groupId:(NSString *)groupId
                               success:(WSSuccessHandler)success
                               failure:(WSFailureError)failure;

@end
