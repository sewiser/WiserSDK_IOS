//
// WiserSpeechService.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartSpeechService_h
#define WiserSmartSpeechService_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief WiserSmartSpeechService is used for voice control.
///
/// There's two main functions:
///     1. Audio to text. Convert voice data into text strings.
///     2. Execute text command. Device related commands can be done through this API.
///
@interface WiserSmartSpeechService : NSObject


/// Audio to text.
/// @param audioData Audio data.
/// @param audioRate Audio rate.
/// @param audioType Audio type.
/// @param homeId Home id.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)convertToTextWithAudioData:(NSData *)audioData
                         audioRate:(NSString *)audioRate
                         audioType:(NSString *)audioType
                            homeId:(long long)homeId
                           success:(nullable WSSuccessString)success
                           failure:(nullable WSFailureError)failure;


/// Execute audio commands.
/// @param speechText Voice text
/// @param homeId Home id
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)executeCommandWithSpeechText:(NSString *)speechText
                              homeId:(long long)homeId
                             success:(nullable WSSuccessDict)success
                             failure:(nullable WSFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* WiserSmartSpeechService_h */
