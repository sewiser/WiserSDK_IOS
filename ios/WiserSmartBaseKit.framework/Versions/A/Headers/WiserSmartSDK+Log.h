//
//  WiserSmartSDK+Log.h
//  WiserSmartBaseKit
//
//
//

#import "WiserSmartSDK.h"

NS_ASSUME_NONNULL_BEGIN


void WSSDKLog(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *format, ...);

#undef WSLog
#undef WSSDKLogDebug
#undef WSSDKLogInfo
#undef WSSDKLogWarn
#undef WSSDKLogError

#define WSLog(...) \
    WSSDKLog(1, @"WiserSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define WSSDKLogDebug(...) \
    WSSDKLog(0, @"WiserSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define WSSDKLogInfo(...) \
    WSSDKLog(1, @"WiserSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define WSSDKLogWarn(...) \
    WSSDKLog(2, @"WiserSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define WSSDKLogError(...) \
    WSSDKLog(3, @"WiserSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

@interface WiserSmartSDK (Log)

/// Debug mode
/// 调试模式
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END
