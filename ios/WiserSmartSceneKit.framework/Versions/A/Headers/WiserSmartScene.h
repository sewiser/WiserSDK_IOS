//
//  WiserSmartScene.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartSceneModel.h"
#import "WiserSmartSceneActionModel.h"
#import "WiserSmartSceneConditionModel.h"

/// @brief WiserSmartScene is used to add, edit delete and execute scenes. 
@interface WiserSmartScene : NSObject

/// Class method for initialize WiserSmartScene by WiserSmartSceneModel.
///
/// @param sceneModel scene model.
/// @return instance of WiserSmartScene.
+ (instancetype)sceneWithSceneModel:(WiserSmartSceneModel *)sceneModel;

/// Instance method for initialize WiserSmartScene by WiserSmartSceneModel.
///
/// @param sceneModel scene model.
/// @return instance of WiserSmartScene.
- (instancetype)initWithSceneModel:(WiserSmartSceneModel *)sceneModel;

/// Don't initialize an instance with init method.
///
/// @return    This method will return an unavailable instance.
- (instancetype)init NS_UNAVAILABLE;

/// Add a scene by all param
///
/// @param name               The scene name.
/// @param homeId            The home id.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param preConditionList       preconditions, like valid time period.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return WiserSmartSceneModel.
/// @param failure            When failure return WSFailureError.
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<WiserSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<WiserSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<WiserSmartSceneActionModel*> *)actionList
                  matchType:(WiserSmartConditionMatchType)matchType
                    success:(void (^)(WiserSmartSceneModel *sceneModel))success
                    failure:(WSFailureError)failure;

/// Add a new scene.Use a sceneModel with complete information of a scene.
///
/// @param sceneModel     WiserSmartSceneModel
/// @param homeId              The home id.
/// @param success            When success return WiserSmartSceneModel.
/// @param failure            When failure return WSFailureError.
+ (void)addNewSceneWithSceneModel:(WiserSmartSceneModel *)sceneModel
                           homeId:(long long)homeId
                          success:(void (^)(WiserSmartSceneModel *sceneModel))success
                          failure:(WSFailureError)failure;

/// Edit a existed scene with all param
///
/// @param name               The scene name.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param preConditionList       preconditions, like valid time period.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<WiserSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<WiserSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<WiserSmartSceneActionModel*> *)actionList
                  matchType:(WiserSmartConditionMatchType)matchType
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure;

/// Edit a existed scene.Use a sceneModel with complete information of a scene.
///
/// @param sceneModel     WiserSmartSceneModel
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)modifySceneWithSceneModel:(WiserSmartSceneModel *)sceneModel
                          success:(WSSuccessHandler)success
                          failure:(WSFailureError)failure;

/// Delete a existed scene.
///
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)deleteSceneWithSuccess:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;

/// Execute a scene.
///
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)executeSceneWithSuccess:(WSSuccessHandler)success
                        failure:(WSFailureError)failure;

/// Disable an automation, which will not executed automatically.
///
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)disableSceneWithSuccess:(WSSuccessHandler)success
                        failure:(WSFailureError)failure;

/// Enable an automation, which will be executed while the conditions are matched.
///
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)enableSceneWithSuccess:(WSSuccessHandler)success
                       failure:(WSFailureError)failure;

/// Cancel the request being executed.
- (void)cancelRequest;

#pragma mark - Recommend scene

/// Execute a recommended scene.
///
/// @param homeId              The home id.
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)triggerRecommendSceneWithHomeId:(long long)homeId success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Delete a recommended scene.
///
/// @param homeId              The home id.
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)removeRecommendSceneWithHomeId:(long long)homeId success:(WSSuccessHandler)success failure:(WSFailureError)failure;

/// Save a recommended scene, this scene can be modified by user. this scene will become a normal scene after save successfully, and the recommended scene will not show anymore.
///
/// @param homeId              The home id.
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
- (void)saveRecommendSceneWithHomeId:(long long)homeId success:(void (^)(WiserSmartSceneModel *sceneModel))success failure:(WSFailureError)failure;

#pragma mark - Deprecated

/// Add a scene by all param, (deprecated).
///
/// @param name               The scene name.
/// @param homeId            The home id.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return WiserSmartSceneModel.
/// @param failure            When failure return WSFailureError.
///
/// @deprecated This method is deprecated, Use -[WiserSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<WiserSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<WiserSmartSceneActionModel*> *)actionList
                  matchType:(WiserSmartConditionMatchType)matchType
                    success:(void (^)(WiserSmartSceneModel *sceneModel))success
                    failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");

/// Edit an existed scene with all param, (deprecated).
///
/// @param name               The scene name.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return WSSuccessHandler.
/// @param failure            When failure return WSFailureError.
///
/// @deprecated This method is deprecated, Use -[WiserSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<WiserSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<WiserSmartSceneActionModel*> *)actionList
                  matchType:(WiserSmartConditionMatchType)matchType
                    success:(WSSuccessHandler)success
                    failure:(WSFailureError)failure __deprecated_msg("This method is deprecated, Use -[WiserSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");
@end
