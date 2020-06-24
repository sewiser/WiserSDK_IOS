//
//  WiserSmartFeedbackTalkListModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//


@interface WiserSmartFeedbackTalkListModel : NSObject

/**
 会话时间
 */
@property (nonatomic, strong) NSString          *dateTime;

/**
 会话id
 */
@property (nonatomic, strong) NSString          *hdId;

/**
 会话类型
 */
@property (nonatomic, assign) NSUInteger        hdType;

/**
 会话标题
 */
@property (nonatomic, strong) NSString          *title;

/**
 会话内容
 */
@property (nonatomic, strong) NSString          *content;

@end
