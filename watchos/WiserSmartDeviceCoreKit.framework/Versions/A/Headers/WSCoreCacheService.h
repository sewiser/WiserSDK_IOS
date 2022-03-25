//
// WSCoreCacheService.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The delegate or WSCoreCacheService class, provides device or group related status callback.
@protocol WSCoreCacheServiceDelegate <NSObject>

- (void)deviceDidAdd:(WiserSmartDeviceModel *)deviceModel;
- (void)deviceListDidAdd:(NSArray<WiserSmartDeviceModel *> *)deviceList;
- (void)deviceDidRemove:(NSString *)devId;

- (void)groupDidAdd:(WiserSmartGroupModel *)groupModel;
- (void)groupDidRemove:(long long)groupId;

@end

/// @brief Devices, group core cache classes, including data model additions, deletions, changes, and related mqtt message subscriptions.
@interface WSCoreCacheService : NSObject

WSSDK_SINGLETON;

@property (nonatomic, weak) id<WSCoreCacheServiceDelegate> delegate;

/// Device cache.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, WiserSmartDeviceModel *> *deviceData;

/// Group caching.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, WiserSmartGroupModel *> *groupData;

/// Group product information cache.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSDictionary *> *groupProductData;

/// Group device relationship cache.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSMutableArray<NSString *> *> *groupDeviceRelation;

/// Mesh information.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, WiserSmartBleMeshModel *> *meshData;

/// Mesh Group information.
@property (nonatomic, strong, readonly) NSMutableDictionary *meshGroupAddData;

/// Set the queue for processing the cache
///
/// @param queue queue
- (void)setCacheHandlerQueue:(dispatch_queue_t)queue;


/// clear cache data.
/// queue.async
- (void)reset;

#pragma mark - device

/// Get the device by device id, synchronize to get
/// queue.sync
///
/// @param devId The device Id.
- (WiserSmartDeviceModel *)getDeviceInfoWithDevId:(NSString *)devId;


/// Add a device to the cache.
///
/// After adding to the cache, subscribe to the topic of the device's mqtt by default, make sure that local key and pv have values at this time
/// After adding, you can accept callbacks by implementing `deviceDidAdd:` of `WSCoreCacheServiceDelegate`.
/// Adding and subscribing, and executing callbacks are all in the `asynchronous thread`.
/// queue.async
///
/// @param deviceModel Model of the device to be added
- (void)addDeviceModel:(WiserSmartDeviceModel *)deviceModel;


/// Add a device to the cache
///
/// After adding to the cache, subscribe to the topic of the device's mqtt by default, making sure that local key and pv have values at this time
/// During the completion process, you can set the completion block or implement the `deviceDidAdd:` of the proxy `WSCoreCacheServiceDelegate` to handle the result of the event
/// The completion block is called first, the delegate second
/// Adding and subscribing, blocking, and callback execution are all in the asynchronous thread
/// queue.async
///
/// @param deviceModel The device model to be added
/// @param completion The callback after the completion of the join block
- (void)addDeviceModel:(WiserSmartDeviceModel *)deviceModel completion:(nullable void (^)(WiserSmartDeviceModel *device))completion;


/// Batch add devices to the cache
///
/// After adding to the cache, subscribe to the topic of each device's mqtt by default, make sure that local key and pv have values at this time
/// After adding, you can accept callbacks by implementing `deviceListDidAdd:` of `WSCoreCacheServiceDelegate`.
/// Adding and subscribing, as well as executing callbacks are all in the `asynchronous thread`.
/// queue.async
///
/// @param deviceModelList The group of devices to be added
- (void)addDeviceModelList:(NSArray<WiserSmartDeviceModel *> *)deviceModelList;


/// Batch add devices to the cache
///
/// After adding to the cache, subscribe to the topic of each device's mqtt by default, make sure that local key and pv have values at this time
/// During the completion process, you can set the completion block or implement the `deviceListDidAdd:` of the proxy `WSCoreCacheServiceDelegate` to handle the result of the event
/// The completion block is called first, the delegate second
/// Adding and subscribing, blocking, and callback execution are all in the asynchronous thread
/// queue.async
///
/// @param deviceModelList The group of devices to be added
/// @param completion The callback after the completion of the join block
- (void)addDeviceModelList:(NSArray<WiserSmartDeviceModel *> *)deviceModelList completion:(nullable void (^)(NSArray<WiserSmartDeviceModel *> *deviceList))completion;


/// Delete the cached data of the device by device id
///
/// If it is already deleted, it will not be executed to avoid duplicate operations
/// After deletion, the mqtt topic of the device will be unsubscribed
/// During the deletion process, the result of the event can be handled by implementing `deviceDidRemove:` of `WSCoreCacheServiceDelegate`.
/// Deletion and un subscription, and callback execution are all in asynchronous threads
/// queue.async
///
/// @param devId The id of the device to be removed
- (void)removeDeviceWithDevId:(NSString *)devId;


/// Delete the cached data of the device by device id
///
/// If it is already deleted, it will not be executed to avoid duplicate operations
/// After deletion, the mqtt topic of the device will be unsubscribed
/// During the deletion process, you can set the completion block or implement `deviceDidRemove:` as a proxy for `WSCoreCacheServiceDelegate` to handle the result of the event
/// The completion block is called first, the delegate second
/// The add and subscribe, completion block, and callback execution are all in the asynchronous thread
/// queue.async
///
/// @param devId The device id to be deleted
/// @param completion The callback block after the completion of the deletion
- (void)removeDeviceWithDevId:(NSString *)devId completion:(nullable void (^)(NSString *devId))completion;


/// Get all devices in the cache.
/// queue.sync
- (NSArray <WiserSmartDeviceModel *> *)getAllDeviceList;

#pragma mark - device ota

/// 更新设备 ota 信息
/// @param otaList 设备 ota 信息列表
- (void)updateDeviceOtaInfoWithList:(NSArray<WiserSmartDeviceOTAModel *> *)otaList;

/// 获取设备 ota 信息
/// @param devId 设备 ID
- (WiserSmartDeviceOTAModel *)getDeviceOtaInfoWithDevId:(NSString *)devId;

#pragma mark - group


/// Get group cache information by group id
/// queue.sync
///
/// @param groupId group id
- (WiserSmartGroupModel *)getGroupInfoWithGroupId:(long long)groupId;


/// Add a group to the cache
///
/// After adding to the cache, subscribe to the topic of the group's mqtt by default, make sure that local key and pv have values at this time
/// After adding, you can accept callbacks by implementing `groupDidAdd:` of `WSCoreCacheServiceDelegate`.
/// Adding and subscribing, and callback execution are all in `asynchronous threads`
/// queue.async
///
/// @param groupModel The group model to be added
- (void)addGroupModel:(WiserSmartGroupModel *)groupModel;


//// Add a group to the cache
///
/// After adding to the cache, subscribe to the topic of the group's mqtt by default, making sure that local key and pv have values at this time
/// During the completion process, you can set the completion block or implement the proxy `groupDidAdd:` of `WSCoreCacheServiceDelegate` to handle the result of the event
/// The completion block is called first, the delegate second
/// Adding and subscribing, blocking, and callback execution are all in the asynchronous thread
/// queue.async
///
/// @param groupModel The group model to be joined
/// @param completion Callback after the completion of the join block
- (void)addGroupModel:(WiserSmartGroupModel *)groupModel completion:(nullable void (^)(WiserSmartGroupModel *group))completion;


//// Delete the cached data of a group by its group id
///
/// If the group is already deleted, it will not be executed to avoid duplicate operations
/// After deletion, the mqtt topic of the group will be unsubscribed
/// During the deletion process, the result of the event can be handled by implementing `groupDidRemove:` of `WSCoreCacheServiceDelegate`.
/// Deletion and un subscription, and callback execution are all in asynchronous threads
/// queue.async
///
/// @param groupId The device id to be removed
- (void)removeGroupWithGroupId:(long long)groupId;

/// Get all groups in the cache
/// queue.sync
- (NSArray <WiserSmartGroupModel *> *)getAllGroupList;


#pragma mark - group product

/// Get group product information based on product id.
/// queue.sync
///
/// @param productId The product id.
- (NSDictionary *)getGroupProductWithProductId:(NSString *)productId;


/// Get the list of devices under a group
/// queue.sync
///
/// @param groupId  group id
- (NSArray <WiserSmartDeviceModel *> *)getDeviceListWithGroupId:(long long)groupId;


/// Bulk update of product information
/// queue.async
///
/// @param groupProductList Product information json list
- (void)updateGroupProductList:(NSArray <NSDictionary *> *)groupProductList;


#pragma mark - [group - device] relation

/// Batch update group - device information relationship
/// queue.async
///
/// @param deviceList device list
/// @param groupId The group id.
- (void)updateDeviceGroupRelationWithDeviceList:(NSArray *)deviceList groupId:(long long)groupId;


/// Batch Update Groups - Device Information Relationships
/// queue.async
///
/// @param deviceList device list
/// @param groupId group id
/// @param shouldNotify Whether to send notifications, if `yes`, then `kNotificationGroupUpdate` will be sent.
- (void)updateDeviceGroupRelationWithDeviceList:(NSArray *)deviceList groupId:(long long)groupId shouldNotify:(BOOL)shouldNotify;


#pragma mark - shared device and group

/// Get the list of shared devices
/// queue.sync
- (NSArray <WiserSmartDeviceModel *> *)getSharedDeviceList;


/// Get a list of shared groups
/// queue.sync
- (NSArray <WiserSmartGroupModel *> *)getSharedGroupList;


/// Update device sharing list
/// queue.async
///
/// @param deviceList device sharing list
- (void)updateSharedDeviceList:(NSArray <WiserSmartDeviceModel *> *)deviceList;


/// Update group sharing list
/// queue.async
///
/// @param groupList group sharing list
- (void)updateSharedGroupList:(NSArray <WiserSmartGroupModel *> *)groupList;

/// This is a special sharing type of device, such as sharing the family and sharing the device at the same time, to distinguish.
- (NSArray <NSString *> *)getSpecialSharedDevIds;

- (NSArray <WiserSmartDeviceModel *> *)getDeviceListWithHomeId:(long long)homeId;

#pragma mark - mesh

/// Get mesh information
/// queue.sync
///
/// @param meshId mesh id
- (WiserSmartBleMeshModel *)getMeshModelWithMeshId:(NSString *)meshId;

/// Update mesh information
/// queue.sync
///
/// @param meshModel mesh info
- (void)updateMeshModel:(WiserSmartBleMeshModel *)meshModel;

- (NSArray<WiserSmartBleMeshModel *> *)getAllMeshList;
- (NSInteger)getMeshGroupAddressFromLocalWithMeshId:(NSString *)meshId;
- (NSInteger)getMeshGroupCountFromLocalWithMeshId:(NSString *)meshId;
- (void)removeMeshGroupWithAddress:(NSInteger)address meshId:(NSString *)meshId;

@end

NS_ASSUME_NONNULL_END
