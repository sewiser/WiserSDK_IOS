//
// WiserSmartHTTPDNS.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartHTTPDNS_h
#define WiserSmartHTTPDNS_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief WiserSmartHTTPDNS is another solution for DNS query instead of system DNS service.
///
/// The DNS query can be done through http to prevent DNS cache pollution.
@interface WiserSmartHTTPDNS : NSObject

+ (instancetype)sharedInstance;

/// Asynchronous resolution interface, first query the cache, if it exists then return the result, if not return nil and asynchronous domain name resolution to update the cache.
/// @param host Domain name (e.g. www.wiser.com).
/// @return The resolution result corresponding to the domain name.
- (NSString *)getIpWithHost:(NSString *)host;


/// Set whether the domain name is downgraded or not.
/// @param host Domain Name.
/// @param enable Whether to downgrade.
- (void)setDegradationWithHost:(NSString *)host enable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END

#endif /* WiserSmartHTTPDNS_h */
