//
// WiserSmartBleMeshModel.h
// WiserSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmart_WiserSmartBleMeshModel
#define WiserSmart_WiserSmartBleMeshModel

#import <Foundation/Foundation.h>

@interface WiserSmartBleMeshModel : NSObject

//generic mesh info
@property (nonatomic, strong) NSString     *name;

//mesh id
@property (nonatomic, strong) NSString     *meshId;

//localKey
@property (nonatomic, strong) NSString     *localKey;

//pv
@property (nonatomic, strong) NSString     *pv;

@property (nonatomic, strong) NSString     *code;

@property (nonatomic, strong) NSString     *password;

@property (nonatomic, assign) BOOL         share;

@property (nonatomic, assign) long long    homeId;

// --------- sig mesh info
@property (nonatomic, strong) NSString *netKey;

@property (nonatomic, strong) NSString *appKey;

@end

#endif
