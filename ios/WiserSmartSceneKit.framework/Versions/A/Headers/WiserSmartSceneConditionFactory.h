//
//  WiserSmartSceneConditionFactory.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import <WiserSmartSceneKit/WiserSmartSceneKit.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>
#import "WiserSmartSceneExprModel.h"

/// The three geo fence type. Provide reach, exit and not set type.
typedef enum : NSInteger{
    /// The geo fence reach type.
    kGeoFenceTypeReach,
    /// The geo fence exit type.
    kGeoFenceTypeExit,
    /// The geo fence not set type.
    kGeoFenceTypeNotSet
}GeoFenceType;

/// @brief A factory design mode for create WiserSmartSceneConditionModel.
///
/// @note In order to facilitate the handling of multiple languages, this class does not handle the actionDisplay and actionDisplayNew fields of the WiserSmartSceneConditionModel.
@interface WiserSmartSceneConditionFactory : NSObject

/// Create a device condition.
///
/// @param device The device model to create condition.
/// @param dpModel The dpModel to create condition.
/// @param exprModel Create with WSSmartSceneConditionExprBuilder.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createDeviceConditionWithDevice:(WiserSmartDeviceModel *)device dpModel:(WiserSmartSceneDPModel *)dpModel exprModel:(WiserSmartSceneExprModel *)exprModel;

/// Create a timed type of human sensor condition, such as no movement for five minutes. Common human sensor conditions use -createDeviceConditionWithDevice:dpModel:exprModel:.
///
/// @param device The device model to create condition.
/// @param dpModel The dpModel to create condition.
/// @param exprModel Create with WSSmartSceneConditionExprBuilder.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createPirConditionWithDevice:(WiserSmartDeviceModel *)device dpModel:(WiserSmartSceneDPModel *)dpModel exprModel:(WiserSmartSceneExprModel *)exprModel;

/// Create an whether condition.
///
/// @param city Whether condition need a city.
/// @param dpModel The dpModel to create condition.
/// @param exprModel Create with WSSmartSceneConditionExprBuilder.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createWhetherConditionWithCity:(WiserSmartCityModel *)city dpModel:(WiserSmartSceneDPModel *)dpModel exprModel:(WiserSmartSceneExprModel *)exprModel;

/// Create a timer condition.
///
/// @param exprModel Create with WSSmartSceneConditionExprBuilder.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createTimerConditionWithExprModel:(WiserSmartSceneExprModel *)exprModel;

/// Create a timer condition related to sunrise and sunset times
///
/// @param city City to be operated.
/// @param exprModel Create with WSSmartSceneConditionExprBuilder.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createSunsetriseTimerConditionWithCity:(WiserSmartCityModel *)city ExprModel:(WiserSmartSceneExprModel *)exprModel;

/// Create a GeoFence conditon,conditionModel's entityId will be assigned after scene saved, the entityId represent the geoFence id, will should be upload to server by http API to trigger the automation.
///
/// @param type The GeoFenceType, reach or leave the place.
/// @param latitude  The geo fence center latitude.
/// @param longitude The geo fence center longitude.
/// @param radius Consider latitude and longitude as the center of a circle, this property represent the radius.
/// @param geoTitle The location name.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createGeoFenceConditionWithGeoType:(GeoFenceType)type geoLati:(CGFloat)latitude geoLonti:(CGFloat)longitude geoRadius:(CGFloat)radius geoTitle:(NSString *)geoTitle;

/// Create an "manual execute" condition.This condition should not be saved to cloud server, when you call the API to save a smart, you should delete this type of condition first.
///
/// @return WiserSmartSceneConditionModel object.
+ (WiserSmartSceneConditionModel *)createManualExecuteCondition;

@end

