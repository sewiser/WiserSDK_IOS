//
// WiserSmartHomeInvitation.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHomeInvitation : NSObject

/// Invite new members by invitation code.
/// @param createRequestModel The request model.
/// @param success Called when the task finishes successfully. WiserSmartHomeInvitationResultModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createInvitationWithCreateRequestModel:(WiserSmartHomeInvitationCreateRequestModel *)createRequestModel
                                       success:(void(^)(WiserSmartHomeInvitationResultModel *invitationResultModel))success
                                       failure:(WSFailureError)failure;

/// Cancel invitation.
/// @param invitationID invitation ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)cancelInvitationWithInvitationID:(NSNumber *)invitationID
                                 success:(WSSuccessBOOL)success
                                 failure:(WSFailureError)failure;

/// Re-invite members.
/// @param reinviteRequestModel The re-invite request model.
/// @param success Called when the task finishes successfully. WiserSmartHomeInvitationResultModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)reinviteInvitationWithReinviteRquestModel:(WiserSmartHomeInvitationReinviteRequestModel *)reinviteRequestModel
                                          success:(void(^)(WiserSmartHomeInvitationResultModel *invitationResultModel))success
                                          failure:(WSFailureError)failure;

/// Get invitation record list information.
/// @param homeID homeID
/// @param success Called when the task finishes successfully. A list of WiserSmartHomeInvitationRecordModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchInvitationRecordListWithHomeID:(long long)homeID
                                    success:(void(^)(NSArray<WiserSmartHomeInvitationRecordModel *> *invitationRecordList))success
                                    failure:(WSFailureError)failure;

/// Update invitation information.
/// @param invitationInfoRequestModel The invitation info request model.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateInvitationInfoWithInvitationInfoRequestModel:(WiserSmartHomeInvitationInfoRequestModel *)invitationInfoRequestModel
                                                   success:(WSSuccessBOOL)success
                                                   failure:(WSFailureError)failure;


/// Get family information of the invitee.
/// @param invitationCode The invitation code.
/// @param success Called when the task finishes successfully. WiserSmartHomeModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchInvitationHomeInfoWithInvitationCode:(NSString *)invitationCode
                                          success:(void(^)(WiserSmartHomeModel *homeModel))success
                                          failure:(WSFailureError)failure;

/// Join the family.
/// @param invitationCode The invitation code.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)joinHomeWithInvitationCode:(NSString *)invitationCode
                           success:(WSSuccessBOOL)success
                           failure:(WSFailureError)failure;
@end

NS_ASSUME_NONNULL_END
