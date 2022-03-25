//
// WiserSmartCommunicationMode.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Communication type
typedef NS_ENUM(NSUInteger, WSCommunicationType) {
    WSCommunicationTypeLAN      = 0, // LAN
    WSCommunicationTypeMQTT     = 1, // MQTT
    WSCommunicationTypeHTTP     = 2, // Http
    WSCommunicationTypeBLE      = 3, // Single Point Bluetooth
    WSCommunicationTypeSIGMesh  = 4, // Sig Mesh
    WSCommunicationTypeBLEMesh  = 5, // Wiser Private Mesh
    WSCommunicationTypeBLEBeacon  = 6, // beaocn
};

/// Communication mode
@interface WiserSmartCommunicationMode : NSObject

/// Communication protocol version
@property (nonatomic, assign) double pv;

/// Communication Protocol Type
@property (nonatomic, assign) WSCommunicationType type;

@end

/// Device communication
@interface WiserSmartCommunication : NSObject

/// Communication sequence
@property (nonatomic, strong) NSArray<WiserSmartCommunicationMode *> *communicationModes;

/// Communication Nodes
@property (nonatomic, strong) NSString *communicationNode;

@end

NS_ASSUME_NONNULL_END
