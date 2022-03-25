//
//  WiserSmartSceneConditionModel.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import "WiserSmartSceneDPModel.h"

#import <CoreLocation/CoreLocation.h>

/// The two  expression type in condition. Provide precise and simple types.
typedef NS_ENUM(NSInteger, WSSConditionExpressionType) {
    /// Precise expression type, including specific equations. eg: $dp110 == 1、$dp111 > 1000、$dp113 < 400.
    WSSConditionExpressionTypePrecise = 1,
    /// Simple expression type, excluding equation. eg: $dp112
    WSSConditionExpressionTypeSimple
};

/// The four status of scene condition. Provide loading, success, offline and timeout status.
typedef NS_ENUM(NSInteger, WSSceneConditionStatus) {
    /// The loading scene condition status.
    WSSceneConditionStatusLoading = 0,
    /// The success scene condition status.
    WSSceneConditionStatusSuccess,
    /// The offline scene condition status.
    WSSceneConditionStatusOffline,
    /// The timeout scene condition status.
    WSSceneConditionStatusTimeout,
};

/// The condition auto type.
typedef NS_ENUM(NSInteger, WSConditionAutoType) {
    /// The device auto type.
    AutoTypeDevice = 1,
    /// The whether auto type.
    AutoTypeWhether = 3,
    /// The timer auto type.
    AutoTypeTimer = 6,
    /// The pir sensor auto type.
    AutoTypePir = 7,
    /// The face recognition auto type.
    AutoTypeFaceRecognition = 9,
    /// The geo auto type.
    AutoTypeGeofence = 10,
    /// The lock member go home auto type.
    AutoTypeLockMemberGoHome = 11,
    /// The condition calculate auto type. As a bd last x hours
    AutoTypeConditionCalculate = 13,
    /// The sun set od rise timer auto type. As x minutes before sunrise.
    AutoTypeSunsetriseTimer = 16,
    /// The manual auto type. This type of condition should not be saved to server, and server will not return this type of condition neither.
    AutoTypeManual = 99,
};

/// @brief Condition data model for scene.
@interface WiserSmartSceneConditionModel : NSObject<NSCoding>

/// The condition id.
@property (nonatomic, copy) NSString *conditionId;

/// The url of condition icon.
@property (nonatomic, copy) NSString *iconUrl;

/// The city id. If this condition is a meteorological condition, devId if this is a device condition, @"timer" if this is a timer condition.
@property (nonatomic, copy) NSString *entityId;

/// The city name. If this is a meteorological condition, device name if this is a device condition, @"timer" if this is a timer condition.
@property (nonatomic, copy) NSString *entityName;

/// The entity type. Device as condition it will be NSInteger 1, 3 for meteorological condition, 6 for timer condition, 7 for human body detector condition, 10 for  geofencing condition.
@property (nonatomic, assign) WSConditionAutoType entityType;

/// Description of condition, like "Switch : Open","Humidity : Comfort"
@property (nonatomic, copy) NSString *exprDisplay;

/// The scene id ,can be used to save the scene's Id which this action belonged to.
@property (nonatomic, copy) NSString *scenarioId;

/// Meteorological condition's subId or device's dpId, timer condition is "timer".
@property (nonatomic, copy) NSString *entitySubIds;

/// Condition's expression, like
/// ("$humidity","==","comfort") or（“$dp1”，“==”，1）
/// timer：{timeZoneId = "Asia/Shanghai",loops = "0000000",time = "08:00",date = "20180308"}
/// loops = "0000000" ,each bit representing from Sunday to Saturday.
/// Details in Doc: https://wiserinc.github.io/wisersmart_home_ios_sdk_doc/en/resource/SmartScene.html#smart-scene
@property (nonatomic, strong) NSArray *expr;

/// The condition status, see WSSceneConditionStatus enum.
@property (nonatomic, assign) WSSceneConditionStatus status;

/// Unit of temperature, or geofence detail, {"tempUnit":"fahrenheit","Hangzhou City":"cityName"}，{"center":{"latitude":30.273173191721956,"longitude":120.09600875035049},"geotitle":"xxx","radius":180.00011311593616}}.
@property (nonatomic, strong) NSDictionary *extraInfo;

/// If this condition is a device type condition and this device has been removed from the current account, this flag is YES.
@property (nonatomic, assign) BOOL devDelMark;

/// If this condition is a device type condition, and this device has been removed from the current account, then provide this icon url to display the device icon.
@property (nonatomic, copy) NSString *deleteDevIcon;

/// The city name
@property (nonatomic, copy) NSString *cityName;

/// The city latitude
@property (nonatomic, assign) CLLocationDegrees cityLatitude;

/// The city longitude
@property (nonatomic, assign) CLLocationDegrees cityLongitude;

#pragma mark - Recommend info

/// Recommend product id.
@property (nonatomic, copy) NSString *productId;

/// Recommend product icon.
@property (nonatomic, copy) NSString *productPic;

/// Recommend product local default icon.
@property (nonatomic, copy) NSString *defaultIconUrl;

#pragma mark - Expression Type

///The expression type for condition. see more: WSSConditionExpressionType.
///
///eg: ("$humidity","==","comfort") Indicates Precise matching mode, including (==, >, <) specific equations. It includes all the DP description types in the condition are enum, value, bool, etc. When the dp type equal enum, value, bool, you can use WSSConditionExpressionTypePrecise.
///eg: （"$dp1"）Indicates simple matching mode, excluding an equation. The DP description types in the condition is only string and raw. When the dp type equal string or raw，you can use WSSConditionExpressionTypeSimple.
@property (nonatomic, assign) WSSConditionExpressionType conditionExpressionType;

@end
