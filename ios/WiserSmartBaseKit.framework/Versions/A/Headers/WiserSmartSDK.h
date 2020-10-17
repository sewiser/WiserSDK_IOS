//
//  WiserSmartSDK.h
//  WiserSmartKit
//
//
//  Copyright (c) 2015年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartSDK
#define WiserSmart_WiserSmartSDK

#import <WiserSmartUtil/WiserSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, WSEnv) {
    WSEnvDaily,
    WSEnvPrepare,
    WSEnvRelease,
};

@interface WiserSmartSDK : NSObject

/**
 Singleton

 @return instance
 */
+ (instancetype)sharedInstance;

/**
 *  Application group identifier
 *  If you want to use the SDK in app extension, set `appGroupId` before SDK initialized both in app & app extension.
 *  如果需要开发APP Extension，请在初始化SDK的时候设置 appGroupId
 */
@property (nonatomic, strong) NSString *appGroupId;

/// Latitude of the loaction
@property (nonatomic, assign) double latitude;

/// Longitude of the loaction
@property (nonatomic, assign) double longitude;

/// Server environment, daily/prepare/release. For test only. Not recommended to switch
/// 测试环境，不建议切换
@property (nonatomic, assign) WSEnv env;

/// Request need SSL Pinning, default is `YES`
/// 请求都进行 SSL Pining 校验，默认为 `YES`
@property (nonatomic, assign) BOOL useSSLPinning;

@property (nonatomic, strong, readonly) NSString *appKey;

@property (nonatomic, strong, readonly) NSString *secretKey;

/// Channel
@property (nonatomic, strong) NSString *channel;

/// uuid of the iOS/watchOS device. Will be created at app first launch.
@property (nonatomic, strong, readonly) NSString *uuid;

/**
 *  App version, default value is from Info.plist -> CFBundleShortVersionString
 *  App 版本号，默认为 Info.plist -> CFBundleShortVersionString 中的值
 */
@property (nonatomic, strong) NSString *appVersion;

/**
 * Device product name. For example: iPhone XS Max.
 * 设备产品名称，例如：iPhone XS Max.
 */
@property (nonatomic, strong) NSString *deviceProductName;

/**
 *  App sdk lang, default value is from mainBundle -> preferredLocalizations -> [0]
 *  App sdk 语言，默认为mainBundle -> preferredLocalizations -> [0] 中的值
 */
@property (nonatomic, strong) NSString *lang;

/**
 *  Initialize WiserSmart SDK
 *  初始化涂鸦智能SDK
 *
 *  @param appKey    WiserSmart AppKey
 *  @param secretKey WiserSmart SecretKey
 */
- (void)startWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;

/**
 *  Report location if needed
 *
 *  @param latitude latitude
 *  @param longitude longitude
 */
- (void)updateLatitude:(double)latitude longitude:(double)longitude;

@end


@interface WiserSmartSDK (Upgrade)

/**
 *  Check if WiserSmartKit need to be upgrade to WiserSmartHomeKit
 *  检测是否需要升级数据 从WiserSDK 升级到WiserHomeSDK，需要进行数据升级
 *
 *  @return Whether need to upgrade data
 */
- (BOOL)checkVersionUpgrade;

/**
 *  SDK data upgrade
 *  SDK数据升级
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)upgradeVersion:(nullable WSSuccessHandler)success
               failure:(nullable WSFailureError)failure;

@end


@interface WiserSmartSDK (PushNotification)

/// Push token
@property (nonatomic, strong) NSString *pushToken DEPRECATED_MSG_ATTRIBUTE("Use +[WiserSmartSDK sharedInstance].deviceToken instead.");

/// Push deviceToken
@property (nonatomic, strong) NSData *deviceToken;

/**
 *  Set push device token and error info
 *  设置推送token以及错误信息
 *  @param token    deviceToken
 *  @param error    error info
 */
- (void)setDeviceToken:(nullable NSData *)token withError:(nullable NSError *)error;

/**
 *  Get notification push status
 *  获取 APP 消息推送的开启状态
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getPushStatusWithSuccess:(__nullable WSSuccessBOOL)success failure:(__nullable WSFailureError)failure;

/**
 *  Set notification push status
 *  开启或者关闭 APP 消息推送
 *
 *  @param enable      open or close
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)setPushStatusWithStatus:(BOOL)enable success:(__nullable WSSuccessHandler)success failure:(__nullable WSFailureError)failure;



/**
 *  Get device alarm push status
 *  获取 APP 设备告警通知的开启状态
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getDevicePushStatusWithSuccess:(__nullable WSSuccessBOOL)success failure:(__nullable WSFailureError)failure;

/**
 *  Set device alarm push status
 *  开启或者关闭 APP 设备告警推送消息
 *
 *  @param enable      open or close
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)setDevicePushStatusWithStauts:(BOOL)enable success:(__nullable WSSuccessHandler)success failure:(__nullable WSFailureError)failure;

/**
 *  Get family message push status
 *  获取 APP 家庭通知的开启状态
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getFamilyPushStatusWithSuccess:(__nullable WSSuccessBOOL)success failure:(__nullable WSFailureError)failure;

/**
 *  Set family message push status
 *  开启或者关闭 APP 家庭推送消息
 *
 *  @param enable      open or close
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)setFamilyPushStatusWithStauts:(BOOL)enable success:(__nullable WSSuccessHandler)success failure:(__nullable WSFailureError)failure;

/**
 *  Get notice message push status
 *  获取 APP 消息通知的开启状态
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getNoticePushStatusWithSuccess:(__nullable WSSuccessBOOL)success failure:(__nullable WSFailureError)failure;

/**
 *  Set notice message push status
 *  开启或者关闭 APP 消息通知推送
 *
 *  @param enable      open or close
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)setNoticePushStatusWithStauts:(BOOL)enable success:(__nullable WSSuccessHandler)success failure:(__nullable WSFailureError)failure;

/**
 *  Get market message push status
 *  获取 APP 营销类消息的开启状态
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getMarketingPushStatusWithSuccess:(__nullable WSSuccessBOOL)success failure:(__nullable WSFailureError)failure;

/**
 *  Set market message push status
 *  开启或者关闭 APP 营销类消息推送
 *
 *  @param enable      open or close
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)setMarketingPushStatusWithStauts:(BOOL)enable success:(__nullable WSSuccessHandler)success failure:(__nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
