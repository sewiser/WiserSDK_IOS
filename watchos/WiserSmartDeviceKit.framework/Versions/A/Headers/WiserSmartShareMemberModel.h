//
//  WiserSmartShareMemberModel.h
//  WiserSmartKit
//
//
//  Copyright © 2015年 Wiser. All rights reserved.
//

@interface WiserSmartShareMemberModel : NSObject

/**
 *  关系Id
 */
@property (nonatomic, assign) NSInteger memberId;

/**
 *  备注名称
 */
@property (nonatomic, strong) NSString  *nickName;

/**
 *  用户名(手机号/邮箱号)
 */
@property (nonatomic, strong) NSString  *userName;

/**
 *  头像地址
 */
@property (nonatomic, strong) NSString *iconUrl;

@end
