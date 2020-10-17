//
//  WiserSmartRoom.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WiserSmartRoomModel.h"
#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

@interface WiserSmartRoom : NSObject

// room model
@property (nonatomic, strong, readonly) WiserSmartRoomModel *roomModel;

// device list
@property (nonatomic, strong, readonly) NSArray <WiserSmartDeviceModel *> *deviceList;

// group list
@property (nonatomic, strong, readonly) NSArray <WiserSmartGroupModel *> *groupList;


/**
 *  Get room instance
 *  获取 room 对象
 *
 *  @param roomId Room ID
 *  @param homeId Home ID
 *  @return instance
 */
+ (instancetype)roomWithRoomId:(long long)roomId homeId:(long long)homeId;

/**
 *  Get room instance
 *  获取 room 对象
 *
 *  @param roomId Room ID
 *  @param homeId Home ID
 *  @return instance
 */
- (instancetype)initWithRoomId:(long long)roomId homeId:(long long)homeId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Rename the room
 *  更新房间名字
 *
 *  @param roomName    Room name
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)updateRoomName:(NSString *)roomName success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/**
 *  Edit room icon.
 *  修改房间图片
 *
 *  @param icon     icon
 *  @param success  Success block
 *  @param failure  Failure block
 */
- (void)updateIcon:(UIImage *)icon success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Add device to the room
 *  添加设备到房间
 *
 *  @param deviceId    Device ID
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/**
 *  Remove device from the room
 *  从房间中移除设备
 *
 *  @param deviceId    Device ID
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(WSSuccessHandler)success failure:(WSFailureError)failure;


/**
 *  Add group to the room
 *  添加群组到房间
 *
 *  @param groupId     Group ID
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)addGroupWithGroupId:(NSString *)groupId success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/**
 *  Remove group from the room
 *  从房间中移除群组
 *
 *  @param groupId     Group ID
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)removeGroupWithGroupId:(NSString *)groupId success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/**
 *  Batch modification of the relationship between rooms, groups and devices
 *  批量修改房间与群组、设备的关系
 *
 *  @param deviceGroupList  List of devices or groups
 *  @param success          Success block
 *  @param failure          Failure block
 */
- (void)saveBatchRoomRelationWithDeviceGroupList:(NSArray <NSString *> *)deviceGroupList
                                         success:(WSSuccessHandler)success
                                         failure:(WSFailureError)failure;


@end
