//
// WiserSmartMessageUtils.h
// WiserSmartMessageKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartMessageUtils_h
#define WiserSmartMessageUtils_h

/// The three types of message. Provides alarm, family and notice types.
typedef NS_ENUM(NSInteger, WSMessageType) {
    /// The alarm message type.
    WSMessageTypeAlarm = 1,
    /// The family message type.
    WSMessageTypeFamily,
    /// The notice message type.
    WSMessageTypeNotice,
};

#endif /* WiserSmartMessageUtils_h */
