//
//  WiserSmartStandSchemaModel.h
//  WiserSmartDeviceKit-iOS
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 上报的映射策略
@interface WiserSmartStatusSchemaModel : NSObject

@property (nonatomic, strong) NSString     *strategyValue; // 映射规则
@property (nonatomic, strong) NSString     *strategyCode; // 策略代号，目前支持 10 余种
@property (nonatomic, strong) NSString     *dpCode; // 上报的 dpId 对应的 dpCode，不是标准 dpCode
@property (nonatomic, strong) NSString     *standardType; // 标准后的 dpValue 类型


@end

// 下发的映射策略
@interface WiserSmartFunctionSchemaModel : NSObject

@property (nonatomic, strong) NSString     *strategyCode; // 策略代号，目前支持 10 余种
@property (nonatomic, strong) NSString     *strategyValue; // 映射规则
@property (nonatomic, strong) NSString     *standardCode; // 标准化的 dpCode
@property (nonatomic, strong) NSString     *standardType; // 标准后的 dpValue 类型

@end


@interface WiserSmartStandSchemaModel : NSObject

@property (nonatomic, assign) BOOL isProductCompatibled;

@property (nonatomic, strong) NSArray<WiserSmartStatusSchemaModel *> *statusSchemaList;

@property (nonatomic, strong) NSArray<WiserSmartFunctionSchemaModel *> *functionSchemaList;

@end

NS_ASSUME_NONNULL_END
