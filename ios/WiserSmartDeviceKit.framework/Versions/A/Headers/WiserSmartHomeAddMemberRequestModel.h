//
// WiserSmartHomeAddMemberRequestModel.h
// WiserSmartDeviceKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHomeAddMemberRequestModel : NSObject

/// Nicknames for invitees.
@property (nonatomic, copy) NSString *name;

/// Invited accounts.
@property (nonatomic, copy) NSString *account;

/// Invitee account corresponding to the country code.
@property (nonatomic, copy) NSString *countryCode;

/// Member role, please set the correct role type you want to set.
@property (nonatomic, assign) WSHomeRoleType role;

/// The avatar set for the invitee, if set to nil, the invitee's personal avatar will be used.
@property (nonatomic, strong) UIImage *headPic;

/// Whether the invitee needs to agree to accept the invitation. YES - the invited account automatically accepts the family invitation without the invitee's confirmation; NO - the invitee's consent is required to join the family.
@property (nonatomic, assign) BOOL autoAccept;

@end

@interface WiserSmartHomeInvitationCreateRequestModel : NSObject

/// Home ID
@property (nonatomic, assign) long long homeID;

/// A boolean value indicates whether need invitation message.
@property (nonatomic, assign) BOOL needMsgContent;

@end

@interface WiserSmartHomeInvitationReinviteRequestModel : NSObject

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationID;

/// A boolean value indicates whether need invitation message.
@property (nonatomic, assign) BOOL needMsgContent;

@end

@interface WiserSmartHomeInvitationInfoRequestModel : NSObject

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationID;

/// Invitation remark name.
@property (nonatomic, copy) NSString *name;

@end

@interface WiserSmartHomeInvitationResultModel : NSObject

/// The Invitation message.
@property (nonatomic, copy) NSString *invitationMsgContent;

/// The invitation code.
@property (nonatomic, copy) NSString *invitationCode;

@end


@interface WiserSmartHomeInvitationRecordModel : NSObject;

/// Invitation code valid time, unit:hour.
@property (nonatomic, assign) NSInteger validTime;

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationID;

/// The invitation code.
@property (nonatomic, copy) NSString *invitationCode;

/// Invitation remark name.
@property (nonatomic, copy) NSString *name;

@end
NS_ASSUME_NONNULL_END

