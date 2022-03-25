//
// WiserSmartUser+Anonymous.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartUser_Anonymous_h
#define WiserSmartUser_Anonymous_h

#import "WiserSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartUser (Anonymous)

/// Anonymous register.
/// @param countryCode Country code.
/// @param userName User Name, e.g. : [UIDevice currentDevice].name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)registerAnonymousWithCountryCode:(NSString *)countryCode
                                userName:(NSString *)userName
                                 success:(nullable WSSuccessHandler)success
                                 failure:(nullable WSFailureError)failure;

/// Delete anonymous account.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteAnonymousAccountWithSuccess:(WSSuccessHandler)success
                                  failure:(WSFailureError)failure;

/// Bind username.
/// @param countryCode Country code.
/// @param userName Mobile phone number or Email address.
/// @param code Verification code.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)usernameBindingWithCountryCode:(NSString *)countryCode
                              userName:(NSString *)userName
                                  code:(NSString *)code
                              password:(NSString *)password
                               success:(nullable WSSuccessHandler)success
                               failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* WiserSmartUser_Anonymous_h */
