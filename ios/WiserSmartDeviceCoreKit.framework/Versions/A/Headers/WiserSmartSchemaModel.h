//
//  WiserSmartSchemaModel.h
//  WiserSmartKit
//
//
//  Copyright (c) 2015年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartSchemaModel
#define WiserSmart_WiserSmartSchemaModel

#import <Foundation/Foundation.h>
#import "WiserSmartSchemaPropertyModel.h"

@interface WiserSmartSchemaModel : NSObject


/**
 *  DP点的ID
 */
@property (nonatomic, strong) NSString     *dpId;

/**
 *  DP点的CODE
 */
@property (nonatomic, strong) NSString     *code;

/**
 *  DP点的Name
 */
@property (nonatomic, strong) NSString     *name;

/**
 *  DP点的读写属性 rw - 可下发可上报 | ro - 仅上报 | wr - 仅下发
 */
@property (nonatomic, strong) NSString     *mode;


/**
 *  DP点的类型 obj - (数值型、字符型、bool 型、枚举型、故障型) | raw 透传类型
 */
@property (nonatomic, strong) NSString     *type;


/**
 *  DP点的iconname
 */
@property (nonatomic, strong) NSString     *iconname;

/**
 *  DP点的属性
 */
@property (nonatomic, strong) WiserSmartSchemaPropertyModel *property;

@end

#endif
