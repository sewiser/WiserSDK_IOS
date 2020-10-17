//
//  WiserSmartHomeMemberModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WiserSmartHomeModelUtils.h"

@interface WiserSmartHomeMemberModel : NSObject

// member Id
@property (nonatomic, assign) long long memberId;

// Head portraits of members
@property (nonatomic, strong) NSString *headPic;

// name of members
@property (nonatomic, strong) NSString *name;

// role
@property (nonatomic, assign) WSHomeRoleType role;

// home Id
@property (nonatomic, assign) long long homeId;

// mobile
@property (nonatomic, strong) NSString *mobile;

// user name
@property (nonatomic, strong) NSString *userName;

// uid
@property (nonatomic, strong) NSString *uid;

// state of deal
@property (nonatomic, assign) WSHomeStatus dealStatus;

#pragma mark - deprecated
// admin or not
@property (nonatomic, assign) BOOL isAdmin __deprecated_msg("The property will be deprecated and remove in a future version，Please use role");

@end
