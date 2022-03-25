//
// WiserSmartHomeDeviceShare+WSDeprecatedApi.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import "WiserSmartHomeDeviceShare.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHomeDeviceShare (WSDeprecatedApi)

/// Add Sharing
/// @param homeId homeId
/// @param countryCode countryCode
/// @param userAccount userAccount
/// @param devIds devId list
/// @param success Success block
/// @param failure Failure block
/// @deprecated This method is deprecated, Use WiserSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addShareWithHomeId:(long long)homeId
               countryCode:(NSString *)countryCode
               userAccount:(NSString *)userAccount
                    devIds:(NSArray <NSString *> *)devIds
                   success:(void(^)(WiserSmartShareMemberModel *model))success
                   failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");


/// Single device add share
/// @param homeId homeId
/// @param countryCode countryCode
/// @param userAccount userAccount
/// @param devId devId
/// @param success Success block
/// @param failure Failure block
/// @deprecated This method is deprecated, Use WiserSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addDeviceShareWithHomeId:(long long)homeId
                     countryCode:(NSString *)countryCode
                     userAccount:(NSString *)userAccount
                           devId:(NSString *)devId
                         success:(void(^)(WiserSmartShareMemberModel *model))success
                         failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
