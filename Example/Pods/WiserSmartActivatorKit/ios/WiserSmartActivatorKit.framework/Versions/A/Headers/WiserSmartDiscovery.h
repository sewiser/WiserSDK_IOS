//
//  WiserSmartDiscovery.h
//  WiserSmartActivatorKit
//
//
//

#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartDiscovery;

@protocol WiserSmartDiscoveryDelegate<NSObject>

@required

/**
 Callback of Device Discovery
 设备搜索回调
 
 @param discovery   instance
 @param deviceModel deviceModel
 @param error       error
 */
- (void)discovery:(WiserSmartDiscovery *)discovery didDiscoveryDevice:(WiserSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface WiserSmartDiscovery : NSObject

@property (nonatomic, weak) id<WiserSmartDiscoveryDelegate> delegate;


/**
 * start discover device
 * 开始发现设备
 *
 * @param ssid      Name of route 路由器热点名称
 * @param password  Password of route 路由器热点密码
 * @param timeout   Timeout, default 100 seconds
 * @param success   Success block
 * @param failure   Failure block
 */
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                      timeout:(NSTimeInterval)timeout
                      success:(WSSuccessHandler)success
                      failure:(WSFailureError)failure;


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


/**
 *  stop Discovery
 *  停止发现
 */
- (void)stopDiscovery;

@end

NS_ASSUME_NONNULL_END
