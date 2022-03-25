//
// WiserSmartSingleTransfer.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WiserSmartTransferState) {
    WiserSmartTransferConnected = 1, // Connected
    WiserSmartTransferDisconnected, // Disconnected
};

@class WiserSmartSingleTransfer;
@protocol WiserSmartTransferDelegate<NSObject>

/// When the connection state changes, the delegate will execute.
/// @param transfer transfer.
/// @param state WiserSmartTransferState.
- (void)transfer:(WiserSmartSingleTransfer *)transfer didUpdateConnectState:(WiserSmartTransferState)state;

/// When received device data, the delegate will execute.
/// @param transfer transfer.
/// @param devId Device Id.
/// @param data Received Data.
- (void)transfer:(WiserSmartSingleTransfer *)transfer didReciveDataWithDevId:(NSString *)devId data:(NSData *)data;

@end

__deprecated_msg("The channel already merged. We will provide new way to support it.")
@interface WiserSmartSingleTransfer : NSObject

/// @deprecated Data flow channel, currently deprecated.
///
/// Can use WiserSmartMQTTChannelDelegate to receive data.
///
@property (nonatomic, weak) id<WiserSmartTransferDelegate> delegate;

#if TARGET_OS_IOS

/// Start Connect.
- (void)startConnect;

/// The connection state.
/// @return Connection Result.
- (BOOL)isConnected;

/// Close the channel; Because of channel merging, it will not be closed because it will affect the normal device subscription process.
- (void)close __deprecated_msg("will remove it");;

/// Subscribe device.
/// @param devId The device ID.
- (void)subscribeDeviceWithDevId:(NSString *)devId;

/// Unsubscribe device.
/// @param devId The device ID.
- (void)unsubscribeDeviceWithDevId:(NSString *)devId;

#endif

@end

