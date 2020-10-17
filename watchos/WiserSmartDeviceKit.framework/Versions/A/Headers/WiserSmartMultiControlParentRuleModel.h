//
//  WiserSmartMultiControlParentRuleModel.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlParentRuleDpModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *dpName;///< dp 名称

@end

@interface WiserSmartMultiControlParentRuleModel : NSObject

@property (copy, nonatomic) NSString *ruleId;///< 自动化 id
@property (copy, nonatomic) NSString *name;///< 自动化名称

@property (strong, nonatomic) NSArray<WiserSmartMultiControlParentRuleDpModel *> *dpList;

@end

NS_ASSUME_NONNULL_END
