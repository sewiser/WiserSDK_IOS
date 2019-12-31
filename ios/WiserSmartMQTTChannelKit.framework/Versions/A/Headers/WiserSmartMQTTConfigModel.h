//
//  WiserSmartMQTTConfigModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartMQTTConfigModel : NSObject

@property (nonatomic, strong) NSString *clientId;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *password;

@property (nonatomic, strong) NSString *mbHost;
@property (nonatomic, assign) int port;
@property (nonatomic, assign) BOOL useSSL;

@end

NS_ASSUME_NONNULL_END
