//
//  WiserSmartRequest.h
//  WiserSmartPublic
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartRequest
#define WiserSmart_WiserSmartRequest

#import <WiserSmartUtil/WiserSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartRequest : NSObject

/**
 Network request for Wiser server API.
 调用服务端API

 @param apiName API name
 @param postData API params
 @param version API version
 @param success Success block
 @param failure Failure block
 */
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   version:(NSString *)version
                   success:(nullable WSSuccessID)success
                   failure:(nullable WSFailureError)failure;

/**
 Network request for Wiser server API.
 调用服务端API
 
 @param apiName API name
 @param postData API params
 @param getData Common params
 @param version API version
 @param success Success block
 @param failure Failure block
 */
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   getData:(nullable NSDictionary *)getData
                   version:(NSString *)version
                   success:(nullable WSSuccessID)success
                   failure:(nullable WSFailureError)failure;

/// Cancel network request
- (void)cancel;

/// Remove network cache
+ (void)removeAllCache;

@end


@interface WiserSmartRequest (ApiMerge)

/**
 Invoke multiple api in one network request.
 一次网络请求调用多个API

 @param apiName API name
 @param postData API params
 @param version API version
 @param success Success block
 @param failure Failure block
 */
- (void)addMergeRequestWithApiName:(NSString *)apiName
                          postData:(nullable NSDictionary *)postData
                           version:(NSString *)version
                           success:(nullable WSSuccessID)success
                           failure:(nullable WSFailureError)failure;


/**
 Send multiple api request.
 发送合并API请求
 
 @param success Success block
 @param failure Failure block
 */
- (void)sendMergeRequestWithSuccess:(nullable WSSuccessList)success
                            failure:(nullable WSFailureError)failure;

/**
 Send multiple api request.
 发送合并API请求
 
 @param getData Common params
 @param success Success block
 @param failure Failure block
 */
- (void)sendMergeRequestWithGetData:(nullable NSDictionary *)getData
                            success:(nullable WSSuccessList)success
                            failure:(nullable WSFailureError)failure;


/**
 Remove all multiple api request.
 清空合并API请求
 */
- (void)removeAllMergeRequest;

@end

@interface WiserSmartRequest (Encryption)

/**
 Network request for Wiser server API with post data encrypt.
 调用服务端API
 
 @param apiName API name
 @param postData API params
 @param version API version
 @param success Success block
 @param failure Failure block
 */
- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                 postData:(nullable NSDictionary *)postData
                                  version:(NSString *)version
                                  success:(nullable WSSuccessID)success
                                  failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
