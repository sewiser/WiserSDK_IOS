//
//  WiserSmartSceneLogDetailModel.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartSceneLogDetailData;

/// @brief WiserSmartSceneLogDetailModel provides more attributes for developers to generate log detail model object.
@interface WiserSmartSceneLogDetailModel : NSObject

/// The action entity id.
@property (nonatomic, strong) NSString *actionEntityId;

/// The action entity name.
@property (nonatomic, strong) NSString *actionEntityName;

/// The action entity URL.
@property (nonatomic, strong) NSString *actionEntityUrl;

/// The action executor type, eg: dpIssue, groupDpIssue.
@property (nonatomic, strong) NSString *actionExecutor;

/// The action id.
@property (nonatomic, strong) NSString *actionId;

/// The error code.
@property (nonatomic, strong) NSString *errorCode;

/// The error information of scene execution.
@property (nonatomic, strong) NSString *errorMsg;

/// The execute status of the action in the scene.
@property (nonatomic, assign) NSInteger execStatus;

/// The execute time of the action in the scene.
@property (nonatomic, strong) NSString *executeTime;

/// The detail data list of scene log.
@property (nonatomic, strong) NSArray<WiserSmartSceneLogDetailData *> *detail;

@end

/// @brief WiserSmartSceneLogDetailData provides more attributes for developers to generate log detail data object.
@interface WiserSmartSceneLogDetailData: NSObject

/// The execute code of the action in the scene.
@property (nonatomic, strong) NSString *code;

/// The error message.
@property (nonatomic, strong) NSString *msg;

/// The execute status of the action in the scene.
@property (nonatomic, assign) NSInteger status;

/// The detail user name.
@property (nonatomic, strong) NSString *detailName;

/// The user id.
@property (nonatomic, strong) NSString *detailId;

/// The icon URL.
@property (nonatomic, strong) NSString * icon;

@end

NS_ASSUME_NONNULL_END
