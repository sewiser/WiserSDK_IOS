//
// WiserSmartHome+SIGMesh.h
// WiserSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartHome (SIGMesh)

@property (nonatomic, strong, readonly) WiserSmartBleMeshModel *sigMeshModel;

/// Get the sig mesh list under the family
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshListWithSuccess:(void(^)(NSArray <WiserSmartBleMeshModel *> *list))success
                          failure:(WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
