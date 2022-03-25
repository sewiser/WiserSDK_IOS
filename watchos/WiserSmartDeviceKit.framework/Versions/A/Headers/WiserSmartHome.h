//
// WiserSmartHome.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartHomeModel.h"
#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>
#import "WiserSmartRoomModel.h"
#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeAddMemberRequestModel.h"

@class WiserSmartHome;

@protocol WiserSmartHomeDelegate <NSObject>

@optional


/// The delegate of home update information, such as the name, online
///
/// @param home instance
- (void)homeDidUpdateInfo:(WiserSmartHome *)home;

/// The delegate of shared device list update.
///
/// @param home instance
- (void)homeDidUpdateSharedInfo:(WiserSmartHome *)home;


/// The delegate when a new room is added.
///
/// @param home instance
/// @param room roomModel
- (void)home:(WiserSmartHome *)home didAddRoom:(WiserSmartRoomModel *)room;


/// The delegate when an existing room is removed.
///
/// @param home     instance
/// @param roomId   roomId
- (void)home:(WiserSmartHome *)home didRemoveRoom:(long long)roomId;


/// The delegate of room update information, such as the name.
///
/// @param home     instance
/// @param room     roomModel
- (void)home:(WiserSmartHome *)home roomInfoUpdate:(WiserSmartRoomModel *)room;


/// The delegate of relation update of room, group and device.
///
/// @param home instance
/// @param room roomModel
- (void)home:(WiserSmartHome *)home roomRelationUpdate:(WiserSmartRoomModel *)room;


/// The delegate when a new device is added.
///
/// @param home     instance
/// @param device   deviceModel
- (void)home:(WiserSmartHome *)home didAddDeivice:(WiserSmartDeviceModel *)device;


/// The delegate when an existing device is removed.
///
/// @param home     instance
/// @param devId    devId
- (void)home:(WiserSmartHome *)home didRemoveDeivice:(NSString *)devId;


/// The delegate of device update information, such as the name.
///
/// @param home     instance
/// @param device   deviceModel
- (void)home:(WiserSmartHome *)home deviceInfoUpdate:(WiserSmartDeviceModel *)device;


/// The delegate of device dps update.
///
/// @param home     instance
/// @param device   deviceModel
/// @param dps      dps
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;


/// The delegate of warning information update.
///
/// @param home         instance
/// @param device       deviceModel
/// @param warningInfo  warning Info
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;


/// The delegate of device firmware upgrade status update.
///
/// @param home                home instance
/// @param device              deviceModel
/// @param upgradeStatusModel  upgradeStatusModel
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device firmwareUpgradeStatusModel:(WiserSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;


/// the delegate when family/shared devices ota status are updated
/// @param home The home instance
/// @param otaModelList OTA model list
- (void)home:(WiserSmartHome *)home didUpdateOTAModelList:(NSArray<WiserSmartDeviceOTAModel *> *)otaModelList;

/// The delegate when a new group is added.
///
/// @param home     instance
///  @param group    groupModel
- (void)home:(WiserSmartHome *)home didAddGroup:(WiserSmartGroupModel *)group;


/// The delegate of group dps update.
///
/// @param home     instance
/// @param group    groupModel
/// @param dps      dps
- (void)home:(WiserSmartHome *)home group:(WiserSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;


/// The delegate when an existing group is removed.
///
/// @param home     instance
/// @param groupId  groupId
- (void)home:(WiserSmartHome *)home didRemoveGroup:(NSString *)groupId;


/// The delegate of group update information, such as the name.
///
/// @param home     instance
/// @param group    groupModel
- (void)home:(WiserSmartHome *)home groupInfoUpdate:(WiserSmartGroupModel *)group;

#pragma mark - deprecated

/// The delegate of relation update of home and room.(deprecated)
///
/// @param home instance
/// @deprecated This method is deprecated, Use WiserSmartHomeDelegate::home:didAddRoom: or  WiserSmartHomeDelegate::home:didRemoveRoom: instead.
- (void)homeDidUpdateRoomInfo:(WiserSmartHome *)home __deprecated_msg("Use -[WiserSmartHomeDelegate home:didAddRoom:] or [WiserSmartHomeDelegate home:didRemoveRoom:] instead.");

/// The delegate of device firmware upgrade status update.
///
/// @param home           instance
/// @param device         deviceModel
/// @param upgradeStatus  upgrade status
/// @deprecated This method is deprecated, Use WiserSmartHomeDelegate::home:device:firmwareUpgradeStatusModel: instead.
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device upgradeStatus:(WiserSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use home:device:firmwareUpgradeStatusModel: instead");

@end

@interface WiserSmartHome : NSObject

@property (nonatomic, weak) id <WiserSmartHomeDelegate> delegate;

@property (nonatomic, strong, readonly) WiserSmartHomeModel *homeModel;

@property (nonatomic, copy, readonly) NSArray <WiserSmartRoomModel *> *roomList;

@property (nonatomic, copy, readonly) NSArray <WiserSmartDeviceModel *> *deviceList;

@property (nonatomic, copy, readonly) NSArray <WiserSmartGroupModel *> *groupList;

@property (nonatomic, copy, readonly) NSArray <WiserSmartDeviceModel *> *sharedDeviceList;

@property (nonatomic, copy, readonly) NSArray <WiserSmartGroupModel *>  *sharedGroupList;

@property (nonatomic, copy, readonly) NSArray <WiserSmartDeviceOTAModel *> *deviceOtaList;

/// Init home.
///
/// @param homeId Home Id
/// @return instance
+ (instancetype)homeWithHomeId:(long long)homeId;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Home

/// After initializing the home object, you need to get the details of the family, homeModel, roomList, deviceList, groupList to have the data。
/// @param success Called when the task finishes successfully. WiserSmartHomeModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeDetailWithSuccess:(void (^)(WiserSmartHomeModel *homeModel))success
                         failure:(WSFailureError)failure;

/// After get home details, update device ota status
/// @param homeId Home id
/// @param success Called when the task finishes successfully.
/// @param failure  If error occurred while adding the task, this block will be called.
- (void)getDeviceOTAStatusWithHomeId:(long long)homeId
                             success:(void (^)(NSArray<WiserSmartDeviceOTAModel *> *))success
                             failure:(WSFailureError)failure;


/// Update home info, API version 2.0.
///
/// @param homeName    Home name
/// @param geoName     City name
/// @param latitude    Lat
/// @param longitude   Lon
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                       success:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;



/// Update home info,API version 3.0
///
/// @param homeName    Home name
/// @param geoName     City name
/// @param latitude    Lat
/// @param longitude   Lon
/// @param rooms       Room name array
/// @param overWriteRoom     NSDictionary now only support "overWriteRoom":boolean
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                         rooms:(NSArray *)rooms
                 overWriteRoom:(BOOL)overWriteRoom
                       success:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;


/// Remove a home.
///
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)dismissHomeWithSuccess:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;


/// Sorting of devices and groups under the entire family.
/// @param orderList order list [@{@"bizId": @"XXX", @"bizType": @"XXX"},@{@"bizId": @"XXX",@"bizType": @"XXX"}], where bizId is the device's devId or group's groupId, device's bizType = @"6" group's bizType = @"5".
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)sortDeviceOrGroupWithOrderList:(NSArray<NSDictionary *> *)orderList
                               success:(WSSuccessHandler)success
                               failure:(WSFailureError)failure;


#pragma mark - Room


/// Add a new room
///
/// @param name        Room name.
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addHomeRoomWithName:(NSString *)name
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure;


/// Remove a room
///
/// @param roomId      Home Id
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeHomeRoomWithRoomId:(long long)roomId
                         success:(WSSuccessHandler)success
                         failure:(WSFailureError)failure;


/// Homes sort
///
/// @param roomList    Homes list
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)sortRoomList:(NSArray <WiserSmartRoomModel *> *)roomList
             success:(WSSuccessHandler)success
             failure:(WSFailureError)failure;


#pragma mark - home member

/// Get home member list
///
/// @param success     Called when the task finishes successfully. A list of WiserSmartHomeMemberModel will be returned.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)getHomeMemberListWithSuccess:(void(^)(NSArray <WiserSmartHomeMemberModel *> *memberList))success
                             failure:(WSFailureError)failure;


/// Add a home member
///
/// @param requestModel member model
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)addHomeMemberWithAddMemeberRequestModel:(WiserSmartHomeAddMemberRequestModel *)requestModel
                                        success:(WSSuccessDict)success
                                        failure:(WSFailureError)failure;

/// Accept or reject to shared home
///
/// @param accept       A boolean value indicates whether to accept the invitation.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)joinFamilyWithAccept:(BOOL)accept
                     success:(WSSuccessBOOL)success
                     failure:(WSFailureError)failure;


/// Sync home device list
///
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)syncHomeDeviceListWithSuccess:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;

@end
