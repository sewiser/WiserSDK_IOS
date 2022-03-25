//
// WSLoginRegionModel.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WSRegionModel_h
#define WSRegionModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief WSRegionModel is an object of server region.
@interface WSRegionModel : NSObject

/// Region name.
@property (nonatomic, strong) NSString *name;

/// Region code.
@property (nonatomic, strong) NSString *region;

/// Default or not.
@property (nonatomic, assign) BOOL isDefault;

@end

NS_ASSUME_NONNULL_END

#endif /* WSRegionModel_h */
