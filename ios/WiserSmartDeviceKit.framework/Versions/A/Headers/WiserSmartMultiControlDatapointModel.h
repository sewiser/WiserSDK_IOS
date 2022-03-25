//
// WiserSmartMultiControlDatapointModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMultiControlDatapointModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *name;///< dp name
@property (copy, nonatomic) NSString *code;///< dp standard name（dpCode）
@property (copy, nonatomic) NSString *schemaId;///< The schema ID to which the key belongs.

@end

NS_ASSUME_NONNULL_END
