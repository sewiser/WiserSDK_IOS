//
//  WiserSmartDeviceModel+Home.h
//  WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceCoreKit/WiserSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartDeviceModel (Home)

@property (nonatomic, assign) long long homeId;
@property (nonatomic, assign) long long roomId;

@property (nonatomic, assign) NSInteger displayOrder;
@property (nonatomic, assign) NSInteger homeDisplayOrder;

@end

NS_ASSUME_NONNULL_END
