//
//  WiserSmartReceiveMemberDetailModel.h
//  WiserSmartKitExample
//
//
//  Copyright © 2017年 tuya. All rights reserved.
//

@class WiserSmartShareDeviceModel;

@interface WiserSmartReceiveMemberDetailModel : NSObject


@property (nonatomic, strong) NSArray <WiserSmartShareDeviceModel *> *devices;

//账号信息 邮箱或者手机号
@property (nonatomic, strong) NSString *mobile;

//用户昵称
@property (nonatomic, strong) NSString *name;

//备注
@property (nonatomic, strong) NSString *remarkName;


@end
