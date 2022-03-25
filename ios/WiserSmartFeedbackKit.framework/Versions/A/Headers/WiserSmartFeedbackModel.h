//
// WiserSmartFeedbackModel.h
// WiserSmartFeedbackKit
//
// Copyright (c) 2014-2021 Wiser Inc (https://developer.wiser.com)

/// The two types of feedback. Provides question and answer types.
typedef enum : NSUInteger {
    /// The question feedback type.
    WiserSmartFeedbackQuestion,
    /// The answer feedback type.
    WiserSmartFeedbackAnswer,
} WiserSmartFeedbackType;

@interface WiserSmartFeedbackModel : NSObject

/// The feedback type.
@property (nonatomic, assign) WiserSmartFeedbackType     type;

/// The time when the feedback opened.
@property (nonatomic, assign) NSTimeInterval            ctime;

/// The feedback ID.
@property (nonatomic, assign) NSUInteger                uniqueId;

/// The content of the feedback.
@property (nonatomic, strong) NSString                  *content;

@end
