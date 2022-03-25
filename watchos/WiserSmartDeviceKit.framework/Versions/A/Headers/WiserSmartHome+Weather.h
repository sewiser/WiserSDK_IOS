//
// WiserSmartHome+Weather.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import "WiserSmartHome.h"

@class WiserSmartWeatherModel;
@class WiserSmartWeatherSketchModel;
@class WiserSmartWeatherOptionModel;

@interface WiserSmartHome (Weather)

/// Home location
- (NSString *)geoName;

/// Get brief weather parameters for the home. This request returns brief weather parameters for the city where the family is located, such as the city name, weather conditions for the day (sunny, cloudy, rainy, etc.), and weather picture information.
/// @param success Called when the task finishes successfully. WiserSmartWeatherSketchModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeWeatherSketchWithSuccess:(void(^)(WiserSmartWeatherSketchModel *))success
                                failure:(WSFailureError)failure;


/// Get detailed parameters of home weather, such as temperature, humidity, UV index, air quality, etc.
///
///optionModel can be nil. if it is nil, the returned parameter will be the parameter setting of the last successful request. if only one unit setting is changed for the request, the other two will remain the parameter setting of the last successful request.
///
///Due to the different services used by weather services in different regions, the parameters returned may differ from region to region. In particular, if the current home account location is in China, then wind speed and barometric pressure information will not be returned.
///
/// @param optionModel Weather details parameter unit configuration.
/// @param success Called when the task finishes successfully. A list of WiserSmartWeatherModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeWeatherDetailWithOption:(WiserSmartWeatherOptionModel *)optionModel
                         success:(void(^)(NSArray<WiserSmartWeatherModel *> *))success
                         failure:(WSFailureError)failure;

@end
