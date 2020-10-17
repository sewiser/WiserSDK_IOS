//
//  WiserSmartHomeMember.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeMemberRequestModel.h"

@interface WiserSmartHomeMember : NSObject

#pragma mark - public

/**
 *  Remove a home member
 *  删除家庭成员
 *
 *  @param memberId    Member Id
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(WSSuccessHandler)success
                             failure:(WSFailureError)failure;


/**
 Update home member info
 修改家庭成员信息

 @param memberRequestModel request model, Set the corresponding property
 @param success            success callback
 @param failure            failure callcack
 */
- (void)updateHomeMemberInfoWithMemberRequestModel:(WiserSmartHomeMemberRequestModel *)memberRequestModel
                                           success:(WSSuccessHandler)success
                                           failure:(WSFailureError)failure;

/**
 *  获取可选的房间列表 fetch optional room list
 *  @param homeID homeID 家庭ID
 *  @param memberID member id 成员ID
 *  @param success success callback
 *  @param failure failure callback
 */
 - (void)getAuthRoomListWithHomeId:(long long)homeID
                         memberID:(long long)memberID
                          success:(WSSuccessList)success
                          failure:(WSFailureError)failure;
/**
 *  获取可选的场景或自动化列表 fetch optional scene list
 *  @param homeID homeID 家庭ID
 *  @param memberID member id 成员ID
 *  @param success success callback
 *  @param failure failure callback
 */
- (void)getAuthSceneListWithHomeID:(long long)homeID
                          memberID:(long long)memberID
                           success:(WSSuccessList)success
                           failure:(WSFailureError)failure;
/**
 *  更新自定义角色有权限的房间列表 update custom role have jurisdiction rooms
 *  @param homeID homeID 家庭ID
 *  @param memberID member id 成员ID
 *  @param roomIDs 有权限的房间ID列表 have jurisdiction room id list
 *  @param success success callback
 *  @param failure failure callback
 */
 - (void)saveAuthRoomListWithHomeId:(long long)homeID
                          memberID:(long long)memberID
                           roomIDs:(NSArray <NSNumber *> *)roomIDs
                           success:(WSSuccessID)success
                           failure:(WSFailureError)failure;

/**
 *  更新自定义角色有权限的的场景列表 update custom role have jurisdiction rule list
 *  @param homeID homeID 家庭ID
 *  @param memberID member id 成员ID
 *  @param ruleIDs 有权限的场景ID列表 have jurisdiction rule id list
 *  @param success success callback
 *  @param failure failure callback
 */
- (void)saveAuthSceneListWithHomeId:(long long)homeID
                           memberID:(long long)memberID
                            ruleIDs:(NSArray <NSString *> *)ruleIDs
                            success:(WSSuccessID)success
                            failure:(WSFailureError)failure;

@end
