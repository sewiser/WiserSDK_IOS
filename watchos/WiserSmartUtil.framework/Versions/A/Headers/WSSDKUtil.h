//
//  WSUtil.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

void wssdk_dispatch_async_on_default_global_thread(dispatch_block_t block);
void wssdk_dispatch_async_on_main_thread(dispatch_block_t block);
void wssdk_dispatch_sync_on_main_thread(dispatch_block_t block);

@interface WSSDKUtil : NSObject

#if TARGET_OS_IOS

+ (NSString *)wssdk_currentWifiSSID;

+ (NSString *)wssdk_currentWifiBSSID;

#endif

+ (uint32_t)wssdk_getIntValueByHex:(NSString *)str;

+ (NSString *)wssdk_getISOcountryCode;

+ (BOOL)wssdk_compareVesionWithDeviceVersion:(NSString *)deviceVersion appVersion:(NSString *)appVersion;

+ (NSData *)wssdk_xorEncodeData:(NSData *)sourceData keyData:(NSData *)keyData;

@end


extern NSString * const WSUtilHostAppExtensionString;
extern NSString * const WSUtilTodayWidgetExtensionString;
extern NSString * const WSUtilIntentExtensionString;
extern NSString * const WSUtilIntentUIExtensionString;
extern NSString * const WSUtilWatchKitExtensionString;

/**
 *  @category WSUtil(AppExtension)
 *  To determine which process the code runs in (App/AppExtension/WatchKitExtension).
 *  运行时判断当前代码运行在哪个进程
 */
@interface WSSDKUtil (AppSDKExtension)

+ (NSString *)wssdk_currentExtensionString;

+ (BOOL)wssdk_isHostApp;

+ (BOOL)wssdk_isAppExtension;

+ (BOOL)wssdk_isWatchKitExtension;

@end
