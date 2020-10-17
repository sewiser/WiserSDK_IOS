//
//  WiserSmartSocketReadModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

//NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartSocketReadModel : NSObject <NSCopying>

@property (nonatomic, assign) int               index; // sequence number
@property (nonatomic, assign) int               type; // protocol
@property (nonatomic, assign) int               code; // success code
@property (nonatomic, strong) NSDictionary      *body; // message
@property (nonatomic, strong) NSString          *error; // error reason
@property (nonatomic, strong) NSData            *data;

// TCP data decrypt
+ (NSArray <WiserSmartSocketReadModel *> *)tcpResponseWithData:(NSData *)data gwId:(NSString *)gwId lpv:(NSString *)lpv localKey:(NSString *)localKey localKeyData:(NSData *)localKeyData;

// UDP data decrypt
+ (NSArray <WiserSmartSocketReadModel *> *)udpResponseWithData:(NSData *)data;

- (NSDictionary *)attribute;

@end

//NS_ASSUME_NONNULL_END
