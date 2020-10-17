//
//  WSCoreCacheService.h
//  WiserSmartDeviceCoreKit
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WSCoreCacheServiceDelegate <NSObject>

- (void)deviceWillRemove:(NSString *)devId;
- (void)groupWillRemove:(long long)groupId;


- (void)deviceWillAdd:(WiserSmartDeviceModel *)deviceModel homeId:(long long)homeId;
- (void)groupWillAdd:(WiserSmartGroupModel *)groupModel homeId:(long long)homeId;

- (void)deviceListWillAdd:(NSArray<WiserSmartDeviceModel *> *)deviceList homeId:(long long)homeId;

@end

@interface WSCoreCacheService : NSObject

WSSDK_SINGLETON;

@property (nonatomic, weak) id<WSCoreCacheServiceDelegate> delegate;

/// 设备缓存
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, WiserSmartDeviceModel *> *deviceData;

/// 群组缓存
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, WiserSmartGroupModel *> *groupData;

/// 群组产品信息缓存
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSDictionary *> *groupProductData;

/// 群组设备关系缓存
@property (nonatomic, strong, readonly) NSMutableDictionary *groupDeviceRelation;

/// mesh 信息
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, WiserSmartBleMeshModel *> *meshData;


- (void)setCacheHandlerQueue:(dispatch_queue_t)queue;

- (void)reset;

- (WiserSmartDeviceModel *)getDeviceInfoWithDevId:(NSString *)devId;

- (WiserSmartGroupModel *)getGroupInfoWithGroupId:(long long)groupId;

- (NSDictionary *)getGroupProductWithProductId:(NSString *)productId;

- (NSArray <WiserSmartDeviceModel *> *)getDeviceListWithGroupId:(long long)groupId;

- (void)updateGroupProductList:(NSArray <NSDictionary *> *)groupProductList;

- (void)updateDeviceGroupRelationWithDeviceList:(NSArray *)deviceList groupId:(long long)groupId;

- (void)updateDeviceGroupRelationWithDeviceList:(NSArray *)deviceList groupId:(long long)groupId shouldNotify:(BOOL)shouldNotify;

- (NSArray <WiserSmartDeviceModel *> *)getAllDeviceList;
- (NSArray <WiserSmartGroupModel *> *)getAllGroupList;

- (void)updateSharedDeviceList:(NSArray <WiserSmartDeviceModel *> *)deviceList;

- (void)updateSharedGroupList:(NSArray <WiserSmartGroupModel *> *)groupList;

- (NSArray <WiserSmartDeviceModel *> *)getDeviceListWithHomeId:(long long)homeId;
// remove delegates

- (void)removeDeviceWithDevId:(NSString *)devId;
- (void)removeGroupWithGroupId:(long long)groupId;

// add delegate

- (void)addDeviceModel:(WiserSmartDeviceModel *)deviceModel homeId:(long long)homeId;
- (void)addGroupModel:(WiserSmartGroupModel *)groupModel homeId:(long long)homeId;

- (void)addDeviceModelList:(NSArray<WiserSmartDeviceModel *> *)deviceModelList homeId:(long long)homeId;

// mesh
- (WiserSmartBleMeshModel *)getMeshModelWithHomeId:(long long)homeId isSigMesh:(BOOL)isSigMesh;
- (WiserSmartBleMeshModel *)getMeshModelWithMeshId:(NSString *)meshId;


@end

NS_ASSUME_NONNULL_END
