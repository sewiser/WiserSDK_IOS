//
//  WSApiMergeModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSApiMergeModel : NSObject


/**
 success
 */
@property (nonatomic, assign) BOOL      success;


/**
 api name
 */
@property (nonatomic, strong) NSString  *apiName;


/**
 error
 */
@property (nonatomic, strong) NSError   *error;


/**
 response result
 */
@property (nonatomic, strong) id        result;


/**
 timestamp
 */
@property (nonatomic, assign) NSTimeInterval time;

@end
