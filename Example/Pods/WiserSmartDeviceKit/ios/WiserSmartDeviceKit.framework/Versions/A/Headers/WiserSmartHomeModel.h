//
//  WiserSmartHomeModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WiserSmartDeviceModelUtils.h"

@interface WiserSmartHomeModel : NSObject

// home Id
@property (nonatomic, assign) long long homeId;

// home name
@property (nonatomic, strong) NSString *name;

// home geographic location
@property (nonatomic, strong) NSString *geoName;

// latitude
@property (nonatomic, assign) double latitude;

// longitude
@property (nonatomic, assign) double longitude;

// home Background Pictures
@property (nonatomic, strong) NSString *backgroundUrl;

// order
@property (nonatomic, assign) NSInteger displayOrder;

// admin or not
@property (nonatomic, assign) BOOL admin __deprecated_msg("This property is deprecated, Use role property");

// role type
@property (nonatomic, assign) WSHomeRoleType role;

// state of deal
@property (nonatomic, assign) WSHomeStatus dealStatus;

// inviter's name
@property (nonatomic, strong) NSString *nickName;

@end

