//
//  WSGroupDevList.h
//  WiserSmart
//
//
//  Copyright © 2015年 Wiser. All rights reserved.
//

#ifndef WiserSmart_WiserSmartGroupDevListModel
#define WiserSmart_WiserSmartGroupDevListModel

#import <Foundation/Foundation.h>

@interface WiserSmartGroupDevListModel : NSObject


/// 设备Id
@property(nonatomic,strong) NSString    *devId;

/// 设备Id
@property(nonatomic,strong) NSString    *gwId;

/// 设备是否在线
@property(nonatomic,assign) BOOL        online;

/// 设备图标url
@property(nonatomic,strong) NSString    *iconUrl;

/// 产品Id
@property(nonatomic,strong) NSString    *productId;

/// 设备是否选中
@property(nonatomic,assign) BOOL        checked;

/// 设备名字
@property(nonatomic,strong) NSString    *name;

/// 设备地址
@property(nonatomic,strong) NSString    *nodeId;


@end

#endif

