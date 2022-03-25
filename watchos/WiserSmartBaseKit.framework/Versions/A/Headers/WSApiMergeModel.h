//
// WSApiMergeModel.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WSApiMergeModel_h
#define WSApiMergeModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief WSApiMergeModel is an object of response data from WSApiMergeService.
@interface WSApiMergeModel : NSObject

/// Success.
@property (nonatomic, assign) BOOL      success;

/// Api name.
@property (nonatomic, strong) NSString  *apiName;

/// Error.
@property (nonatomic, strong) NSError   *error;

/// Response result.
@property (nonatomic, strong) id        result;

/// Timestamp.
@property (nonatomic, assign) NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END

#endif /* WSApiMergeModel_h */
