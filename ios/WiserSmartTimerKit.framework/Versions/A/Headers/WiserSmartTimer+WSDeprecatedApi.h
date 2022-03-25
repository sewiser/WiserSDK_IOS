//
// WiserSmartTimer+WSDeprecatedApi.h
// WiserSmartTimerKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartTimer_WSDeprecatedApi_h
#define WiserSmartTimer_WSDeprecatedApi_h

#import "WiserSmartTimer.h"

/// @deprecated The old timer api, deprecated.
///
/// Can use WiserSmartTimer.h to set timer
///
@interface WiserSmartTimer (WSDeprecatedApi)

/// Add a new task for timer.
/// @param task The name of task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID for which the timer task needs to run on.
/// @param time The specific time to trigger this task.
/// @param dps The data point dictionary.
/// @param timeZone The timezone of the device.
/// @param success If successfully added the task, this block will be called.
/// @param failure If error occurred while adding the task, this block will be called.
/// @deprecated This method is deprecated, Use WiserSmartTimer::addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure: instead.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   devId:(NSString *)devId
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                timeZone:(NSString *)timeZone
                 success:(WSSuccessHandler)success
                 failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure:] instead");


/// Add timed tasks。
/// @param task The name of the task.
/// @param loops Number of cycles.
/// @param devId The device ID.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00, if the phone time zone is not taken.
/// @param isAppPush A boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success  Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure: instead.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   devId:(NSString *)devId
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                timeZone:(NSString *)timeZone
               isAppPush:(BOOL)isAppPush
               aliasName:(NSString *)aliasName
                 success:(WSSuccessHandler)success
                 failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure:] instead");


/// Update timer task status.
/// @param task The name of the task.
/// @param devId The device ID.
/// @param status Timing group status.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::updateTimerStatusWithTask:bizId:bizType:status:success:failure: instead instead.
- (void)updateTimerTaskStatusWithTask:(NSString *)task
                                devId:(NSString *)devId
                               status:(NSInteger)status
                              success:(WSSuccessHandler)success
                              failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer updateTimerStatusWithTask:bizId:bizType:status:success:failure:] instead");


/// Update timeclock status.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param status Timing clock status.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::updateTimerStatusWithTimerId:bizId:bizType:status:success:failure: instead instead.
- (void)updateTimerStatusWithTask:(NSString *)task
                            devId:(NSString *)devId
                          timerId:(NSString *)timerId
                           status:(NSInteger)status
                          success:(WSSuccessHandler)success
                          failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer updateTimerStatusWithTimerId:bizId:bizType:status:success:failure:] instead");


/// Delete time clock.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::removeTimerWithTimerId:bizId:bizType:success:failure: instead.
- (void)removeTimerWithTask:(NSString *)task
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer removeTimerWithTimerId:bizId:bizType:success:failure:] instead");


/// Update the timer.
/// @param task The name of the timer task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure: instead.
- (void)updateTimerWithTask:(NSString *)task
                      loops:(NSString *)loops
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                       time:(NSString *)time
                        dps:(NSDictionary *)dps
                   timeZone:(NSString *)timeZone
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure:] instead");


/// Update the timer.
/// @param task The name of the timer task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00.
/// @param isAppPush A boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure: instead.
- (void)updateTimerWithTask:(NSString *)task
                      loops:(NSString *)loops
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                       time:(NSString *)time
                        dps:(NSDictionary *)dps
                   timeZone:(NSString *)timeZone
                  isAppPush:(BOOL)isAppPush
                  aliasName:(NSString *)aliasName
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure:] instead");


/// Get all timer clocks under timer task.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use WiserSmartTimer::getTimerListWithTask:bizId:bizType:success:failure: instead.
- (void)getTimerWithTask:(NSString *)task
                   devId:(NSString *)devId
                 success:(void(^)(NSArray<WSTimerModel *> *list))success
                 failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use [WiserSmartTimer getTimerListWithTask:bizId:bizType:success:failure:] instead");


@end


#endif /* WiserSmartTimer_WSDeprecatedApi_h */
