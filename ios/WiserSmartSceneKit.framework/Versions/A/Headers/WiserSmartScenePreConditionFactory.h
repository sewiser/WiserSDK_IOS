//
//  WiserSmartScenePreConditionFactory.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)
//

#import <Foundation/Foundation.h>
#import <WiserSmartSceneKit/WiserSmartSceneKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief WiserSmartScenePreConditionFactory provides convenient construction methods for developers to generate precondition object.
@interface WiserSmartScenePreConditionFactory : NSObject

/// Create an all-day valid precondition.
///
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
///
/// @return The WiserSmartScenePreConditionModel instance.
+ (WiserSmartScenePreConditionModel *)creatAllDayPreConditionWithSceneId:(NSString *__nullable)sceneId
                                                       existConditionId:(NSString * __nullable)conditionId
                                                                  loops:(NSString *)loops
                                                             timeZoneId:(NSString *)timeZoneId;

/// Create a daytime valid precondition.
/// 
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param cityId The current city id.
/// @param cityName The current city name.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
///
/// @return The WiserSmartScenePreConditionModel instance.
+ (WiserSmartScenePreConditionModel *)createDayTimePreConditionWithSceneId:(NSString *__nullable)sceneId
                                                         existConditionId:(NSString * __nullable)conditionId
                                                                    loops:(NSString *)loops
                                                                   cityId:(NSString *)cityId
                                                                 cityName:(NSString *)cityName
                                                               timeZoneId:(NSString *)timeZoneId;

/// Create a night valid precondition.
///
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param cityId The current city id.
/// @param cityName The current city name.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
///
/// @return The WiserSmartScenePreConditionModel instance.
+ (WiserSmartScenePreConditionModel *)createNightTimePreConditionWithSceneId:(NSString *__nullable)sceneId
                                                           existConditionId:(NSString * __nullable)conditionId
                                                                      loops:(NSString *)loops
                                                                     cityId:(NSString *)cityId
                                                                   cityName:(NSString *)cityName
                                                                 timeZoneId:(NSString *)timeZoneId;

/// Create a valid precondition of custom time period.
///
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param cityId The current city id.
/// @param cityName The current city name.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
/// @param begin The begin date. eg:"00:59".
/// @param end The end date. eg:"18:30".
///
/// @return The WiserSmartScenePreConditionModel instance.
+ (WiserSmartScenePreConditionModel *)createCustomTimePreConditionWithSceneId:(NSString *__nullable)sceneId
                                                            existConditionId:(NSString * __nullable)conditionId
                                                                       loops:(NSString *)loops
                                                                      cityId:(NSString *)cityId
                                                                    cityName:(NSString *)cityName
                                                                  timeZoneId:(NSString *)timeZoneId
                                                                   beginTime:(NSString *)begin
                                                                     endTime:(NSString *)end;

@end

NS_ASSUME_NONNULL_END

