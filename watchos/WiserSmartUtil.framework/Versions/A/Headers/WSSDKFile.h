//
//  WSSDKFile.h
//  Pods-WiserSmartHomeKit_Tests
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WSSDKFile : NSObject

+ (instancetype)sharedInstance;

- (NSString *)wssdk_getAtDocumentPath:(NSString *)fileName;

- (BOOL)wssdk_mkdirAtPath:(NSString *)dir;

- (BOOL)wssdk_fileExistsAtPath:(NSString *)filePath;

- (BOOL)wssdk_delFileAtPath:(NSString *)filepath;

- (BOOL)wssdk_createFileAtPath:(NSString *)filePath;


@end

NS_ASSUME_NONNULL_END
