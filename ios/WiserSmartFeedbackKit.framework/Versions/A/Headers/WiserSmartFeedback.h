//
// WiserSmartFeedback.h
// WiserSmartFeedbackKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartFeedbackTalkListModel.h"
#import "WiserSmartFeedbackModel.h"
#import "WiserSmartFeedbackTypeListModel.h"

/// @brief WiserSmartFeedback provides methods for developers to implement feedback functionalities.
///
/// When the user finds a problem and needs to submit feedback, he/she can add it. When adding feedback, he/she should first select the feedback type, then write the feedback content and submit it.
///
/// All functions related to feedback correspond to the WiserSmartFeedback class, which supports the following list of functions:
///
/// - WiserSmartFeedback::getFeedbackTalkList:failure: for getting a list of feedback sessions
/// - WiserSmartFeedback::getFeedbackList:hdType:success:failure: for getting a list of feedback contents in a session
/// - WiserSmartFeedback::getFeedbackTypeList:failure: for getting a list of feedback types
/// - adding feedback
@interface WiserSmartFeedback : NSObject

/// Get a list of sessions that users have submitted feedback on.
///
/// @param success      When success, return feedback session list.
/// @param failure      When error occurred, return WSFailureError.
- (void)getFeedbackTalkList:(void (^)(NSArray<WiserSmartFeedbackTalkListModel *> *list))success
                    failure:(WSFailureError)failure;


/// Get a list of the corresponding feedback contents in the feedback session. The `hdId` and `hdType` can be obtained from WiserSmartFeedbackTalkListModel.
///
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param success      When success, return feedback list.
/// @param failure      When error occurred, return WSFailureError.
- (void)getFeedbackList:(NSString *)hdId
                 hdType:(NSUInteger)hdType
                success:(void (^)(NSArray<WiserSmartFeedbackModel *> *list))success
                failure:(WSFailureError)failure;


/// Get feedback type list. When adding feedback, select the type of feedback first.
///
/// @param success      When success, return WiserSmartFeedbackTypeListModel.
/// @param failure      When error occurred, return WSFailureError.
- (void)getFeedbackTypeList:(void (^)(NSArray<WiserSmartFeedbackTypeListModel *> *list))success
                    failure:(WSFailureError)failure;


/// Add feedback and submit the content of the feedback entered by the user.
///
/// The `hdId` and `hdType` can be obtained from WiserSmartFeedbackTalkListModel.
///
/// @note This is suggested for App related issues and devices that do not need strong bindings.
///
/// @param content      The feedback content.
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param contact      The contact information.
/// @param success      When successfully add the feedback, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
            success:(WSSuccessHandler)success
            failure:(WSFailureError)failure;


/// Add feedback and submit the content of the feedback entered by the user.
///
/// The `hdId` and `hdType` can be obtained from WiserSmartFeedbackTalkListModel.
///
/// @note This is suggested for devices that need strong bindings, for example IP cameras.
///
/// @param content      The feedback content.
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param contact      The contact information.
/// @param uuid         The UUID for the device.
/// @param region       The user's region.
/// @param success      When successfully add the feedback, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
               uuid:(NSString *)uuid
             region:(NSString *)region
            success:(WSSuccessHandler)success
            failure:(WSFailureError)failure;


/// Canceling an ongoing operation.
- (void)cancelRequest;

@end
