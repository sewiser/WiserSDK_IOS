//
// WiserSmartRequest.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartRequest_h
#define WiserSmartRequest_h

#import <WiserSmartUtil/WiserSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief WiserSmartRequest is used for invoke Wiser Cloud API.
///
/// All of the Wiser Cloud API (atop) is made from this class.
///
/// Usually, a request need these params:
///   - API name.
///   - API version.
///   - API params (aka postData). A serializable dictionary object.
///   - Common params (aka getData). A serializable dictionary object. Optional.
///
/// And a response will be back through `success` or `failure` callback.
/// A success callback will give any kind of object, which depends on the specific API.
/// An error callback will give an error object, `error.userInfo[NSLocalizedFailureReasonErrorKey]` is for Wiser error code, `error.localizedDescription` is for detailed reasons.
///
/// @warning The `error.localizedDescription` is not recommend for display, please handle every possible error types and prepare the error messages for your own.
///
@interface WiserSmartRequest : NSObject

/// Network request for Wiser server API.
/// @param apiName API name.
/// @param postData API params.
/// @param version  API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   version:(NSString *)version
                   success:(nullable WSSuccessID)success
                   failure:(nullable WSFailureError)failure;


/// Network request for Wiser server API.
/// @param apiName API name.
/// @param postData API params.
/// @param getData Common params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   getData:(nullable NSDictionary *)getData
                   version:(NSString *)version
                   success:(nullable WSSuccessID)success
                   failure:(nullable WSFailureError)failure;

/// Cancel network request.
- (void)cancel;

/// Remove network cache.
+ (void)removeAllCache;

@end


@interface WiserSmartRequest (ApiMerge)

/// Invoke multiple api in one network request.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addMergeRequestWithApiName:(NSString *)apiName
                          postData:(nullable NSDictionary *)postData
                           version:(NSString *)version
                           success:(nullable WSSuccessID)success
                           failure:(nullable WSFailureError)failure;


/// Send multiple api request.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithSuccess:(nullable WSSuccessList)success
                            failure:(nullable WSFailureError)failure;


/// Send multiple api request.
/// @param getData Common params.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithGetData:(nullable NSDictionary *)getData
                            success:(nullable WSSuccessList)success
                            failure:(nullable WSFailureError)failure;


/// Remove all multiple api request.
- (void)removeAllMergeRequest;

@end

@interface WiserSmartRequest (Encryption)

/// Network request for Wiser server API with post data encrypt.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                 postData:(nullable NSDictionary *)postData
                                  version:(NSString *)version
                                  success:(nullable WSSuccessID)success
                                  failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* WiserSmartRequest_h */
