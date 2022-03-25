//
// WiserSmartWeatherModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartWeatherModel : NSObject

/// The weather icon.
@property (nonatomic, copy) NSString *icon;

/// Weather parameter name
@property (nonatomic, copy) NSString *name;

/// Parameter unit.
@property (nonatomic, copy) NSString *unit;

/// Parameter ID.
@property (nonatomic, assign) long long objId;

/// Whether to display; business layer not used.
@property (nonatomic, assign) BOOL show;

/// Weather parameter value.
@property (nonatomic, copy) NSString *value;

@property (nonatomic, copy) NSString *metaValue;
@property (nonatomic, copy) NSString *fieldName;
@property (nonatomic, copy) NSString *roomName;

@end

NS_ASSUME_NONNULL_END
