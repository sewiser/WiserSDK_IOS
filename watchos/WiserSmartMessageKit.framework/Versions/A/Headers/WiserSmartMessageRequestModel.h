//
//  WiserSmartMessageRequestModel.h
//  WiserSmartMessageKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// 消息中心消息列表请求模型
@interface WiserSmartMessageListRequestModel : NSObject

/// 消息类型 message type
@property (nonatomic, assign) WSMessageType msgType;

/// 限制列表数 limit count
@property (nonatomic, assign) NSInteger limit;

/// 偏移 offset
@property (nonatomic, assign) NSInteger offset;

@end

/// 消息中心消息详情列表请求模型
@interface WiserSmartMessageDetailListRequestModel : NSObject

/// 消息类型(目前仅支持WSMessageTypeAlarm类消息) message type( Currently only supported WSMessageTypeAlarm)
@property (nonatomic, assign) WSMessageType msgType;

/// 限制列表数 limit count
@property (nonatomic, assign) NSInteger limit;

/// 偏移 offset
@property (nonatomic, assign) NSInteger offset;

/// 消息来源设备ID message device ID
@property (nonatomic, copy) NSString *msgSrcId;

@end

@interface WiserSmartMessageListDeleteRequestModel : NSObject
/// 消息类型 message type
@property (nonatomic, assign) WSMessageType msgType;

/// 消息ID message ID
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

/// 消息来源设备ID message device ID
@property (nonatomic, copy) NSArray<NSString *> *msgSrcIds;

@end

@interface WiserSmartMessageListReadRequestModel : NSObject

/// 消息类型(目前仅支持WSMessageTypeAlarm类消息) message type( Currently only supported WSMessageTypeAlarm)
@property (nonatomic, assign) WSMessageType msgType;

/// 消息ID message ID
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

@end

NS_ASSUME_NONNULL_END
