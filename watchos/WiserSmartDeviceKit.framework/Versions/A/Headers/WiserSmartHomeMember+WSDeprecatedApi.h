//
// WiserSmartHomeMember+WSDeprecatedApi.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import "WiserSmartHomeMember.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHomeMember (WSDeprecatedApi)


/// Add a home member
///
/// @param homeId      Home Id
/// @param countryCode Country code
/// @param account     User account
/// @param name        Note name
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure: instead.
- (void)addHomeMemberWithHomeId:(long long)homeId
                    countryCode:(NSString *)countryCode
                        account:(NSString *)account
                           name:(NSString *)name
                        isAdmin:(BOOL)isAdmin
                        success:(WSSuccessHandler)success
                        failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartHome -  addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure:] instead");


/// Update home member info
///
/// @param memberId    Member Id
/// @param name        Note name
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::updateHomeMemberInfoWithMemberId:name:headPic:isAdmin:success:failure: instead.
- (void)updateHomeMemberNameWithMemberId:(long long)memberId
                                    name:(NSString *)name
                                 isAdmin:(BOOL)isAdmin
                                 success:(WSSuccessHandler)success
                                 failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartHomeMember - (void)updateHomeMemberInfoWithMemberId:name:headPic:isAdmin:success:failure:] instead");


/// Add family members.
/// @param groupId Home Group ID
/// @param name Family member's name
/// @param headPic Family member avatar
/// @param countryCode Country code.
/// @param account User account.
/// @param admin Whether is the administrator.
/// @param success Success block
/// @param failure Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure: instead.
- (void)addHomeMemberWithHomeId:(long long)groupId
                           name:(NSString *)name
                        headPic:(UIImage *)headPic
                    countryCode:(NSString *)countryCode
                    userAccount:(NSString *)account
                        isAdmin:(BOOL)admin
                        success:(WSSuccessDict)success
                        failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartHome -  addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure:] instead");



/// Get home member list
///
/// @param homeId      Home Id
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::getHomeMemberListWithSuccess:failure: instead.
- (void)getHomeMemberListWithHomeId:(long long)homeId
                            success:(void(^)(NSArray <WiserSmartHomeMemberModel *> *memberList))success
                            failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartHome - (void)getHomeMemberListWithSuccess:failure:] instead");



/// Update home member info
///
/// @param memberId    Member Id
/// @param name        Note name
/// @param headPic     Portrait
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberInfoWithMemberId:(long long)memberId
                                    name:(NSString *)name
                                 headPic:(UIImage *)headPic
                                 isAdmin:(BOOL)isAdmin
                                 success:(WSSuccessHandler)success
                                 failure:(WSFailureError)failure  __deprecated_msg("This method will be deprecated and remove, Use [WiserSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Update home member note name
///
/// @param memberId    Member Id
/// @param name        Note name
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberRemarkNameWithMemberId:(long long)memberId
                                          name:(NSString *)name
                                       isAdmin:(BOOL)isAdmin
                                       success:(WSSuccessHandler)success
                                       failure:(WSFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [WiserSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Update home member portrait
///
/// @param memberId    Member Id
/// @param headPic     Portrait
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberHeadPicWithMemberId:(long long)memberId
                                    headPic:(UIImage *)headPic
                                    isAdmin:(BOOL)isAdmin
                                    success:(WSSuccessHandler)success
                                    failure:(WSFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [WiserSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Update home member management authority
///
/// @param memberId    Member Id
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberAdminWithMemberId:(long long)memberId
                                  isAdmin:(BOOL)isAdmin
                                  success:(WSSuccessHandler)success
                                  failure:(WSFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [WiserSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
