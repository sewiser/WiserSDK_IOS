//
// WiserSmartWeatherOptionModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    WiserSmartWeatherOptionPressureUnit_unknown = 0,
    WiserSmartWeatherOptionPressureUnit_hPa = 1,
    WiserSmartWeatherOptionPressureUnit_inHg = 2,
    WiserSmartWeatherOptionPressureUnit_mmHg = 3,
    WiserSmartWeatherOptionPressureUnit_mb = 4,
} WiserSmartWeatherOptionPressureUnit;

typedef enum : NSUInteger {
    WiserSmartWeatherOptionWindSpeedUnit_unknown = 0,
    WiserSmartWeatherOptionWindSpeedUnit_mph = 1,
    WiserSmartWeatherOptionWindSpeedUnit_m_s = 2,// m/s
    WiserSmartWeatherOptionWindSpeedUnit_kph = 3,
    WiserSmartWeatherOptionWindSpeedUnit_km_h = 4// km/h
} WiserSmartWeatherOptionWindSpeedUnit;

typedef enum : NSUInteger {
    WiserSmartWeatherOptionTemperatureUnit_unknown = 0,
    WiserSmartWeatherOptionTemperatureUnit_Centigrade = 1,// ℃
    WiserSmartWeatherOptionTemperatureUnit_Fahrenheit = 2,// ℉
} WiserSmartWeatherOptionTemperatureUnit;

NS_ASSUME_NONNULL_BEGIN

/// Get home weather request entry.
@interface WiserSmartWeatherOptionModel : NSObject

/// Barometric unit.
@property (nonatomic, assign) WiserSmartWeatherOptionPressureUnit pressureUnit;

/// Wind speed unit
@property (nonatomic, assign) WiserSmartWeatherOptionWindSpeedUnit windspeedUnit;

/// Temperature units
@property (nonatomic, assign) WiserSmartWeatherOptionTemperatureUnit temperatureUnit;

/// The number of requests for weather details, if not configured, all are returned by default.
@property (nonatomic, assign) NSInteger limit;

@end

NS_ASSUME_NONNULL_END
