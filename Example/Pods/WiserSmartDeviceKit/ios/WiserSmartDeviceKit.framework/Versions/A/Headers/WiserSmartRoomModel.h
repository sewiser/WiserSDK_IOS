//
//  WiserSmartRoomModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WiserSmartRoomModel : NSObject

// room Id
@property (nonatomic, assign) long long roomId;

// room name
@property (nonatomic, strong) NSString *name;

// order
@property (nonatomic, assign) NSInteger displayOrder;


@end
