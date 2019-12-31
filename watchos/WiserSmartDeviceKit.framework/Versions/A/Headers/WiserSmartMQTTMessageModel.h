//
//  WiserSmartMQTTMessageModel.h
//  WiserSmartDeviceKit
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMQTTMessageModel : NSObject

/**
 protocol
 */
@property (nonatomic, assign) NSInteger    protocol;

/**
 type
 */
@property (nonatomic, strong) NSString     *type;

/**
 data
 */
@property (nonatomic, strong) id           data;

/**
 devId
 */
@property (nonatomic, strong) NSString     *devId;

@end

NS_ASSUME_NONNULL_END
