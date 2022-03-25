//
// WSApiMergeService.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WSApiMergeService_h
#define WSApiMergeService_h

#import "WSApiMergeModel.h"
#import "WiserSmartRequest.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief WSApiMergeService is used for making several requests in one HTTP request.
///
/// This class is used for reduce the number of network requests. Use it with the following steps:
///     1. Create a WSApiMergeService instance
///     2. Add several request by `-[WSApiMergeService addApiRequest:postData:version:]`
///     3. SendRequests by `- [WSApiMergeService sendRequest:success:failure]`. requests will be sent and received together.
///
/// @discussion Due to HTTP/2 multiplexing technology, it is not recommend for use now.
///
@interface WSApiMergeService : WiserSmartRequest

@property (nonatomic, strong) WSSDKSafeMutableArray *requestList;


/// Add api request.
/// @param apiName Api name.
/// @param postData Post data.
/// @param version Version.
- (void)addApiRequest:(NSString *)apiName postData:(NSDictionary *)postData version:(NSString *)version;


/// Send request.
/// @param getData Get data.
/// @param success Called when the task finishes successfully. A list of WSApiMergeModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)sendRequest:(NSDictionary *)getData success:(nullable void (^)(NSArray <WSApiMergeModel *> *list))success failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* WSApiMergeService_h */
