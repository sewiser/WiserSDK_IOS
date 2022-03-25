//
//  WiserSmartSocketChannel.h
//
//
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartSocketReadModel.h"
#import "WiserSmartSocketWriteModel.h"
#import <WiserSmartBaseKit/WiserSmartBaseKit.h>

// 协议
#define SOCKET_TYPE_BROADCAST             0x00
#define SOCKET_TYPE_BROADCAST_V4          0x13
#define SOCKET_TYPE_BROADCAST_V34         0x23
#define SOCKET_TYPE_AP_ERROR              0x15
#define SOCKET_TYPE_AP_CONFIG             0x01
#define SOCKET_TYPE_AP_ACTIVATE           0x02
#define SOCKET_TYPE_DP_PUBLISH            0x07
#define SOCKET_TYPE_DP_REPORT             0x08
#define SOCKET_TYPE_HEARTBEAT             0x09
#define SOCKET_TYPE_QUERY_DEV_INFO        0x0a
#define SOCKET_TYPE_QUERY_SSID_LIST       0x0b
#define SOCKET_TYPE_DP_CAD_PUBLISH        0x0d
#define SOCKET_TYPE_LOCL_SCENE_EXE        0x11
#define SOCKET_TYPE_ENABLE_LOG            0x20
#define SOCKET_TYPE_BIND_TOKEN            0x0c
#define SOCKET_TYPE_ACTIVE_SUBDEV         0x0e
#define SOCKET_TYPE_QUERY_CAD_DEV_INFO    0x10
#define SOCKET_TYPE_INITIATIVE_QUERY_DPS  0x12
#define SOCKET_TYPE_AP_CONFIG             0x01
#define SOCKET_TYPE_AP_CONFIG_NEW         0x14
#define SOCKET_TYPE_AP_CONFIG_BROADCAST   0x11

#define SOCKET_TYPE_HANDSHAKE_RAND_A      0x03
#define SOCKET_TYPE_HANDSHAKE_RAND_B      0x04
#define SOCKET_TYPE_HANDSHAKE_RAND_ACK_B  0x05

#define SOCKET_TYPE_IPC_AP_SET_PWD        0x21


@class WiserSmartSocketChannel;

@protocol WiserSmartSocketChannelDelegate <NSObject>

@optional

#pragma mark - TCP Delegate

// TCP Connection Successful
- (void)socketDidTcpConnected:(WiserSmartSocketChannel *)socket devId:(NSString *)devId;

// Receive TCP message
- (void)socket:(WiserSmartSocketChannel *)socket didReceiveTcpData:(WiserSmartSocketReadModel *)tcpData tag:(long)tag devId:(NSString *)devId;

// TCP disconnection
- (void)socketDidTcpDisconnect:(WiserSmartSocketChannel *)socket devId:(NSString *)devId error:(NSError *)error;


#pragma mark - UDP Delegate

// Receive UDP message
- (void)socket:(WiserSmartSocketChannel *)socket didReceiveUdpData:(WiserSmartSocketReadModel *)udpData;

// Close UDP connection
- (void)socketDidUdpClose:(WiserSmartSocketChannel *)socket error:(NSError *)error;

@end

@interface WiserSmartSocketChannel : NSObject

+ (instancetype)sharedInstance;

/**
 *  未激活的设备列表
 */
@property (nonatomic, strong) WSSDKSafeMutableDictionary   *inactiveDevices;

@property (nonatomic, strong) WSSDKSafeMutableDictionary    *HKDFDic;

#pragma mark - TCP

// connect TCP
- (void)initTcpClientWithHost:(NSString *)host devInfo:(NSDictionary *)devInfo;

// send TCP message
- (void)sendTcpRequest:(WiserSmartSocketWriteModel *)request
               success:(WSSuccessDict)success
               failure:(WSFailureHandler)failure __deprecated_msg("This method is deprecated, Use sendTcpWithRequest:success:failure: instead");

// send TCP message
- (void)sendTcpWithRequest:(WiserSmartSocketWriteModel *)request
                   success:(WSSuccessDict)success
                   failure:(WSFailureError)failure;

- (void)removeInactiveDevice:(NSString *)gwId;

- (void)removeAllInactiveDevice;

// whether the TCP connection
- (BOOL)hasTcpClientWithDevId:(NSString *)devId;

// close TCP connect
- (void)closeTcpClientWithDevId:(NSString *)devId;

// close all TCP connect
- (void)closeAllTcpClient;

#pragma mark - UDP

// init UDP serve
- (void)initUdpServerWithPort:(NSInteger)port;

// send UDP message
- (void)sendUdpRequestWithHost:(NSString *)host port:(NSInteger)port type:(int)type body:(NSDictionary *)body success:(WSSuccessHandler)success failure:(WSFailureHandler)failure;

- (void)sendUdpRequestWithHost:(NSString *)host port:(NSInteger)port type:(int)type body:(NSDictionary *)body lpv:(NSString *)lpv success:(WSSuccessHandler)success failure:(WSFailureHandler)failure;

// close UDP serve
- (void)closeUdpServerWithPort:(uint16_t)port;

#pragma mark - Delegate

// add socket channel delegate
- (void)addDelegate:(id<WiserSmartSocketChannelDelegate>)delegate;

// remove socket channel delegate
- (void)removeDelegate:(id<WiserSmartSocketChannelDelegate>)delegate;

@end

