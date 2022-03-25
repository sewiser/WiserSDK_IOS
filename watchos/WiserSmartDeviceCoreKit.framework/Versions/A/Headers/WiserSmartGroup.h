//
// WiserSmartGroup.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartGroup
#define WiserSmart_WiserSmartGroup

#import <Foundation/Foundation.h>
#import "WiserSmartGroupModel.h"
#import "WiserSmartGroupDevListModel.h"

NS_ASSUME_NONNULL_BEGIN

@class WiserSmartGroup;

/// The delegate of WiserSmartGroup class, provides group related status update callback.
@protocol WiserSmartGroupDelegate<NSObject>

@optional

/// Group dps data update.
/// @param group The instance of WiserSmartGroup.
/// @param dps dps.
- (void)group:(WiserSmartGroup *)group dpsUpdate:(NSDictionary *)dps;

/// Group Information Update.
/// @param group The instance of WiserSmartGroup.
- (void)groupInfoUpdate:(WiserSmartGroup *)group;

/// Group removal.
/// @param groupId The group ID.
- (void)groupRemove:(NSString *)groupId;

/// Group dpCodes data update.
/// @param group The instance of WiserSmartGroup.
/// @param dpCodes Dp Codes
- (void)group:(WiserSmartGroup *)group dpCodesUpdate:(NSDictionary *)dpCodes;

/// Group Response of Zigbee Devices Joining Gateway. 1: Over the Scenario Limit 2: Sub-device Timeout 3: Setting Value Out of Range 4: Write File Error 5: Other Errors.
/// @param group The instance of WiserSmartGroup.
/// @param responseCode Response code.
- (void)group:(WiserSmartGroup *)group addResponseCode:(NSArray <NSNumber *>*)responseCode;

/// Group Response of Zigbee Devices removing Gateway 1: Over the Scenario Limit 2: Sub-device Timeout 3: Setting Value Out of Range 4: Write File Error 5: Other Errors.
/// @param group The instance of WiserSmartGroup.
/// @param responseCode Response code.
- (void)group:(WiserSmartGroup *)group removeResponseCode:(NSArray <NSNumber *>*)responseCode;

@end

/// @brief Smart device group, including group creation, group command issuance, group basic information update, etc.
///
/// Adding a number of devices with the same function to a group allows you to control them simultaneously.
///
@interface WiserSmartGroup : NSObject

/// Get the basic group information model
@property (nonatomic, strong, readonly) WiserSmartGroupModel *groupModel;

@property (nonatomic, weak, nullable) id<WiserSmartGroupDelegate> delegate;

/// Get WiserSmartGroup instance.
/// @param groupId The group ID.
+ (nullable instancetype)groupWithGroupId:(NSString *)groupId;

/// Get WiserSmartGroup instance.
/// @param groupId The group ID.
- (nullable instancetype)initWithGroupId:(NSString *)groupId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Get the device list for the corresponding group based on productId.
/// @param productId Product ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevList:(NSString *)productId
           success:(nullable void(^)(NSArray <WiserSmartGroupDevListModel *> *list))success
           failure:(nullable WSFailureError)failure;

/// Group control command issuance.
/// @param dps dps.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Rename the group name.
/// @param name The group name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateGroupName:(NSString *)name success:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;

/// Edit group icon.
/// @param icon Group icon.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon
           success:(nullable WSSuccessHandler)success
           failure:(nullable WSFailureError)failure;

/// Edit group icon.
/// @param cloudKey The cloud key.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIconWithCloudKey:(NSString *)cloudKey
                       success:(nullable WSSuccessHandler)success
                       failure:(nullable WSFailureError)failure;

/// Modify the device list of the group.
/// @param devList Device list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateGroupRelations:(NSArray <NSString *>*)devList
                     success:(nullable WSSuccessHandler)success
                     failure:(nullable WSFailureError)failure;

/// Remove Group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)dismissGroup:(nullable WSSuccessHandler)success failure:(nullable WSFailureError)failure;


#pragma mark - zigbee

#if TARGET_OS_IOS

/// Add sub devices to groups (interacting locally with gateways).
/// @param nodeList Sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithSubDeviceNodeList:(NSArray <NSString *>*)nodeList
                                  success:(nullable WSSuccessHandler)success
                                  failure:(nullable WSFailureError)failure;

/// Remove sub devices from groups (interacting locally with gateways).
/// @param nodeList  Sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSubDeviceWithSubDeviceNodeList:(NSArray <NSString *>*)nodeList
                                     success:(nullable WSSuccessHandler)success
                                     failure:(nullable WSFailureError)failure;

#endif

/// Cancel Request
- (void)cancelRequest;


@end

NS_ASSUME_NONNULL_END

#endif
