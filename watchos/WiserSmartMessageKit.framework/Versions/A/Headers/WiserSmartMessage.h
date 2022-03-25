//
// WiserSmartMessage.h
// WiserSmartMessageKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartMessageListModel.h"
#import "WiserSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN
/// @brief WiserSmartMessage provides methods for developers to implement message functionalities.
///
/// WiserSmartMessage contains message center and push-related functions, and its messages are mainly divided into three major categories: alarms, families, and notifications, each of which is supported to be turned on or off respectively.
@interface WiserSmartMessage : NSObject

/// Fetch message list.
/// @param listRequestModel Provide listRequestModel to fetch the WiserSmartMessageListModel.
/// @param success Called when the task finishes successfully. A list of WiserSmartMessageListModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageListWithListRequestModel:(WiserSmartMessageListRequestModel *)listRequestModel
                                     success:(void (^)(NSArray<WiserSmartMessageListModel *> *messageList))success
                                     failure:(WSFailureError)failure;

/// Fetch message detail list.
/// @param detailListRequestModel Provide a listRequestModel to fetch the WiserSmartMessageListModel.
/// @param success Called when the task finishes successfully. A list of WiserSmartMessageListModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageDetailListWithListRequestModel:(WiserSmartMessageDetailListRequestModel *)detailListRequestModel
                                           success:(void (^)(NSArray<WiserSmartMessageListModel *> *messageList))success
                                           failure:(WSFailureError)failure;

/// Get three types of messages if there are new ones.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getLatestMessageWithSuccess:(WSSuccessDict)success failure:(WSFailureError)failure;

/// Set the message center list data to read.
/// @param readRequestModel List of read messages (support all read).
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)readMessageWithReadRequestModel:(WiserSmartMessageListReadRequestModel *)readRequestModel success:(WSSuccessBOOL)success failure:(WSFailureError)failure;


/// Delete message center list data.
/// @param deleteRequestModel List of deleted messages (delete all is not supported).
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteMessageWithDeleteRequestModel:(WiserSmartMessageListDeleteRequestModel *)deleteRequestModel success:(WSSuccessBOOL)success failure:(WSFailureError)failure;

/// Canceling the ongoing operation.
- (void)cancelRequest;

@end
NS_ASSUME_NONNULL_END
