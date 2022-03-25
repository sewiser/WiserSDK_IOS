//
// WiserSmartRoom.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartRoomModel.h"
#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

@interface WiserSmartRoom : NSObject

/// room model
@property (nonatomic, strong, readonly) WiserSmartRoomModel *roomModel;

/// device list
@property (nonatomic, strong, readonly) NSArray <WiserSmartDeviceModel *> *deviceList;

/// group list
@property (nonatomic, strong, readonly) NSArray <WiserSmartGroupModel *> *groupList;


/// Get room instance.
///
/// @param roomId Room ID
/// @param homeId Home ID
/// @return instance
+ (instancetype)roomWithRoomId:(long long)roomId homeId:(long long)homeId;


/// Get room instance
///
/// @param roomId Room ID
/// @param homeId Home ID
/// @return instance
- (instancetype)initWithRoomId:(long long)roomId homeId:(long long)homeId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;


/// Rename the room.
///
/// @param roomName    Room name
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)updateRoomName:(NSString *)roomName success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Edit room icon.
///
/// @param icon room icon
/// @param success  Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateIcon:(UIImage *)icon success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Add device to the room.
///
/// @param deviceId    Device ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(WSSuccessHandler)success failure:(WSFailureError)failure;


/// Remove device from the room.
///
/// @param deviceId    Device ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(WSSuccessHandler)success failure:(WSFailureError)failure;


/// Add group to the room.
///
/// @param groupId     Group ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addGroupWithGroupId:(NSString *)groupId success:(WSSuccessHandler)success failure:(WSFailureError)failure;


/// Remove group from the room
///
/// @param groupId     Group ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeGroupWithGroupId:(NSString *)groupId success:(WSSuccessHandler)success failure:(WSFailureError)failure;


/// Batch modification of the relationship between rooms, groups and devices.
///
/// @param deviceGroupList  List of devices or groups.
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)saveBatchRoomRelationWithDeviceGroupList:(NSArray <NSString *> *)deviceGroupList
                                         success:(WSSuccessHandler)success
                                         failure:(WSFailureError)failure;


@end
