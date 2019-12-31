//
//  WSUtil.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

void tysdk_dispatch_async_on_default_global_thread(dispatch_block_t block);
void tysdk_dispatch_async_on_main_thread(dispatch_block_t block);
void tysdk_dispatch_sync_on_main_thread(dispatch_block_t block);

@interface WSSDKUtil : NSObject

#if TARGET_OS_IOS

+ (NSString *)tysdk_currentWifiSSID;

+ (NSString *)tysdk_currentWifiBSSID;

#endif

+ (uint32_t)tysdk_getIntValueByHex:(NSString *)str;

+ (NSString *)tysdk_getISOcountryCode;

+ (BOOL)tysdk_compareVesionWithDeviceVersion:(NSString *)deviceVersion appVersion:(NSString *)appVersion;

+ (NSData *)tysdk_xorEncodeData:(NSData *)sourceData keyData:(NSData *)keyData;

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

+ (NSString *)tysdk_currentExtensionString;

+ (BOOL)tysdk_isHostApp;

+ (BOOL)tysdk_isAppExtension;

+ (BOOL)tysdk_isWatchKitExtension;

@end
