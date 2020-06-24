//
//  WiserSmartFeedbackModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//


typedef enum : NSUInteger {
    WiserSmartFeedbackQuestion,      //提问
    WiserSmartFeedbackAnswer,        //回答
} WiserSmartFeedbackType;

@interface WiserSmartFeedbackModel : NSObject

/**
 反馈类型
 */
@property (nonatomic, assign) WiserSmartFeedbackType     type;

/**
 反馈时间
 */
@property (nonatomic, assign) NSTimeInterval            ctime;

/**
 反馈id
 */
@property (nonatomic, assign) NSUInteger                uniqueId;

/**
 反馈内容
 */
@property (nonatomic, strong) NSString                  *content;

@end
