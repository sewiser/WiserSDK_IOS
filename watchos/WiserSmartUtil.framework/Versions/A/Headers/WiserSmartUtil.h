//
//  WiserSmartUtil.h
//  WiserSmartBaseKit
//
//
//

#ifndef WiserSmartUtil_h
#define WiserSmartUtil_h

#import <Foundation/Foundation.h>

#import "NSDate+WSSDKOffset.h"
#import "NSError+WSSDKDomain.h"
#import "NSNumber+WSSDKRandom.h"
#import "NSObject+WSSDKHex.h"
#import "NSObject+WSSDKJSON.h"
#import "NSObject+WSSDKURL.h"
#import "NSObject+WSSDKEncrypt.h"
#import "NSObject+WSSDKCategory.h"
#import "NSBundle+WSSDKLanguage.h"
#import "NSMutableDictionary+WSSDKCategory.h"

#import "WSSDKUtil.h"
#import "WSSDKDevice.h"
#import "WSSDKUserDefault.h"
#import "WSSDKSafeMutableArray.h"
#import "WSSDKSafeMutableDictionary.h"
#import "WSSDKNotification.h"
#import "WSSDKLogUtils.h"
#import "WSSDKFile.h"
#if TARGET_OS_IOS
#import "WiserSmartReachability.h"
#endif

#define WSSDK_SINGLETON \
+ (instancetype)sharedInstance;

#define WSSDK_DEF_SINGLETON \
+ (instancetype)sharedInstance { \
    static id instance; \
    static dispatch_once_t once; \
    dispatch_once(&once, ^{ \
        instance = [[self alloc] init]; \
    }); \
    return instance; \
}

#define WEAKSELF_WSSDK __weak __typeof(&*self)weakSelf_WSSDK = self;

typedef void (^WSSuccessHandler)(void);
typedef void (^WSSuccessDict)(NSDictionary *dict);
typedef void (^WSSuccessString)(NSString *result);
typedef void (^WSSuccessList)(NSArray *list);
typedef void (^WSSuccessBOOL)(BOOL result);
typedef void (^WSSuccessID)(id result);
typedef void (^WSSuccessInt)(int result);
typedef void (^WSSuccessLongLong)(long long result);
typedef void (^WSSuccessData)(NSData *data);

typedef void (^WSFailureHandler)(void);
typedef void (^WSFailureError)(NSError *error);

#endif /* WiserSmartUtil_h */
