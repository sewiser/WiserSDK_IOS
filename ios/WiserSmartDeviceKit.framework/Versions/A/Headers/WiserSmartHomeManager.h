//
//  WiserSmartHomeManager.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "WiserSmartHomeModel.h"

@class WiserSmartHomeManager;


@protocol WiserSmartHomeManagerDelegate <NSObject>

@optional

/**
 *  the delegate when a new home is added.
 *  新增一个家庭代理回调
 *
 *  @param manager  instance
 *  @param home     homeModel
 */
- (void)homeManager:(WiserSmartHomeManager *)manager didAddHome:(WiserSmartHomeModel *)home;

/**
 *  the delegate when an existing home is removed.
 *  删除一个家庭代理回调
 *
 *  @param manager  instance
 *  @param homeId   homeId
 */
- (void)homeManager:(WiserSmartHomeManager *)manager didRemoveHome:(long long)homeId;

/**
 *  MQTT connected success
 *  MQTT 服务连接成功代理回调
 */
- (void)serviceConnectedSuccess;


@end

@interface WiserSmartHomeManager : NSObject

@property (nonatomic, weak) id <WiserSmartHomeManagerDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <WiserSmartHomeModel *> *homes;


/**
 *  get homes list. if you want to get home deatails, need to initialize a home, call getHomeDetailWithSuccess: failure:
 *  获取家庭列表，如果要获取具体家庭的详情，需要去初始化一个home，调用接口getHomeDetailWithSuccess:failure:
 *
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)getHomeListWithSuccess:(void(^)(NSArray <WiserSmartHomeModel *> *homes))success
                       failure:(WSFailureError)failure;

/**
 *  Adds a new home
 *  添加家庭
 *
 *  @param homeName    Home name
 *  @param geoName     City name
 *  @param rooms       Rooms list
 *  @param latitude    Lat
 *  @param longitude   Lon
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)addHomeWithName:(NSString *)homeName
                geoName:(NSString *)geoName
                  rooms:(NSArray <NSString *>*)rooms
               latitude:(double)latitude
              longitude:(double)longitude
                success:(WSSuccessLongLong)success
                failure:(WSFailureError)failure;

/**
 *  Home sort
 *  家庭排序
 *
 *  @param homeList    Homes list
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)sortHomeList:(NSArray <WiserSmartHomeModel *> *)homeList
             success:(WSSuccessHandler)success
             failure:(WSFailureError)failure;

/**
 *  Accept or reject to shared home
 *  接受或拒绝加⼊分享过来的家庭
 *
 *  @param homeId       Home Id
 *  @param isAccept     Whether to accept the invitation
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)joinFamilyWithHomeId:(long long)homeId
                      action:(BOOL)isAccept
                     success:(WSSuccessBOOL)success
                     failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartHome - (void)joinFamilyWithAccept:success:failure:] instead");

@end
