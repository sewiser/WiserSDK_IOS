//
//  NSObject+WSEncrypt.h
//  WiserSmartBaseKit
//
//
//

#import <Foundation/Foundation.h>

@interface NSString (WSSDKEnCrypt)

- (NSString *)wssdk_sha1String;

- (NSString *)wssdk_md5String;

- (NSString *)wssdk_sha256String;

- (NSString *)wssdk_aes128EncryptWithKey:(NSString *)key;

- (NSString *)wssdk_aes128NoPaddingEncryptWithKey:(NSString *)key;

- (NSString *)wssdk_aes128DecryptWithKey:(NSString *)key;

- (NSString *)wssdk_aes128NoPaddingDecryptWithKey:(NSString *)key;

- (NSString *)wssdk_aes256EncryptWithKey:(NSString *)key;

- (NSString *)wssdk_aes256DecryptWithKey:(NSString *)key;

- (NSString *)wssdk_hexRSAEncryptWithPublicKey:(NSString *)publicKey;

- (NSString *)wssdk_hexRSANoPaddingEncryptWithPublicKey:(NSString *)publicKey;

- (NSString *)wssdk_hmacSHA256StringWithKey:(NSString *)key;

@end


@interface NSData (WSSDKEncrypt)

- (NSString *)wssdk_md5String;

- (NSString *)wssdk_sha256String;

- (NSData *)wssdk_aes128EncryptWithKeyData:(NSData *)keyData;

- (NSData *)wssdk_aes128NoPaddingEncryptWithKeyData:(NSData *)keyData;

- (NSData *)wssdk_aes128DecryptWithKeyData:(NSData *)keyData;

- (NSData *)wssdk_aes128NoPaddingDecryptWithKeyData:(NSData *)keyData;

- (NSData *)wssdk_aes256EncryptWithKeyData:(NSData *)keyData;

- (NSData *)wssdk_aes256DecryptWithKeyData:(NSData *)keyData;

- (NSData *)wssdk_hmacSHA256DataWithKey:(NSString *)key;

@end
