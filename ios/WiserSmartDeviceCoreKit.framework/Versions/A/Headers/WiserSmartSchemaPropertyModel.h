//
// WiserSmartSchemaPropertyModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartSchemaPropertyModel
#define WiserSmart_WiserSmartSchemaPropertyModel

#import <Foundation/Foundation.h>

/// device schema property
@interface WiserSmartSchemaPropertyModel : NSObject

/// Type: enum - enumerated | bool - boolean | string - string | value - numeric | bitmap - fault.
@property (nonatomic, strong) NSString   *type;

/// Unit For example, ℃.
@property (nonatomic, strong) NSString   *unit;

/// Minimum value of numeric type.
@property (nonatomic, assign) double     min;

/// max when type is value.
@property (nonatomic, assign) double     max;

/// Numerical step.
@property (nonatomic, assign) double     step;

/// The exponent of 10 in the numeric type, multiplied by the corresponding transmission value, is equal to the actual value and is used to avoid fractional transmission.
@property (nonatomic, assign) NSInteger  scale;

/// The maximum number of bits of the fault type.
@property (nonatomic, assign) NSInteger  maxlen;

/// Detailed description of the fault type.
@property (nonatomic, strong) NSArray    *label;

/// scope of the enumeration type.
@property (nonatomic, strong) NSArray    *range;

/// value of the user to select.
@property (nonatomic, assign) NSInteger selectedValue;

@end

#endif
