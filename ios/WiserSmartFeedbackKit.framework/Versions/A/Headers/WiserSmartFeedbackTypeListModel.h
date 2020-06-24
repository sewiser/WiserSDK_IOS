//
//  WiserSmartFeedbackTypeListModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import "WiserSmartFeedbackItemModel.h"

@interface WiserSmartFeedbackTypeListModel : NSObject

/**
 反馈类型，如：“故障设备”, "更多"
 */
@property (nonatomic, strong) NSString *type;

/**
 反馈类型包含的item列表
 */
@property (nonatomic, strong) NSArray<WiserSmartFeedbackItemModel *> *list;

@end
