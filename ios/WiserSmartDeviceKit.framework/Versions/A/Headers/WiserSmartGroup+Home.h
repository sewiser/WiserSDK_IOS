//
// WiserSmartGroup+Home.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface WiserSmartGroup (Home)

/// Creating Groups of Wifi Devices.
/// @param name The group name.
/// @param productId Product ID.
/// @param homeId Home ID.
/// @param devIdList DeviceId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createGroupWithName:(NSString *)name
                  productId:(NSString *)productId
                     homeId:(long long)homeId
                  devIdList:(NSArray<NSString *> *)devIdList
                    success:(nullable void (^)(WiserSmartGroup *group))success
                    failure:(nullable WSFailureError)failure;


/// Create groups of zigBee devices.
/// @param name Group name.
/// @param homeId Home ID.
/// @param gwId Gateway ID.
/// @param productId Product ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createGroupWithName:(NSString *)name
                     homeId:(long long)homeId
                       gwId:(NSString *)gwId
                  productId:(NSString *)productId
                    success:(nullable void (^)(WiserSmartGroup *))success
                    failure:(nullable WSFailureError)failure;

/// Get a list of ZigBee sub devices for the corresponding support group based on productId and gwId.
/// @param productId Product ID.
/// @param gwId Gateway ID.
/// @param homeId Home ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                         homeId:(long long)homeId
                        success:(nullable void (^)(NSArray<WiserSmartGroupDevListModel *> *))success
                        failure:(nullable WSFailureError)failure;

/// Get list of WiFi devices that support groups based on productId.
/// @param productId Product ID.
/// @param homeId Home ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDevList:(NSString *)productId
            homeId:(long long)homeId
           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
           failure:(nullable WSFailureError)failure;


#if TARGET_OS_IOS

/// Add ZigBee devices to groups (interacting locally with gateways).
/// @param nodeList Zigbee sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                            success:(nullable WSSuccessHandler)success
                            failure:(nullable WSFailureError)failure;


/// Remove ZigBee devices from groups (interacting locally with gateways).
/// @param nodeList Zigbee sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                               success:(nullable WSSuccessHandler)success
                               failure:(nullable WSFailureError)failure;

#endif

@end

NS_ASSUME_NONNULL_END
