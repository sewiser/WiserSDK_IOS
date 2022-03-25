//
//  WiserSmartSceneLogModel.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartSceneLogData;

/// @brief WiserSmartSceneLogModel provides more attributes for developers to create log list model for scene.
@interface WiserSmartSceneLogModel : NSObject

/// The scene log data list.
@property (nonatomic, strong) NSArray<WiserSmartSceneLogData *> * datas;

/// The number of scene logs.
@property (nonatomic, assign) NSInteger totalCount;

@end

/// @brief WiserSmartSceneLogData provides more attributes for developers to create log data.
@interface WiserSmartSceneLogData : NSObject

/// The log event id.
@property (nonatomic, strong) NSString *eventId;

/// The result of scene execution.
@property (nonatomic, assign) NSInteger execResult;

/// The result message of scene execution.
@property (nonatomic, strong) NSString *execResultMsg;

/// The time of scene execution.
@property (nonatomic, strong) NSString *execTime;

/// The error information of scene execution.
@property (nonatomic, strong) NSString *failureCause;

/// The error code.
@property (nonatomic, assign) NSInteger failureCode;

/// The owner id of scene log.
@property (nonatomic, strong) NSString *ownerId;

/// The rule id of the scene.
@property (nonatomic, strong) NSString *ruleId;

/// The rule name.
@property (nonatomic, strong) NSString *ruleName;

/// The scene type, 1 means tap-to-run scene, 2 means automation scene.
@property (nonatomic, assign) NSInteger sceneType;

/// The user id.
@property (nonatomic, strong) NSString *uid;

/// This data is not from service, you can set this property just for display.
@property (nonatomic, strong) NSString *detailTime;

/// This data is not from service, you can set this property to assist sort the list into category use this property just for display. 0 first , 1 middle, 2 last, -1 needless(just one item)
@property (nonatomic, assign) NSInteger indexType;

@end

NS_ASSUME_NONNULL_END
