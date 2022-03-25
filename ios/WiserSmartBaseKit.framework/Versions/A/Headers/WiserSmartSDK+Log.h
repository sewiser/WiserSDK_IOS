//
// WiserSmartSDK+Log.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartSDK_Log_h
#define WiserSmartSDK_Log_h

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

/// Debug mode, default is false. Verbose log will print into console if opened.
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END

#endif /* WiserSmartSDK_Log_h */
