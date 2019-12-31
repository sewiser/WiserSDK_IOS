//
//  WiserSmartWeattherOptionModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    WiserSmartWeattherOptionPressureUnit_unknown = 0,
    WiserSmartWeattherOptionPressureUnit_hPa = 1,
    WiserSmartWeattherOptionPressureUnit_inHg = 2,
    WiserSmartWeattherOptionPressureUnit_mmHg = 3,
    WiserSmartWeattherOptionPressureUnit_mb = 4,
} WiserSmartWeattherOptionPressureUnit;

typedef enum : NSUInteger {
    WiserSmartWeattherOptionWindSpeedUnit_unknown = 0,
    WiserSmartWeattherOptionWindSpeedUnit_mph = 1,
    WiserSmartWeattherOptionWindSpeedUnit_m_s = 2,// m/s
    WiserSmartWeattherOptionWindSpeedUnit_kph = 3,
    WiserSmartWeattherOptionWindSpeedUnit_km_h = 4// km/h
} WiserSmartWeattherOptionWindSpeedUnit;

typedef enum : NSUInteger {
    WiserSmartWeattherOptionTemperatureUnit_unknown = 0,
    WiserSmartWeattherOptionTemperatureUnit_Centigrade = 1,// ℃
    WiserSmartWeattherOptionTemperatureUnit_Fahrenheit = 2,// ℉
} WiserSmartWeattherOptionTemperatureUnit;

NS_ASSUME_NONNULL_BEGIN

/**
 * 获取家庭天气请求入参
 */
@interface WiserSmartWeatherOptionModel : NSObject

/// 气压单位
@property (nonatomic, assign) WiserSmartWeattherOptionPressureUnit pressureUnit;

/// 风速单位
@property (nonatomic, assign) WiserSmartWeattherOptionWindSpeedUnit windspeedUnit;

/// 温度单位
@property (nonatomic, assign) WiserSmartWeattherOptionTemperatureUnit temperatureUnit;

/// 请求多少个天气详情，若不配置，则默认全部返回
@property (nonatomic, assign) NSInteger limit;

@end

NS_ASSUME_NONNULL_END
