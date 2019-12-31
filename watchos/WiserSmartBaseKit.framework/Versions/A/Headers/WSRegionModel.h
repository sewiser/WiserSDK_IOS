//
//  WSLoginRegionModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WSRegionModel : NSObject


/**
 region name
 */
@property (nonatomic, strong) NSString *name;

/**
 region code
 */
@property (nonatomic, strong) NSString *region;

/**
 default
 */
@property (nonatomic, assign) BOOL isDefault;

@end

NS_ASSUME_NONNULL_END
