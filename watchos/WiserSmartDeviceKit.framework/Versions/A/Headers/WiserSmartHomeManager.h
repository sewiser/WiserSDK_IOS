//
// WiserSmartHomeManager.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

#import "WiserSmartHomeModel.h"

@class WiserSmartHomeManager;


@protocol WiserSmartHomeManagerDelegate <NSObject>

@optional

/// The delegate when a new home is added.
///
/// @param manager  instance
/// @param home     homeModel
- (void)homeManager:(WiserSmartHomeManager *)manager didAddHome:(WiserSmartHomeModel *)home;

/// The delegate when an existing home is removed.
///
/// @param manager  instance
/// @param homeId   homeId
- (void)homeManager:(WiserSmartHomeManager *)manager didRemoveHome:(long long)homeId;

/// MQTT service connection success callback.
- (void)serviceConnectedSuccess;


@end

@interface WiserSmartHomeManager : NSObject

@property (nonatomic, weak) id <WiserSmartHomeManagerDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <WiserSmartHomeModel *> *homes;


/// Get homes list. If you want to get home details, need to initialize a home, call getHomeDetailWithSuccess: failure:
///
/// @param success Called when the task finishes successfully. A list of WiserSmartHomeModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeListWithSuccess:(void(^)(NSArray <WiserSmartHomeModel *> *homes))success
                       failure:(WSFailureError)failure;


/// Adds a new home
///
/// @param homeName    Home name
/// @param geoName     City name
/// @param rooms       Rooms list
/// @param latitude    Latitude
/// @param longitude   Longitude
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addHomeWithName:(NSString *)homeName
                geoName:(NSString *)geoName
                  rooms:(NSArray <NSString *>*)rooms
               latitude:(double)latitude
              longitude:(double)longitude
                success:(WSSuccessLongLong)success
                failure:(WSFailureError)failure;


/// Home sort
///
/// @param homeList    Homes list
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)sortHomeList:(NSArray <WiserSmartHomeModel *> *)homeList
             success:(WSSuccessHandler)success
             failure:(WSFailureError)failure;

#pragma mark - deprecated

/// Accept or reject to shared home
///
/// @param homeId       Home Id
/// @param isAccept     Whether to accept the invitation
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use WiserSmartHome::joinFamilyWithAccept:success:failure: instead.
- (void)joinFamilyWithHomeId:(long long)homeId
                      action:(BOOL)isAccept
                     success:(WSSuccessBOOL)success
                     failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartHome - (void)joinFamilyWithAccept:success:failure:] instead");

@end
