//
//  WiserSmartHome.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WiserSmartHomeModel.h"
#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>
#import "WiserSmartRoomModel.h"
#import "WiserSmartHomeMemberModel.h"
#import "WiserSmartHomeAddMemberRequestModel.h"

@class WiserSmartHome;

@protocol WiserSmartHomeDelegate <NSObject>

@optional

/**
 *  the delegate of home update information, such as the name, online
 *  家庭信息变化代理回调
 *
 *  @param home instance
 */
- (void)homeDidUpdateInfo:(WiserSmartHome *)home;

/**
 *  the delegate of shared device list update.
 *  设备共享信息变化代理回调
 *
 *  @param home instance
 */
- (void)homeDidUpdateSharedInfo:(WiserSmartHome *)home;

/**
 *  the delegate when a new room is added.
 *  家庭下新增房间代理回调
 *
 *  @param home instance
 *  @param room roomModel
 */
- (void)home:(WiserSmartHome *)home didAddRoom:(WiserSmartRoomModel *)room;

/**
 *  the delegate when an existing room is removed.
 *  家庭下删除房间代理回调
 *
 *  @param home     instance
 *  @param roomId   roomId
 */
- (void)home:(WiserSmartHome *)home didRemoveRoom:(long long)roomId;

/**
 *  the delegate of room update information, such as the name.
 *  家庭下房间信息变化代理回调
 *
 *  @param home     instance
 *  @param room     roomModel
 */
- (void)home:(WiserSmartHome *)home roomInfoUpdate:(WiserSmartRoomModel *)room;

/**
 *  the delegate of relation update of room, group and device.
 *  房间和设备，群组关系变化代理回调
 *
 *  @param home instance
 *  @param room roomModel
 */
- (void)home:(WiserSmartHome *)home roomRelationUpdate:(WiserSmartRoomModel *)room;

/**
 *  the delegate when a new device is added.
 *  家庭下新增设备代理回调
 *
 *  @param home     instance
 *  @param device   deviceModel
 */
- (void)home:(WiserSmartHome *)home didAddDeivice:(WiserSmartDeviceModel *)device;

/**
 *  the delegate when an existing device is removed.
 *  家庭下删除设备代理回调
 *
 *  @param home     instance
 *  @param devId    devId
 */
- (void)home:(WiserSmartHome *)home didRemoveDeivice:(NSString *)devId;

/**
 *  the delegate of device update information, such as the name.
 *  家庭下设备的信息变化代理回调
 *
 *  @param home     instance
 *  @param device   deviceModel
 */
- (void)home:(WiserSmartHome *)home deviceInfoUpdate:(WiserSmartDeviceModel *)device;

/**
 *  the delegate of device dps update.
 *  家庭下设备的 dps 变化代理回调
 *
 *  @param home     instance
 *  @param device   deviceModel
 *  @param dps      dps
 */
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;

/**
 *  the delegate of warning information update
 *  家庭下设备的告警信息变化的代理回调
 *
 *  @param home         instance
 *  @param device       deviceModel
 *  @param warningInfo  warning Info
 */
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;

/**
*  the delegate of device firmware upgrade status update
*  家庭下设备升级状态的回调
*
*  @param home                家庭实例 home instance
*  @param device              设备模型 deviceModel
*  @param upgradeStatusModel  设备升级状态模型 upgradeStatusModel
*/
- (void)home:(WiserSmartHome *)home device:(WiserSmartDeviceModel *)device firmwareUpgradeStatusModel:(WiserSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;

/**
 *  the delegate when a new group is added.
 *  家庭下新增群组代理回调
 *
 *  @param home     instance
 *  @param group    groupModel
 */
- (void)home:(WiserSmartHome *)home didAddGroup:(WiserSmartGroupModel *)group;

/**
 *  the delegate of group dps update.
 *  家庭下群组 dps 变化代理回调
 *
 *  @param home     instance
 *  @param group    groupModel
 *  @param dps      dps
 */
- (void)home:(WiserSmartHome *)home group:(WiserSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;

/**
 *  the delegate when an existing group is removed.
 *  家庭下删除群组代理回调
 *
 *  @param home     instance
 *  @param groupId  groupId
 */
- (void)home:(WiserSmartHome *)home didRemoveGroup:(NSString *)groupId;

/**
 *  the delegate of group update information, such as the name.
 *  家庭下群组基本信息变化（例如群组名字等）代理回调
 *
 *  @param home     instance
 *  @param group    groupModel
 */
- (void)home:(WiserSmartHome *)home groupInfoUpdate:(WiserSmartGroupModel *)group;

#pragma mark - deprecated
/**
 *  the delegate of relation update of home and room.(deprecated)
 *  家庭下房间信息信息变化代理回调（已废弃）
 *
 *  @param home instance
 */
- (void)homeDidUpdateRoomInfo:(WiserSmartHome *)home __deprecated_msg("Use -[WiserSmartHomeDelegate home:didAddRoom:] or [WiserSmartHomeDelegate home:didRemoveRoom:] instead.");

/**
 *  the delegate of device firmware upgrade status update
 *  家庭下设备升级状态的回调(废弃)
 *
 *  @param home           instance
 *  @param device         deviceModel
 *  @param upgradeStatus  upgrade status
 */
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

/**
 *  Init home
 *
 *  @param homeId Home Id
 *  @return instance
 */
+ (instancetype)homeWithHomeId:(long long)homeId;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Home

/**
 *  After init home, need to get home details
 *  初始化 home 对象之后需要获取家庭的详情，homeModel,roomList,deviceList,groupList 才有数据
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getHomeDetailWithSuccess:(void (^)(WiserSmartHomeModel *homeModel))success
                         failure:(WSFailureError)failure;

/**
 *  Update home info,API version 3.0
 *  修改家庭信息 API version 2.0
 *
 *  @param homeName    Home name
 *  @param geoName     City name
 *  @param latitude    Lat
 *  @param longitude   Lon
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                       success:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;


/**
 *  Update home info,API version 3.0
 *  修改家庭信息 API version 3.0
 *
 *  @param homeName    Home name
 *  @param geoName     City name
 *  @param latitude    Lat
 *  @param longitude   Lon
 *  @param rooms       Room name array
 *  @param overWriteRoom     NSDictionary now only support "overWriteRoom":boolean
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                         rooms:(NSArray *)rooms
                 overWriteRoom:(BOOL)overWriteRoom
                       success:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;

/**
 *  Remove a home
 *  解散家庭
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)dismissHomeWithSuccess:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;

/**
 *  order all device or group
 *  对整个家庭下设备和群组进行排序
 *
 *  @param orderList order list [@{@"bizId": @"XXX", @"bizType": @"XXX"},@{@"bizId": @"XXX",@"bizType": @"XXX"}] 其中bizId为设备的devId或群组的groupId, device的bizType = @"6" group的bizType = @"5"
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)sortDeviceOrGroupWithOrderList:(NSArray<NSDictionary *> *)orderList
                               success:(WSSuccessHandler)success
                               failure:(WSFailureError)failure;


#pragma mark - Room

/**
 *  Add a new room
 *  新增房间
 *
 *  @param name        Room name
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)addHomeRoomWithName:(NSString *)name
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure;

/**
 *  Remove a room
 *  解散房间
 *
 *  @param roomId      Home Id
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)removeHomeRoomWithRoomId:(long long)roomId
                         success:(WSSuccessHandler)success
                         failure:(WSFailureError)failure;

/**
 *  Homes sort
 *  房间排序
 *
 *  @param roomList    Homes list
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)sortRoomList:(NSArray <WiserSmartRoomModel *> *)roomList
             success:(WSSuccessHandler)success
             failure:(WSFailureError)failure;


#pragma mark - home member

/**
 *  Get home member list
 *  获取家庭成员列表
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getHomeMemberListWithSuccess:(void(^)(NSArray <WiserSmartHomeMemberModel *> *memberList))success
                             failure:(WSFailureError)failure;


/**
*  Add a home member
*  添加家庭成员
*
*  @param requestModel member model
*  @param success      Success block
*  @param failure      Failure block
*/
- (void)addHomeMemberWithAddMemeberRequestModel:(WiserSmartHomeAddMemberRequestModel *)requestModel
                                        success:(WSSuccessDict)success
                                        failure:(WSFailureError)failure;

/**
 *  Accept or reject to shared home
 *  接受或拒绝加⼊分享过来的家庭
 *
 *  @param accept       Whether to accept the invitation
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)joinFamilyWithAccept:(BOOL)accept
                     success:(WSSuccessBOOL)success
                     failure:(WSFailureError)failure;

@end
