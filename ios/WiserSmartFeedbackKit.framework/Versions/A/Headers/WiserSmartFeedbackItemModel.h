//
// WiserSmartFeedbackItemModel.h
// WiserSmartFeedbackKit
//
// Copyright (c) 2014-2021 Wiser Inc (https://developer.wiser.com)

@interface WiserSmartFeedbackItemModel : NSObject


/// The feedback item id.
@property (nonatomic, strong) NSString      *hdId;

/// The feedback item type.
@property (nonatomic, assign) NSUInteger    hdType;

/// The feedback item title.
@property (nonatomic, strong) NSString      *title;

@end
