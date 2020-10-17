//
//  WiserSmartHome+WSDeprecatedApi.h
//  WiserSmartDeviceKit
//
//
//

#import "WiserSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHome (WSDeprecatedApi)

/**
 *  Add a home member
 *  添加家庭成员 将会废弃
 *
 *  @param name         Member name
 *  @param headPic      Member portrait
 *  @param countryCode  Country code
 *  @param account      User account
 *  @param isAdmin      Whether the administrator
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                      isAdmin:(BOOL)isAdmin
                      success:(WSSuccessDict)success
                      failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartHome   addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure:]");

/**
 *  Add a home member
 *  添加家庭成员
 *
 *  @param name         Member name
 *  @param headPic      Member portrait
 *  @param countryCode  Country code
 *  @param account      User account
 *  @param role         home role type
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                         role:(WSHomeRoleType)role
                      success:(WSSuccessDict)success
                      failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartHome addHomeMemberWithAddMemeberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
