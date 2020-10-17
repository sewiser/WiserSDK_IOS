//
//  WiserSmartHomeMemberRequestModel.h
//  Pods
//
//
//

#import <Foundation/Foundation.h>
#import "WiserSmartHomeModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHomeMemberRequestModel : NSObject

/** 成员ID 必传字段 member Id is required */
@property (nonatomic, assign) long long memberId;

/** 成员名称 nil时不会更新已有名称 name of member */
@property (nonatomic, strong) NSString *name;

/**
 * 成员角色 请正确设置你想设置的角色类型，若不想更新角色类型可以保持当前角色类型或设为 “WSHomeRoleType_Unknown”
 * role，Please set the type of role you want to set. If don't want to update role type keep WSHomeRoleType_Unknown or current role type
 */
@property (nonatomic, assign) WSHomeRoleType role;

/** 成员头像 nil时不会更新已有头像 Head portraits of members Can be nil */
@property (nonatomic, strong) UIImage *headPic;

@end

NS_ASSUME_NONNULL_END
