//
//  WSApiMergeService.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import "WSApiMergeModel.h"
#import "WiserSmartRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface WSApiMergeService : WiserSmartRequest

@property (nonatomic, strong) NSMutableArray *requestList;


/**
 add api request

 @param apiName     api name
 @param postData    post data
 @param version     version
 */
- (void)addApiRequest:(NSString *)apiName postData:(NSDictionary *)postData version:(NSString *)version;


/**
 send request

 @param getData get data
 @param success Success block
 @param failure Failure block
 */
- (void)sendRequest:(NSDictionary *)getData success:(nullable void (^)(NSArray <WSApiMergeModel *> *list))success failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
