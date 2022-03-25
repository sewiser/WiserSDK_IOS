//
// WiserSmartGroup+DpCode.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceCoreKit/WiserSmartGroup.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartGroup (DpCode)

#pragma mark - Wi-Fi dpCode

/// Creating Groups of Wifi Standard Code Devices.
///
/// @param name      Group name
/// @param homeId    Home ID
/// @param categoryCode category Code
/// @param devIdList DeviceId list
/// @param success   Success block
/// @param failure   Failure block
/// @deprecated This method is deprecated, Use WiserSmartGroup::createDpCodeGroupWithName:homeId:devIdList:success:failure: instead.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                     categoryCode:(NSString *)categoryCode
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(WiserSmartGroup *group))success
                          failure:(nullable WSFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use createDpCodeGroupWithName:homeId:devIdList:success:failure: instead");



/// Get list of Wi-Fi devices that support standard code groups based on category code.
///
/// @param homeId    Home ID
/// @param categoryCode category Code
/// @param success   Success block
/// @param failure   Failure block
/// @deprecated This method is deprecated, Use WiserSmartGroup::getDpCodeDevListWithHomeId:success:failure: instead.
+ (void)getDpCodeDevListWithHomeId:(long long)homeId
                      categoryCode:(NSString *)categoryCode
                           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
                           failure:(nullable WSFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use getDpCodeDevListWithHomeId:success:failure: instead");




/// Creating Groups of Wifi Standard Code Devices.
///
/// @param name      Group name
/// @param homeId    Home ID
/// @param devIdList DeviceId list
/// @param success   Called when the task finishes successfully. WiserSmartGroup will be returned.
/// @param failure   Called when the task is interrupted by an error.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(WiserSmartGroup *group))success
                          failure:(nullable WSFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use createDpCodeGroupWithName:homeId:productId:devIdList:success:failure: instead");


/// Create standard DPCode device group
///
/// @param name Group name
/// @param homeId Home ID
/// @param productId Product ID
/// @param devIdList DeviceId list
/// @param success Called when the task finishes successfully. WiserSmartGroup will be returned.
/// @param failure  Called when the task is interrupted by an error.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                        productId:(NSString *)productId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(WiserSmartGroup *group))success
                          failure:(nullable WSFailureError)failure;



/// Get list of WiFi devices that support standard code groups based on category code
///
/// @param homeId    Home ID
/// @param success   Called when the task finishes successfully. A list of WiserSmartGroupDevListModel will be returned.
/// @param failure   Called when the task is interrupted by an error.
+ (void)getDpCodeDevListWithHomeId:(long long)homeId
                           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
                           failure:(nullable WSFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use getDpCodeDevListWithHomeId:productId:success:failure: instead");

/// Get list of WiFi devices that support standard code groups based on category code
///
/// @param homeId Home ID
/// @param productId ProductId of device
/// @param success Called when the task finishes successfully. A list of WiserSmartGroupDevListModel will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDpCodeDevListWithHomeId:(long long)homeId
                         productId:(NSString *)productId
                           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
                           failure:(nullable WSFailureError)failure;


/// Get the device list for the group based.
///
/// @param success   Called when the task finishes successfully. A list of WiserSmartGroupDevListModel will be returned.
/// @param failure   Called when the task is interrupted by an error.
- (void)getDpCodeDevListWithSuccess:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
                            failure:(nullable WSFailureError)failure;



/// Modify the device list of the group.
///
/// @param devList Device list
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateDpCodeGroupRelationsWithDevList:(NSArray <NSString *>*)devList
                                      success:(nullable WSSuccessHandler)success
                                      failure:(nullable WSFailureError)failure;



/// Group control command issuance.
///
/// @param dpCodes dp Codes
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpCodes:(NSDictionary *)dpCodes
               success:(nullable WSSuccessHandler)success
               failure:(nullable WSFailureError)failure;


@end

NS_ASSUME_NONNULL_END
