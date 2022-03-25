//
// WiserSmartHome+WSDeprecatedApi.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import "WiserSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHome (WSDeprecatedApi)


/// Add a home member
///
/// @param name         Member name
/// @param headPic      Member portrait
/// @param countryCode  Country code
/// @param account      User account
/// @param isAdmin      Whether the administrator
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                      isAdmin:(BOOL)isAdmin
                      success:(WSSuccessDict)success
                      failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartHome   addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure:]");

/// Add a home member
///
/// @param name         Member name
/// @param headPic      Member portrait
/// @param countryCode  Country code
/// @param account      User account
/// @param role         home role type
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::addHomeMemberWithAddMemeberRequestModel:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                         role:(WSHomeRoleType)role
                      success:(WSSuccessDict)success
                      failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartHome addHomeMemberWithAddMemeberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
