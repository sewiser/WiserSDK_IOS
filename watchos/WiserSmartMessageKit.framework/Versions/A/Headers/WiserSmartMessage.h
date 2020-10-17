//
//  WiserSmartMessage.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartMessageListModel.h"
#import "WiserSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN
@interface WiserSmartMessage : NSObject

/// 获取消息列表数据 fetch message list
/// @param listRequestModel 列表数据请求模型 listRequestModel
/// @param success 成功回调 success
/// @param failure 失败回调 failure
- (void)fetchMessageListWithListRequestModel:(WiserSmartMessageListRequestModel *)listRequestModel
                                     success:(void (^)(NSArray<WiserSmartMessageListModel *> *messageList))success
                                     failure:(WSFailureError)failure;

/// 获取消息详情列表数据 fetch message detail list
/// @param detailListRequestModel 列表数据请求模型 detailListRequestModel
/// @param success 成功回调 success
/// @param failure 失败回调 failure
- (void)fetchMessageDetailListWithListRequestModel:(WiserSmartMessageDetailListRequestModel *)detailListRequestModel
                                           success:(void (^)(NSArray<WiserSmartMessageListModel *> *messageList))success
                                           failure:(WSFailureError)failure;

/// 获取三类消息是否有新消息 Get three types of messages if there are new ones
/// @param success 成功回调 success
/// @param failure 失败回调 failure
- (void)getLatestMessageWithSuccess:(WSSuccessDict)success failure:(WSFailureError)failure;

/// 已阅消息中心列表数据 have read message
/// @param readRequestModel 已阅的消息列表(支持全部已读) readRequestModel(support read all)
/// @param success 成功回调 success
/// @param failure 失败回调 failure
- (void)readMessageWithReadRequestModel:(WiserSmartMessageListReadRequestModel *)readRequestModel success:(WSSuccessBOOL)success failure:(WSFailureError)failure;


/// 删除消息中心列表数据 delete message
/// @param deleteRequestModel 删除的消息列表(不支持删除全部) deleteRequestModel(nonsupport delete all)
/// @param success 成功回调 success
/// @param failure 失败回调 failure
- (void)deleteMessageWithDeleteRequestModel:(WiserSmartMessageListDeleteRequestModel *)deleteRequestModel success:(WSSuccessBOOL)success failure:(WSFailureError)failure;

/// 取消正在进行的操作 Cancel the request being executed
- (void)cancelRequest;

@end
NS_ASSUME_NONNULL_END
