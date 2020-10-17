//
//  WiserSmartSceneConditionExprBuilder.h
//  WiserSmartSceneKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartSceneExprModel.h"

typedef enum : NSInteger {
    kExprTypeWhether,
    kExprTypeDevice
}ExprType;

typedef enum : NSInteger {
    kSunTypeNotDetermin,
    kSunTypeRise,
    kSunTypeSet
}SunType;

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartSceneConditionExprBuilder : NSObject

/**
 zh^
 创建值为bool类型的条件的expr数据对象, 如“开关”这种布尔型dp点类型创建条件时使用。
 zh$
 en^
 Create a exprModel with bool value and condition type.
 en$

 @param type Whether type or device's dpId.
 @param isTrue BOOL value.
 @param exprType To distinguish the entity type.
 @return An ExprModel object.
 */
+ (WiserSmartSceneExprModel *)createBoolExprWithType:(NSString *)type isTrue:(BOOL)isTrue exprType:(ExprType)exprType;

/**
 zh^
 创建值为枚举类型类型的条件的expr数据对象。
 zh$
 en^
 Create a exprModel with enum string value and condition type.
 en$

 @param type Whether type or device's dpId.
 @param chooseValue enum string value, get it in WiserSmartSceneDPModel.dpModel.property.range
 @param exprType To distinguish the entity type.
 @return An ExprModel object.
 */
+ (WiserSmartSceneExprModel *)createEnumExprWithType:(NSString *)type chooseValue:(NSString *)chooseValue exprType:(ExprType)exprType;

/**
 zh^
 创建值为“temp <= 40”形式的expr数据对象。
 zh$
 en^
 Create exprModel like "temp <= 40".
 en$

 @param type Whether type or device's dpId.
 @param operateString @"==",@"<=",@"=="
 @param value selected value
 @param exprType To distinguish the entity type.
 @return An ExprModel object.
 */
+ (WiserSmartSceneExprModel *)createValueExprWithType:(NSString *)type operater:(NSString *)operateString chooseValue:(NSInteger )value exprType:(ExprType)exprType;

/**
zh^
创建值为“rawType”形式的expr数据对象。
zh$
en^
Create exprModel like "rawType".
en$

@param type Whether type or device's dpId.
@param exprType To distinguish the entity type.
@return An ExprModel object.
*/
+ (WiserSmartSceneExprModel *)createRawExprWithType:(NSString *)type exprType:(ExprType)exprType;

/**
 zh^
 创建定时器条件。
 zh$
 en^
 Create timer condition.
 en$

 @param timeZoneId timeZoneId like @"Asia/Shanghai"
 @param loops eg: @"0111110", each charactor represent from Sunday to Monday. @"0000000" represent only once.
 @param date eg: @"20190501"
 @param time eg: @"20:40"
 @return An ExprModel object.
 */
+ (WiserSmartSceneExprModel *)createTimerExprWithTimeZoneId:(NSString *)timeZoneId loops:(NSString *)loops date:(NSString *)date time:(NSString *)time;

/**
zh^
创建一个和日出日落时间相关的定时条件表达式，如「日出前x分钟」。「日出时」依然作为一个普通天气条件来处理。
zh$
en^
Create a timer condition's expression related to sunrise or sunset times, For example, "x minutes before sunrise". "at sunrise" is still handled as a normal weather condition.
en$

@param city City that needs to be set
@param type Identify sunrise or sunset
@param minutes From -300 minutes to 300 minutes
@return An ExprModel object.
*/
+ (WiserSmartSceneExprModel *)createSunsetriseTimerExprWithCity:(WiserSmartCityModel *)city type:(SunType)type deltaMinutes:(NSInteger)minutes;

@end

NS_ASSUME_NONNULL_END

