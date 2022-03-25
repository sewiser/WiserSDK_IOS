//
// WiserSmartFeedbackTypeListModel.h
// WiserSmartFeedbackKit
//
// Copyright (c) 2014-2021 Wiser Inc (https://developer.wiser.com)

#import "WiserSmartFeedbackItemModel.h"

@interface WiserSmartFeedbackTypeListModel : NSObject

/// Feedback type, e.g. "faulty device", "more".
@property (nonatomic, strong) NSString *type;

/// List of items included in the feedback type.
@property (nonatomic, strong) NSArray<WiserSmartFeedbackItemModel *> *list;

@end
