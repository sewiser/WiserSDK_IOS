//
// WiserSmartHome+BleMesh.h
// WiserSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

@interface WiserSmartHome (BleMesh)

@property (nonatomic, strong, readonly) WiserSmartBleMeshModel *meshModel;

/// Get the mesh list under the family.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getMeshListWithSuccess:(void(^)(NSArray <WiserSmartBleMeshModel *> *list))success
                       failure:(WSFailureError)failure;


@end
