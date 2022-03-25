//
// WiserSmartDeviceCoreKitErrors.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartDeviceCoreKitErrors_h
#define WiserSmartDeviceCoreKitErrors_h

/*
 *  WSDeviceCoreKitError
 *
 *  Discussion:
 *    Error returned as code to NSError from WiserSmartDeviceKit.
 */
extern NSString *const kWSDeviceCoreKitErrorDomain;

/// The device core kit errors define.
typedef NS_ENUM(NSInteger, WSDeviceCoreKitError) {
    /// The device does not support a certain capability (capability reported on the device dimension).
    kWSDeviceCoreKitErrorDeviceNotSupport                      = 3000,
    /// LAN downstream data failure.
    kWSDeviceCoreKitErrorSocketSendDataFailed                  = 3001,
    /// DPS command is empty.
    kWSDeviceCoreKitErrorEmptyDpsData                          = 3002,
    /// Group device is empty.
    kWSDeviceCoreKitErrorGroupDeviceListEmpty                  = 3003,
    /// Group ID length error.
    kWSDeviceCoreKitErrorGroupIdLengthError                    = 3004,
    /// Illegal dps, see product dp definition.
    kWSDeviceCoreKitErrorIllegalDpData                         = 3005,
    /// Device ID length error.
    kWSDeviceCoreKitErrorDeviceIdLengthError                   = 3006,
    /// Missing local key.
    kWSDeviceCoreKitErrorDeviceLocalKeyNotFound                = 3007,
    /// Product ID length error.
    kWSDeviceCoreKitErrorDeviceProductIDLengthError            = 3008,
    
};

#endif /* WiserSmartDeviceCoreKitErrors_h */
