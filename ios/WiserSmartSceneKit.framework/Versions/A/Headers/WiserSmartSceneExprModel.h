//
//  WiserSmartSceneExprModel.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)
//

#import <Foundation/Foundation.h>

/// @brief Scene expression model, it can be defined as any type.
@interface WiserSmartSceneExprModel : NSObject

/// Used to store expression data, it can be used as any type.
@property (nonatomic, strong) NSArray *expr;

@end

