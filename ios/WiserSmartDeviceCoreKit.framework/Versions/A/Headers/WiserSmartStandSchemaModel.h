//
// WiserSmartStatusSchemaModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Reported Mapping Policies.
@interface WiserSmartStatusSchemaModel : NSObject

/// Mapping Rules.
@property (nonatomic, strong) NSString     *strategyValue;

/// Policy designators, currently supporting more than 10.
@property (nonatomic, strong) NSString     *strategyCode;

/// The reported dpId corresponds to a dpCode that is not a standard dpCode.
@property (nonatomic, strong) NSString     *dpCode;

/// DpValue type after standard.
@property (nonatomic, strong) NSString     *standardType;

/// The value range
@property (nonatomic, strong) NSString     *valueRange;

/// Dpcode->dpid mapping relationship
@property (nonatomic, strong) NSDictionary *relationDpIdMaps;

@end

/// Distributed mapping strategy.
@interface WiserSmartFunctionSchemaModel : NSObject

/// At present, more than 10 kinds of policy codes are supported.
@property (nonatomic, strong) NSString     *strategyCode;

/// Mapping rules.
@property (nonatomic, strong) NSString     *strategyValue;

/// Standardized dpcode.
@property (nonatomic, strong) NSString     *standardCode;

/// Dpvalue type after standard.
@property (nonatomic, strong) NSString     *standardType;

/// The value range
@property (nonatomic, strong) NSString     *valueRange;

/// Dpcode->dpid mapping relationship
@property (nonatomic, strong) NSDictionary *relationDpIdMaps;

@end

/// standard schema
@interface WiserSmartStandSchemaModel : NSObject

@property (nonatomic, assign) BOOL isProductCompatibled;

@property (nonatomic, strong) NSArray<WiserSmartStatusSchemaModel *> *statusSchemaList;

@property (nonatomic, strong) NSArray<WiserSmartFunctionSchemaModel *> *functionSchemaList;

@end

NS_ASSUME_NONNULL_END
