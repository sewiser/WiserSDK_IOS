//
//  WiserSmartShareMemberDetailModel.h
//  WiserSmartKitExample
//
//
//  Copyright © 2017年 tuya. All rights reserved.
//

@class WiserSmartShareDeviceModel;

@interface WiserSmartShareMemberDetailModel : NSObject

/**
 deviceModel list
 */
@property (nonatomic, strong) NSArray <WiserSmartShareDeviceModel *> *devices;

/**
 mobile
 */
@property (nonatomic, strong) NSString *mobile;

/**
 name
 */
@property (nonatomic, strong) NSString *name;

/**
 remark name
 */
@property (nonatomic, strong) NSString *remarkName;

/**
 auto sharing
 */
@property (nonatomic, assign) BOOL autoSharing;


@end
