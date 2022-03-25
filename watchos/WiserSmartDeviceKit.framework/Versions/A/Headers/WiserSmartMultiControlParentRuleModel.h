//
// WiserSmartMultiControlParentRuleModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlParentRuleDpModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *dpName;///< dp name

@end

@interface WiserSmartMultiControlParentRuleModel : NSObject

@property (copy, nonatomic) NSString *ruleId;///< Automation id
@property (copy, nonatomic) NSString *name;///< Automation name

@property (strong, nonatomic) NSArray<WiserSmartMultiControlParentRuleDpModel *> *dpList;

@end

NS_ASSUME_NONNULL_END
