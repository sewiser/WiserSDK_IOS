//
//  AppDelegate.m
//  WiserSDKDemo
//
//  Created by huangkai on 2019/12/31.
//  Copyright © 2019 wiser. All rights reserved.
//

#import "AppDelegate.h"
#import <WiserSmartBaseKit/WiserSmartBaseKit.h>
#import <WiserSmartDeviceKit/WiserSmartDeviceKit.h>

#define APP_KEY <#(nonnull NSString *)#>
#define APP_SECRET <#(nonnull NSString *)#>

@interface AppDelegate ()

@property (nonatomic, strong) WiserSmartHome *home;
@property (nonatomic, strong) WiserSmartHomeManager *homeManager;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [[WiserSmartSDK sharedInstance] startWithAppKey:APP_KEY secretKey:APP_SECRET];
    [[WiserSmartUser sharedInstance] loginByEmail:@"86" email:@"YOUR_EMAIL" password:@"YOUR_PASSWORD" success:^{
        NSLog(@"log success");
        [self loadHome];
        NSLog(@"登录成功，可继续往下操作。");
    } failure:^(NSError *error) {
        NSLog(@"log error: %@", error);
    }];
    
    return YES;
}

- (void)loadHome {
    self.homeManager = [[WiserSmartHomeManager alloc] init];
    WEAKSELF_WSSDK
    [self.homeManager getHomeListWithSuccess:^(NSArray<WiserSmartHomeModel *> *homes) {
        
        // 没有家庭信息，去创建
        if (homes.count <= 0) {
            [weakSelf_WSSDK createHome];
        } else {
            // 这里有很多家庭，在这里，因为是 demo，我们取第一个，后续可根据实际情况切换家庭。
            
            //                for (WiserSmartHomeModel *model in  homes) {
            //                    if ([model.name isEqualToString:@"xxx"]) {
            weakSelf_WSSDK.home = [WiserSmartHome homeWithHomeId:homes.firstObject.homeId];
            [weakSelf_WSSDK getHomeDetail];
            //                    }
            //                }
            
            
            
        }
        
    } failure:^(NSError *error) {
        
    }];
}

- (void)createHome {
   /// create home
}


- (void)getHomeDetail {
    
    WEAKSELF_WSSDK
    [self.home getHomeDetailWithSuccess:^(WiserSmartHomeModel *homeModel) {
        
        // device list
        for (WiserSmartDeviceModel *device in weakSelf_WSSDK.home.deviceList) {
            if ([device.devId isEqualToString:@"xxx"]) {
                
            }
        }
        
    } failure:^(NSError *error) {
        
    }];
}

#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
