//
//  WiserSmartSocketWriteModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartSocketWriteModel : NSObject <NSCopying>

@property (nonatomic, strong) NSString          *gwId;
@property (nonatomic, assign) BOOL              encrypt;

@property (nonatomic, assign) int               index; // sequence number
@property (nonatomic, assign) int               type; // protocol
@property (nonatomic, strong) NSString          *lpv; // version
@property (nonatomic, strong) NSDictionary      *body; // body
@property (nonatomic, strong) NSString          *localKey; // local key
@property (nonatomic, strong) NSData            *data; // data
@property (nonatomic, strong) NSData            *localKeyData; // local key


@property (nonatomic, copy) WSSuccessDict       successBlock;
@property (nonatomic, copy) WSFailureHandler    failureBlock;

// data encryption
- (NSData *)buildRequestData;

- (NSDictionary *)attributes;

@end

NS_ASSUME_NONNULL_END
