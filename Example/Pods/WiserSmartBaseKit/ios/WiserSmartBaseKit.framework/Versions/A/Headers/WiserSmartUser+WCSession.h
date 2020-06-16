//
//  WiserSmartUser+WCSession.h
//  WiserSmartBaseKit
//
//
//

#import "WiserSmartUser.h"

/**
 We don't link WatchConnectivity.framework because not all developers need this feature.
 If the sdk links WatchConnectivity.framework and don't use this feature, your app might be reject when submit to Apple Store.
 So please link WatchConnectivity.framework manually and use it on demand.
 */
//#import <WatchConnectivity/WatchConnectivity.h>

@class WCSession, WCSessionUserInfoTransfer;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const WiserSmartUserWCSessionKey;

@interface WiserSmartUser (WCSession)

/**
 Sync WiserSmartUser context to iWatch. When user login/logout/session expired on iPhone, please use this method to sync manually.
 同步WiserSmartUser用户信息到iWatch。当用户在iPhone登录、登出、session过期时，需要手动调用此方法同步。
 
 Example:
 
 [WiserSmartUser.sharedInstance updateApplicationContext:session];

 @param session session
 @return results of synchron
 */
- (BOOL)updateApplicationContext:(WCSession *)session API_AVAILABLE(ios(9.0));

/**
 Receive WiserSmartUser context from iPhone.
 从iPhone获取WiserSmartUser用户信息。

 @param applicationContext applicationContext
 */
- (void)didReceiveApplicationContext:(NSDictionary *)applicationContext API_AVAILABLE(watchos(2.0));

@end

NS_ASSUME_NONNULL_END
