//
// WiserSmartMessageRequestModel.h
// WiserSmartMessageKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// Message center message list request model.
@interface WiserSmartMessageListRequestModel : NSObject

/// Message type.
@property (nonatomic, assign) WSMessageType msgType;

/// Limit count.
@property (nonatomic, assign) NSInteger limit;

/// Total number of messages requested
@property (nonatomic, assign) NSInteger offset;

@end

/// Message center message detail list request model.
@interface WiserSmartMessageDetailListRequestModel : NSObject

/// Message type (Currently only supported WSMessageTypeAlarm).
@property (nonatomic, assign) WSMessageType msgType;

/// Limit count.
@property (nonatomic, assign) NSInteger limit;

/// Total number of messages requested.
@property (nonatomic, assign) NSInteger offset;

/// Message device ID.
@property (nonatomic, copy) NSString *msgSrcId;

@end

@interface WiserSmartMessageListDeleteRequestModel : NSObject
/// Message type.
@property (nonatomic, assign) WSMessageType msgType;

/// Message ID.
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

/// Message device ID.
@property (nonatomic, copy) NSArray<NSString *> *msgSrcIds;

@end

@interface WiserSmartMessageListReadRequestModel : NSObject

/// Message type (Currently only supported WSMessageTypeAlarm).
@property (nonatomic, assign) WSMessageType msgType;

/// Message ID.
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

@end

#pragma mark - setting
/// Device Do Not Disturb request model.
@interface WiserSmartMessageSettingDNDRequestModel : NSObject

/// Start time.
@property (nonatomic, copy) NSString *startTime;

/// End time.
@property (nonatomic, copy) NSString *endTime;

/// The device ID list.
@property (nonatomic, copy) NSArray<NSString *> *devIDs;

/// Repeat days per week.
///
/// 0 means close that day, 1 means open on the day. @"0000111" means Friday to Sunday open.
///
@property (nonatomic, copy) NSString *loops;

/// Do all devices support DND.
///
/// 'devIDs' is not required when 'isAllDevIDs' is Ture.
@property (nonatomic, assign) BOOL isAllDevIDs;

@end

NS_ASSUME_NONNULL_END
