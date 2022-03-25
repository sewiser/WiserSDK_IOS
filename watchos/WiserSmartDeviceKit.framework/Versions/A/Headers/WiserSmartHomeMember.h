//
// WiserSmartHomeMember.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeMemberRequestModel.h"

@interface WiserSmartHomeMember : NSObject

#pragma mark - public


/// Remove a home member.
///
/// @param memberId    Member Id
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(WSSuccessHandler)success
                             failure:(WSFailureError)failure;



/// Update home member info
///
/// @param memberRequestModel request model, Set the corresponding property
/// @param success            Called when the task finishes successfully.
/// @param failure            If error occurred while adding the task, this block will be called.
- (void)updateHomeMemberInfoWithMemberRequestModel:(WiserSmartHomeMemberRequestModel *)memberRequestModel
                                           success:(WSSuccessHandler)success
                                           failure:(WSFailureError)failure;


/// Get a list of optional rooms.
/// @param homeID homeID
/// @param memberID member id
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
 - (void)getAuthRoomListWithHomeId:(long long)homeID
                         memberID:(long long)memberID
                          success:(WSSuccessList)success
                          failure:(WSFailureError)failure;

/// Get a list of optional scenes or automations.
/// @param homeID homeID
/// @param memberID member id
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getAuthSceneListWithHomeID:(long long)homeID
                          memberID:(long long)memberID
                           success:(WSSuccessList)success
                           failure:(WSFailureError)failure;


/// Update the list of rooms to which custom roles have access.
/// @param homeID homeID
/// @param memberID member id
/// @param roomIDs List of room IDs with permission.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
 - (void)saveAuthRoomListWithHomeId:(long long)homeID
                          memberID:(long long)memberID
                           roomIDs:(NSArray <NSNumber *> *)roomIDs
                           success:(WSSuccessID)success
                           failure:(WSFailureError)failure;


/// Update the list of scenes to which custom roles have access.
/// @param homeID homeID
/// @param memberID member id
/// @param ruleIDs List of scene IDs with permissions.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)saveAuthSceneListWithHomeId:(long long)homeID
                           memberID:(long long)memberID
                            ruleIDs:(NSArray <NSString *> *)ruleIDs
                            success:(WSSuccessID)success
                            failure:(WSFailureError)failure;

@end
