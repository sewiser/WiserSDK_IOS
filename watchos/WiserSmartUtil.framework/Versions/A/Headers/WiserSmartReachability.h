

#if TARGET_OS_IOS
#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>


/** 
 * Create NS_ENUM macro if it does not exist on the targeted version of iOS or OS X.
 *
 * @see http://nshipster.com/ns_enum-ns_options/
 **/
#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

extern NSString *const kWiserSmartReachabilityChangedNotification;

typedef NS_ENUM(NSInteger, WSSDKNetworkStatus) {
    // Apple NetworkStatus Compatible Names.
    WSSDKNotReachable = 0,
    WSSDKReachableViaWiFi = 2,
    WSSDKReachableViaWWAN = 1
};

@class WiserSmartReachability;

typedef void (^WiserSmartNetworkReachable)(WiserSmartReachability * reachability);
typedef void (^WiserSmartNetworkUnreachable)(WiserSmartReachability * reachability);


@interface WiserSmartReachability : NSObject

@property (nonatomic, copy) WiserSmartNetworkReachable    reachableBlock;
@property (nonatomic, copy) WiserSmartNetworkUnreachable  unreachableBlock;

@property (nonatomic, assign) BOOL reachableOnWWAN;


+(WiserSmartReachability*)reachabilityWithHostname:(NSString*)hostname;
// This is identical to the function above, but is here to maintain
//compatibility with Apples original code. (see .m)
+(WiserSmartReachability*)reachabilityWithHostName:(NSString*)hostname;
+(WiserSmartReachability*)reachabilityForInternetConnection;
+(WiserSmartReachability*)reachabilityWithAddress:(void *)hostAddress;
+(WiserSmartReachability*)reachabilityForLocalWiFi;

-(WiserSmartReachability *)initWithReachabilityRef:(SCNetworkReachabilityRef)ref;

-(BOOL)startNotifier;
-(void)stopNotifier;

-(BOOL)isReachable;
-(BOOL)isReachableViaWWAN;
-(BOOL)isReachableViaWiFi;

// WWAN may be available, but not active until a connection has been established.
// WiFi may require a connection for VPN on Demand.
-(BOOL)isConnectionRequired; // Identical DDG variant.
-(BOOL)connectionRequired; // Apple's routine.
// Dynamic, on demand connection?
-(BOOL)isConnectionOnDemand;
// Is user intervention required?
-(BOOL)isInterventionRequired;

-(WSSDKNetworkStatus)currentReachabilityStatus;
-(SCNetworkReachabilityFlags)reachabilityFlags;
-(NSString*)currentReachabilityString;
-(NSString*)currentReachabilityFlags;

@end

#endif
