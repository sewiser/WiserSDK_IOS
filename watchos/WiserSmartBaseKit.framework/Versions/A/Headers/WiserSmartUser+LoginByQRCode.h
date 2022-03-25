//
// WiserSmartUser+LoginByQRCode.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartUser_LoginByQRCode_h
#define WiserSmartUser_LoginByQRCode_h

#import "WiserSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartUser (LoginByQRCode)

#pragma mark - Scan code to authorize third-party app login

/// Authorize third-party applications to login by QR code.
/// @param codeInfo QR code information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQRcode:(NSDictionary *)codeInfo success:(nullable WSSuccessID)success failure:(nullable WSFailureError)failure;

/// Get third-party applications info.
/// @param codeInfo  QR code information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)userInfo:(NSDictionary *)codeInfo success:(nullable WSSuccessID)success failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* WiserSmartUser_LoginByQRCode_h */
