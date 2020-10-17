//
//  WiserSmartRouterActivator.h
//  WiserSmartActivatorKit
//
//
//

#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartRouterActivator;

@protocol WiserSmartRouterActivatorDelegate <NSObject>


/**
 Callback of Config Network Status Update
 配网状态更新的回调
 
 @param activator   instance
 @param deviceModel devicemodel
 @param error       error
 */
- (void)routerActivator:(WiserSmartRouterActivator *)activator didReceiveAutoConfigDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface WiserSmartRouterActivator : NSObject

/**
 delegate
 */
@property (nonatomic, weak) id<WiserSmartRouterActivatorDelegate> delegate;

/**
 * Get a list of all devices that support route atvice in the current home
 * 获取当前家庭下所有网关路由器设备列表
 *
 * @param homeId 当前家庭的id
 * @return 当前家庭所有网关路由器设备列表
 */
- (NSArray <WiserSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId;

/**
 *  To obtain token (valid for 10 minutes)
 *  获取配网Token（有效期10分钟）
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)getTokenSuccess:(WSSuccessString)success
                failure:(WSFailureError)failure;


/**
 * start discover device with gateway route
 * 开始发现设备
 *
 * @param devIds    Device Id list
 * @param type      Type,  0 to start discover device
 * @param timeout   Timeout, default 100 seconds
 * @param success   Success block
 * @param failure   Failure block
 */
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;


/**
 * start discover device with gateway route
 * 开始发现设备
 *
 * @param devIds    Device Id list
 * @param token     Config Token
 * @param type      Type,  0 to start discover device
 * @param timeout   Timeout, default 100 seconds
 * @param success   Success block
 * @param failure   Failure block
 */
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                token:(NSString *)token
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure;


/**
 * stop discover
 * 停止发现设备
 */
- (void)stopDiscover;


/**
 * Binding device to the home
 * 将设备绑定家庭
 *
 * @param homeId  HomeId
 * @param devIds  Deivce Id list
 * @param success Success block
 * @param failure Failure block
 */
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(WSSuccessHandler)success failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
