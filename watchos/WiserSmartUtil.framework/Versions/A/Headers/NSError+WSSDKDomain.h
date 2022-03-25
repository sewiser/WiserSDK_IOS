//
//  NSError+WSDomain.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

#define WSErrorDomain @"com.wiser.www"

/**
 *
 * APP错误码枚举定义
 */
typedef enum {
    
    //接口请求网络错误 errorcode 不能变
    WISER_NETWORK_ERROR = 1500,
    
    //一般的错误
    WISER_COMMON_ERROR,
    
    //面板解压失败
    WISER_PANEL_DECOMPRESS_ERROR,
    
    //面板大小校验失败
    WISER_PANEL_SIZE_ERROR,
    
    //本地时间校验失败
    WISER_TIME_VALIDATE_FAILED,
    
    //设备已离线
    WISER_GW_OFFLINE,
    
    //用户已注册
    WISER_USER_HAS_EXISTS,
    
    //非法的dp下发
    WISER_ILLEGAL_DP_DATA,
    
    //设备已经被重置
    WISER_DEVICE_HAS_RESET,
    
    //用户登录信息丢失
    WISER_USER_SESSION_LOSS,
    
    //用户登录信息失效
    WISER_USER_SESSION_INVALID,
    
    //二维码识别错误
    WISER_QR_PROTOCOL_NOT_RECOGNIZED,
    
    //超时错误
    WISER_TIMEOUT_ERROR,
    
    //无可用 node ID
    WISER_NO_AVAILABLE_NODE_ID,
    
    //手机号格式错误
    WISER_MOBILE_FORMAT_ERROR,
    
    //手机号码输入错误
    WISER_MOBILE_ILLEGAL,
    
    //手机验证码错误
    WISER_MOBILE_CODE_ERROR,
    
    //邮箱格式错误
    WISER_EMAIL_FORMAT_ERROR,
    
    //邮箱输入错误
    WISER_EMAIL_ILLEGAL,
    
    //邮箱验证码错误
    WISER_EMAIL_CODE_ERROR,
    
    //用户不存在
    WISER_USER_NOT_EXISTS,
    
    //zigbee 群组子设备不能为空
    WISER_GROUP_DEVICE_LIST_NOT_EMPTY,
    
    //局域网离线
    WISER_SOCKET_TCP_DISCONNECT,
    
    //局域网解析错误
    WISER_SOCKET_TCP_RESPONSE_ERROR,
    
} WSSDKErrorCode;

@interface NSError (WSSDKDomain)

+ (instancetype)wssdk_errorWithErrorCode:(WSSDKErrorCode)errorCode errorMsg:(NSString *)errorMsg;

+ (NSError *)wssdk_errorWithCodeString:(NSString *)codeString errorMsg:(NSString *)errorMsg;

@end
