//
//  WiserSmartMQTTChannel.h
//  WiserSmart
//
//
//  Copyright (c) 2015年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WiserSmartMQTTConfigModel.h"

@interface WiserSmartPublishMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;

@property (nonatomic, assign) NSTimeInterval    time; // time stamp
@property (nonatomic, assign) NSInteger         protocol; // protocol
@property (nonatomic, assign) double            pv; // version
@property (nonatomic, strong) NSDictionary      *body; // body
@property (nonatomic, strong) NSString          *localKey; // local key
@property (nonatomic, assign) NSInteger         publishS;// sequence
@property (nonatomic, assign) NSInteger         publishR;// publish Id

@end

@interface WiserSmartResponseMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;
@property (nonatomic, strong) id                message;  // mesh array
@property (nonatomic, assign) NSInteger         protocol; // protocol
@property (nonatomic, strong) NSString          *type;
@property (nonatomic, assign) NSInteger         responseS;// sequence
@property (nonatomic, assign) NSInteger         responseR;// response Id

@end

@class WiserSmartMQTTChannel;

/**
 mqtt connect state
 */
typedef NS_ENUM (NSInteger, WiserSmartMqttConnectState){
    WiserSmartMqttConnectStateCreated,
    WiserSmartMqttConnectStateConnecting,
    WiserSmartMqttConnectStateConnected,
    WiserSmartMqttConnectStateDisconnecting,
    WiserSmartMqttConnectStateClose,
    WiserSmartMqttConnectStateError,
};

@protocol WiserSmartMQTTChannelDelegate <NSObject>

@optional

/**
 *  mqtt connection channel state changes
 *  mqtt 连接的状态改变回调
 */
- (void)mqttChannel:(WiserSmartMQTTChannel *)mqttChannel connectState:(WiserSmartMqttConnectState)connectState error:(NSError *)error;

/**
 *  Receive mqtt data
 *  收到mqtt消息上报
 */
- (void)mqttChannel:(WiserSmartMQTTChannel *)mqttChannel didReceiveMessage:(WiserSmartResponseMessageModel *)message topic:(NSString *)topic;

@end


@interface WiserSmartMQTTChannel : NSObject

+ (instancetype)sharedInstance;

/**
 *  connect mqtt host
 *  建立 mqtt 连接
 *
 *  @param mqttConfig mqttConfig
 */
- (void)startConnectToHostWithMqttConfig:(WiserSmartMQTTConfigModel *)mqttConfig;

/**
 *  close mqtt host
 *  关闭mqtt连接
 */
- (void)close;

/**
 *  mqtt connect state
 *  mqtt 连接状态
 */
- (WiserSmartMqttConnectState)connectState;

/**
 *  subscribe topic
 *  订阅主题
 *
 *  @param topic   Topic
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)subscribeToTopic:(NSString *)topic
                 devInfo:(NSDictionary *)devInfo
                 success:(WSSuccessHandler)success
                 failure:(WSFailureError)failure;

/**
 *  unsubscribe topic
 *  取消订阅主题
 *
 *  @param topic   Topic
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)unsubscribeToTopic:(NSString *)topic
                   success:(WSSuccessHandler)success
                   failure:(WSFailureError)failure;

/**
 *  推送mqtt消息
 *  publish mqtt data
 *
 *  @param data    Data
 *  @param topic   Topic
 *  @param success Success block
 *  @param failure Failure block
 *  @return the Message Identifier of the publish message. Zero if qos 0. If qos 1 or 2, zero was publish faliure
 */
- (UInt16)publishMessage:(NSData *)data
                   topic:(NSString *)topic
                 success:(WSSuccessHandler)success
                 failure:(WSFailureError)failure;

/**
 *  推送mqtt消息
 *  publish mqtt data
 *
 *  @param messageModel MessageModel
 *  @param topic        Topic
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)publishMessageWithMessageModel:(WiserSmartPublishMessageModel *)messageModel
                                 topic:(NSString *)topic
                               success:(WSSuccessHandler)success
                               failure:(WSFailureError)failure;

/**
 *  add mqtt channel delegate
 *  添加mqtt长连接的代理
 *
 *  @param delegate Delegate
 */
- (void)addDelegate:(id<WiserSmartMQTTChannelDelegate>)delegate;

/**
 *  remove mqtt channel delegate
 *  删除mqtt长连接的代理
 *
 *  @param delegate Delegate
 */
- (void)removeDelegate:(id<WiserSmartMQTTChannelDelegate>)delegate;

@end
