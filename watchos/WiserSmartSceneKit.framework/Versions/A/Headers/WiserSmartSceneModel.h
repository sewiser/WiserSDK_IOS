//
//  WiserSmartSceneModel.h
//  WiserSmartSceneKit
//
//  Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#import <Foundation/Foundation.h>

#import "WiserSmartSceneActionModel.h"
#import "WiserSmartSceneConditionModel.h"
#import "WiserSmartScenePreConditionModel.h"


/// The two types of condition match. Provides any and all types.
typedef enum : NSUInteger {
    /// The condition match any type, it means any one condition in the scene is be matched, it will be executed.
    WiserSmartConditionMatchAny = 1,
    /// The condition match all type, it means all conditions in the scene is be matched, it will be executed.
    WiserSmartConditionMatchAll
} WiserSmartConditionMatchType;

/// The three types of recommend scene. Provides none, scene and automation types.
typedef enum : NSUInteger {
    /// The none recommend type, indicates it is neither tap-to-run nor automation scene.
    WiserSmartSceneRecommendTypeNone,
    /// The tap-to-run recommend scene type.
    WiserSmartSceneRecommendTypeScene,
    /// The automation recommend scene type.
    WiserSmartSceneRecommendTypeAutomation
} WiserSmartSceneRecommendType;

/// The three types of collection scene. Provides none, scene and automation types.
typedef enum : NSUInteger {
    /// The none collection type, indicates it is neither tap-to-run nor automation scene.
    WiserSmartSceneCollectionTypeNone,
    /// The tap-to-run collection scene type.
    WiserSmartSceneCollectionTypeScene,
    /// The automation collection scene type.
    WiserSmartSceneCollectionTypeAutomation
} WiserSmartSceneCollectionType;

/// The two types of device list on the panel when creating scene.
typedef NS_ENUM(NSInteger, WiserSmartScenePanelType) {
    /// The non all device panel type, indicates you can only add zigbee device in the scene action.
    WiserSmartScenePanelTypeNonAllDevevice = 0,
    /// The all device panel type, indicates you can add zigbee device and wifi device in the scene action.
    WiserSmartScenePanelTypeAllDevices
};

/// @brief WiserSmartSceneModel provides more data attributes for developers to implement business logic of the scene.
@interface WiserSmartSceneModel : NSObject<NSCoding>

/// The scene id, it's unique. But only custom scene has this property.
@property (nonatomic, strong) NSString *sceneId;

/// The scene code, only default scene has this property.
@property (nonatomic, strong) NSString *code;

/// The scene name, it describes what the scene is used to.
@property (nonatomic, strong) NSString *name;

/// Whether the scene enabled, this status is used to automation scene and default enabled in tap-to-run scene.
@property (nonatomic, assign) BOOL enabled;

/// Whether show scene in first page, the status only can be switched when editing scene.
@property (nonatomic, assign) BOOL stickyOnTop;

/// The pre condition object model list is used to set the valid time period for automation scene. More information about WiserSmartScenePreConditionModel, you can see WiserSmartScenePreConditionModel class.
@property (nonatomic, strong) NSArray<WiserSmartScenePreConditionModel *> *preConditions;

/// The condition model list,
@property (nonatomic, strong) NSArray<WiserSmartSceneConditionModel *> *conditions;

/// The action model list,
@property (nonatomic, strong) NSArray<WiserSmartSceneActionModel *> *actions;

/// The device list,
@property (nonatomic, strong) NSArray *devList;

/// The scene background icon URL
@property (nonatomic, copy) NSString *coverIcon;

/// The scene background color hex string.
@property (nonatomic, copy) NSString *displayColor;

/// The scene background URL, when created a new scene, use the URL provided by Wiser.
@property (nonatomic, strong) NSString *background;

/// The condition match type, For detail you can see WiserSmartConditionMatchType enumeration value introduction.
@property (nonatomic, assign) WiserSmartConditionMatchType matchType;

/// Whether this scene is bound to a panel. This attribute only supports standard zigbee devices.
@property (nonatomic, assign) BOOL boundForPanel;

/// Whether this scene is bound by a panel with new firmware. The new panel indicates that the scene supports zigbee devices and wifi devices.
@property (nonatomic, assign) BOOL boundForWiFiPanel;

/// Whether the automation scene supports to execute in LAN, If YES indicates the automation scene can be executed when zigbee gateway is offline.
@property (nonatomic, assign) BOOL localLinkage;

/// Whether the tap-to-run scene supports to execute in LAN, If YES indicates you can directly notify the zigbee gateway to execute the scene through TCP or MQTT messages.
@property (nonatomic, assign) BOOL newLocalScene;

/// The bound panel type, For detail you can see WiserSmartScenePanelType enumeration value introduction.
@property (nonatomic, assign) WiserSmartScenePanelType panelType;

/// The recommend scene type, For detail you can see WiserSmartSceneRecommendType enumeration value introduction.
@property (nonatomic, assign) WiserSmartSceneRecommendType recommendType;

/// The collection scene type, For detail you can see WiserSmartSceneCollectionType enumeration value introduction.
@property (nonatomic, assign) WiserSmartSceneCollectionType collectionType;

/// The recommend scene description.
@property (nonatomic, copy) NSString *recomDescription;

/// The recommended coefficient value of recommended scene, the range value is 0-100.
@property (nonatomic, assign) CGFloat recomCoefficient;

/// The timestamp when the automation scene will be automatically closed, The zero means it has not been set.
@property (nonatomic, assign) long long  disableTime;

#pragma mark - Business field

/// Whether the scene has already obtained details.
@property (nonatomic, assign) BOOL cached;

/// The arrow icon URL.
@property (nonatomic, copy) NSString *arrowIconUrl;

/// The hot value of recommended scene
@property (nonatomic, copy) NSString *hotCount;
#pragma mark - Deprecated

/// The scene subtitle.
@property (nonatomic, strong) NSString *subTitle __deprecated;

/// The scene edit icon URL.
@property (nonatomic, strong) NSString *editIcon __deprecated;

/// The scene display icon URL.
@property (nonatomic, strong) NSString *displayIcon __deprecated;

@end
