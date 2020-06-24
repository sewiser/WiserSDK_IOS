//
//  WiserSmartFeedbackItemModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

@interface WiserSmartFeedbackItemModel : NSObject

/**
 反馈类型item id
 */
@property (nonatomic, strong) NSString      *hdId;

/**
 反馈类型item类型
 */
@property (nonatomic, assign) NSUInteger    hdType;

/**
 反馈类型item标题
 */
@property (nonatomic, strong) NSString      *title;

@end
