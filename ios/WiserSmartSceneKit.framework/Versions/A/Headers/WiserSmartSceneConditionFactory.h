//
//  WiserSmartSceneConditionFactory.h
//  WiserSmartSceneKit
//
//
//

#import <Foundation/Foundation.h>
#import <WiserSmartSceneKit/WiserSmartSceneKit.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>
#import "WiserSmartSceneExprModel.h"

typedef enum : NSInteger{
    kGeoFenceTypeReach,
    kGeoFenceTypeExit,
    kGeoFenceTypeNotSet
}GeoFenceType;

//为了方便处理多语言，本类不处理条件的exprDisplay，也就是条件显示相关的逻辑，需要上层自行拼装处理。

@interface WiserSmartSceneConditionFactory : NSObject

/**
 zh^
 创建一个设备条件。
 zh$
 en^
 Create a device condition.
 en$

 @param device The device model to create condition.
 @param dpModel The dpModel to create condition.
 @param exprModel Create with WSSmartSceneConditionExprBuilder.
 @return WiserSmartSceneConditionModel object.
 */
+ (WiserSmartSceneConditionModel *)createDeviceConditionWithDevice:(WiserSmartDeviceModel *)device dpModel:(WiserSmartSceneDPModel *)dpModel exprModel:(WiserSmartSceneExprModel *)exprModel;

/**
zh^
创建一个人体传感器设备条件。
zh$
en^
Create a person ir device condition.
en$

@param device The device model to create condition.
@param dpModel The dpModel to create condition.
@param exprModel Create with WSSmartSceneConditionExprBuilder.
@return WiserSmartSceneConditionModel object.
*/
+ (WiserSmartSceneConditionModel *)createPirConditionWithDevice:(WiserSmartDeviceModel *)device dpModel:(WiserSmartSceneDPModel *)dpModel exprModel:(WiserSmartSceneExprModel *)exprModel;

/**
 zh^
 创建一个气象条件。
 zh$
 en^
 Create an whether condition.
 en$

 @param city Whether condition need a city.
 @param dpModel The whether datapoint.
 @param exprModel Create with WSSmartSceneConditionExprBuilder.
 @return WiserSmartSceneConditionModel object.
 */
+ (WiserSmartSceneConditionModel *)createWhetherConditionWithCity:(WiserSmartCityModel *)city dpModel:(WiserSmartSceneDPModel *)dpModel exprModel:(WiserSmartSceneExprModel *)exprModel;

/**
 zh^
 创建一个定时条件。
 zh$
 en^
 Create a timer condition.
 en$

 @param exprModel Create with WSSmartSceneConditionExprBuilder.
 @return WiserSmartSceneConditionModel object.
 */
+ (WiserSmartSceneConditionModel *)createTimerConditionWithExprModel:(WiserSmartSceneExprModel *)exprModel;

/**
zh^
创建一个和日出日落时间相关的定时条件。
zh$
en^
Create a timer condition related to sunrise and sunset times
en$

@param city City to be operated.
@param exprModel Create with WSSmartSceneConditionExprBuilder.
@return WiserSmartSceneConditionModel object.
*/
+ (WiserSmartSceneConditionModel *)createSunsetriseTimerConditionWithCity:(WiserSmartCityModel *)city ExprModel:(WiserSmartSceneExprModel *)exprModel;

/**
 zh^
 创建地理围栏条件，保存之后返回的conditionModel会生成entityId，上报这个entityId代表触发了地理围栏。
 zh$
 en^
 Create a GeoFence conditon,conditionModel's entityId will be assigned after scene saved, the entityId represent the geoFence id, will should be upload to server by http API to trigger the automation.
 en$

 @param type zh^ 离开或者到达类型 zh$ en^ reach or leave the place en$
 @param latitude zh^ 纬度 zh$ en^ latitude en$
 @param longitude zh^ 经度 zh$ en^ longitude en$
 @param radius zh^ 以经纬度为圆心的半径 zh$ en^ consider latitude and longitude as the center of a circle, this property represent the radius. en$
 @param geoTitle zh^ 定位地点名称 zh$ en^ lacation name en$
 @return condition model
 */
+ (WiserSmartSceneConditionModel *)createGeoFenceConditionWithGeoType:(GeoFenceType)type geoLati:(CGFloat)latitude geoLonti:(CGFloat)longitude geoRadius:(CGFloat)radius geoTitle:(NSString *)geoTitle;


/**
 zh^
 创建一个”手动执行“条件。这个条件不应该被保存到云端，在调用保存智能接口的时候，应该删除掉这个条件。
 zh$
 en^
 Create an "manual execute" condition.This condition should not be saved to cloud server, when you call the API to save a smart, you should delete this type of condition first.
 en$

 @return condition model
 */
+ (WiserSmartSceneConditionModel *)createManualExecuteCondition;

@end

