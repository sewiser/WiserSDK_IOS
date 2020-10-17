//
//  WiserSmartUser+LoginByQRCode.h
//  WiserSmartBaseKit
//
//
//

#import "WiserSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartUser (LoginByQRCode)

#pragma mark - 扫码授权第三方应用登录

/**
*  Authorize third-party applications to login by QR code.
*  授权第三方应用登录
*
*  @param codeInfo    QR code information
*  @param success     Success block
*  @param failure     Failure block
*
*/
- (void)loginByQRcode:(NSDictionary *)codeInfo success:(nullable WSSuccessID)success failure:(nullable WSFailureError)failure;

/**
*  Get third-party applications info.
*  获取第三方应用信息
*
*  @param codeInfo    QR code information
*  @param success     Success block
*  @param failure     Failure block
*/
- (void)userInfo:(NSDictionary *)codeInfo success:(nullable WSSuccessID)success failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END
