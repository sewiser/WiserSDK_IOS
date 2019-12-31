//
//  WiserSmartGroup.h
//  WiserSmartPublic
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartGroup
#define WiserSmart_WiserSmartGroup

#import <Foundation/Foundation.h>
#import "WiserSmartGroupModel.h"
#import "WiserSmartGroupDevListModel.h"

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartGroup;

@protocol WiserSmartGroupDelegate<NSObject>

@optional

/**
 Group dps data update
 群组dp数据更新

 @param group   instance
 @param dps     dps
 */
- (void)group:(WiserSmartGroup *)group dpsUpdate:(NSDictionary *)dps;

/**
 Group Information Update
 群组信息更新

 @param group instance
 */
- (void)groupInfoUpdate:(WiserSmartGroup *)group;

/**
 Group removal
 群组移除

 @param groupId groupId
 */
- (void)groupRemove:(NSString *)groupId;

/**
 Group dpCodes data update
 群组dpCodes 数据更新

 @param group   instance
 @param dpCodes dpCodes
 */
- (void)group:(WiserSmartGroup *)group dpCodesUpdate:(NSDictionary *)dpCodes;

/**
 zigbee 设备加入到网关的群组响应
 1:超过场景数上限 2:子设备超时 3:设置值超出范围 4:写文件错误 5:其他错误
 Group Response of Zigbee Devices Joining Gateway
 1: Over the Scenario Limit 2: Subdevice Timeout 3: Setting Value Out of Range 4: Write File Error 5: Other Errors

 @param group           instance
 @param responseCode    responseCode
 */
- (void)group:(WiserSmartGroup *)group addResponseCode:(NSArray <NSNumber *>*)responseCode;

/**
 zigbee 设备从网关群组移除响应
 1:超过场景数上限 2:子设备超时 3:设置值超出范围 4:写文件错误 5:其他错误
 Group Response of Zigbee Devices removing Gateway
 1: Over the Scenario Limit 2: Subdevice Timeout 3: Setting Value Out of Range 4: Write File Error 5: Other Errors
 
 @param group           instance
 @param responseCode    responseCode
 */
- (void)group:(WiserSmartGroup *)group removeResponseCode:(NSArray <NSNumber *>*)responseCode;

@end

@interface WiserSmartGroup : NSObject

@property (nonatomic, strong, readonly) WiserSmartGroupModel *groupModel;

@property (nonatomic, weak, nullable) id<WiserSmartGroupDelegate> delegate;


/**
 *  Get WiserSmartGroup instance.
 *  获取群组对象
 *
 *  @param groupId groupId
 *  @return instance
 */
+ (nullable instancetype)groupWithGroupId:(NSString *)groupId;

/**
 *  Get WiserSmartGroup instance.
 *  获取群组对象
 *
 *  @param groupId groupId
 *  @return instance
 */
- (nullable instancetype)initWithGroupId:(NSString *)groupId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Creating Groups of Wifi Devices
 *  创建 wifi 设备群组
 *
 *  @param name      Group name
 *  @param productId Product ID
 *  @param homeId    Home ID
 *  @param devIdList DeviceId list
 *  @param success   Success block
 *  @param failure   Failure block
 */
+ (void)createGroupWithName:(NSString *)name
                  productId:(NSString *)productId
                     homeId:(long long)homeId
                  devIdList:(NSArray<NSString *> *)devIdList
                    success:(nullable void (^)(WiserSmartGroup *group))success
                    failure:(nullable WSFailureError)failure;


/**
 *  Get list of WiFi devices that support groups based on productId
 *  根据 productId 获取对应的支持群组的 wifi 设备列表
 *
 *  @param productId Product ID
 *  @param homeId    Home ID
 *  @param success   Success block
 *  @param failure   Failure block
 */
+ (void)getDevList:(NSString *)productId
            homeId:(long long)homeId
           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
           failure:(nullable WSFailureError)failure;

/**
 *  Get the device list for the corresponding group based on productId
 *  根据 productId 获取对应群组下的设备列表
 *
 *  @param productId Product ID
 *  @param success   Success block
 *  @param failure   Failure block
 */
- (void)getDevList:(NSString *)productId
           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
           failure:(nullable WSFailureError)failure;

/**
 *  Group control command issuance
 *  群组dp命令下发
 *
 *  @param dps     dps
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)publishDps:(NSDictionary *)dps success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/**
 *  Rename the group name
 *  修改群组名称
 *
 *  @param name    Group name
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)updateGroupName:(NSString *)name success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;


/**
 *  Modify the device list of the group
 *  修改群组设备列表
 *
 *  @param devList Device list
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)updateGroupRelations:(NSArray <NSString *>*)devList
                     success:(nullable WSSuccessHandler)success
                     failure:(nullable WSFailureError)failure;

/**
 *  Remove Group
 *  解散群组
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)dismissGroup:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;


#pragma mark - zigbee

/**
 *  Create groups of zigBee devices
 *  创建 zigbee 设备群组
 *
 *  @param name      Group name
 *  @param homeId    Home ID
 *  @param gwId      Gateway ID
 *  @param productId Product ID
 *  @param success   Success block
 *  @param failure   Failure block
 */
+ (void)createGroupWithName:(NSString *)name
                     homeId:(long long)homeId
                       gwId:(NSString *)gwId
                  productId:(NSString *)productId
                    success:(nullable void (^)(WiserSmartGroup *))success
                    failure:(nullable WSFailureError)failure;

/**
 *  Get a list of ZigBee subdevices for the corresponding support group based on productId and gwId
 *  根据 productId 和 gwId 获取对应的支持群组的 zigbee 子设备列表
 *
 *  @param productId Product ID
 *  @param gwId      Gateway ID
 *  @param homeId    Home ID
 *  @param success   Success block
 *  @param failure   Failure block
 */
+ (void)getDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                         homeId:(long long)homeId
                        success:(nullable void (^)(NSArray<WiserSmartGroupDevListModel *> *))success
                        failure:(nullable WSFailureError)failure;

#if TARGET_OS_IOS

/**
 *  Add ZigBee devices to groups (interacting locally with gateways)
 *  添加zigbee设备到群组(和网关本地交互)
 *
 *  @param nodeList Zigbee subdevce nodeId list
 *  @param success  Success block
 *  @param failure  Failure block
 */
- (void)addZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                            success:(nullable WSSuccessHandler)success
                            failure:(nullable WSFailureError)failure;

/**
 *  Remove ZigBee devices from groups (interacting locally with gateways)
 *  把zigbee设备从群组移除(和网关本地交互)
 *
 *  @param nodeList Zigbee subdevce nodeId list
 *  @param success  Success block
 *  @param failure  Failure block
 */
- (void)removeZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                               success:(nullable WSSuccessHandler)success
                               failure:(nullable WSFailureError)failure;

#endif

/// Cancel Request
- (void)cancelRequest;


@end

NS_ASSUME_NONNULL_END

#endif
