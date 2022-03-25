//
// WiserSmartSchemaModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartSchemaModel
#define WiserSmart_WiserSmartSchemaModel

#import <Foundation/Foundation.h>
#import "WiserSmartSchemaPropertyModel.h"

/// device schema
@interface WiserSmartSchemaModel : NSObject

/// Dp ID.
@property (nonatomic, strong) NSString     *dpId;

/// Dp code.
@property (nonatomic, strong) NSString     *code;

/// The name of dp.
@property (nonatomic, strong) NSString     *name;

/// Read and write attributes of the DP point rw - can send down and report | ro - only report | wr - only send down.
@property (nonatomic, strong) NSString     *mode;

/// Type of DP point obj - (numeric, character, bool, enumerated, fault) | raw pass-through type.
@property (nonatomic, strong) NSString     *type;

/// The icon name of dp.
@property (nonatomic, strong) NSString     *iconname;

/// Dp property.
@property (nonatomic, strong) WiserSmartSchemaPropertyModel *property;

@end

#endif
