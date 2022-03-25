//
// WiserSmartHomeModelUtils.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartHomeModelUtils_h
#define WiserSmartHomeModelUtils_h

typedef NS_ENUM(NSInteger, WSHomeRoleType) {
    WSHomeRoleType_Unknown = -999,  /**< Invalid role */
    WSHomeRoleType_Custom  = -1,  /**< Customized role */
    WSHomeRoleType_Member  = 0,   /**< General family member */
    WSHomeRoleType_Admin,         /**< Family administrator, no add delete other administrator privileges. */
    WSHomeRoleType_Owner,         /**< Family super administrator, owner */
};

typedef NS_ENUM(NSUInteger, WSHomeStatus) {
    WSHomeStatusPending = 1,      /**< To be joined, invitees have not decided whether to join the corresponding family */
    WSHomeStatusAccept,           /**< Invitees have agreed to join the corresponding family */
    WSHomeStatusReject            /**< Invitees have declined to join the corresponding family */
};

#endif /* WiserSmartHomeModelUtils_h */
