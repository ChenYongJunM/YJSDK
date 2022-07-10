//
//  MSMacro.h
//  MSAdSDKDev
//  Created by cyy on 2022/7/9.
//  Copyright © 2022 xyy. All rights reserved.
//

#ifndef MSMacro_h
#define MSMacro_h

//是否是竖屏
#define IsPortrait ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown)

#define MSWS(weakSelf) __weak __typeof(&*self)weakSelf = self;

// RGB颜色转换（16进制->10进制）
#define MSUIColorFromRGB(rgbValue)\
\
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

#define MSUIColorFromRGBA(rgbValue)\
\
[UIColor colorWithRed:((float)((rgbValue & 0xFF000000) >> 24))/255.0 \
green:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
blue:((float)(rgbValue & 0xFF00 >> 8))/255.0 \
alpha:((float)(rgbValue & 0xFF))/255.0]

#define msScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define msScreenHeight ([UIScreen mainScreen].bounds.size.height)
#define msIs_iphone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define msIs_iPhoneX msScreenWidth >=375.0f && msScreenHeight >=812.0f&& msIs_iphone

/*状态栏高度*/
#define msStatusBarHeight (CGFloat)(msIs_iPhoneX?(44.0):(20.0))
/*导航栏高度*/
#define msNavBarHeight (44)
/*状态栏和导航栏总高度*/
#define msNavBarAndStatusBarHeight (CGFloat)(msIs_iPhoneX?(88.0):(64.0))
/*TabBar高度*/
#define msTabBarHeight (CGFloat)(msIs_iPhoneX?(49.0 + 34.0):(49.0))
/*顶部安全区域远离高度*/
#define msTopBarSafeHeight (CGFloat)(msIs_iPhoneX?(44.0):(0))
 /*底部安全区域远离高度*/
#define msBottomSafeHeight (CGFloat)(msIs_iPhoneX?(34.0):(0))
/*iPhoneX的状态栏高度差值*/
#define msTopBarDifHeight (CGFloat)(msIs_iPhoneX?(24.0):(0))
/*导航条和Tabbar总高度*/
#define msNavAndTabHeight (msNavBarAndStatusBarHeight + msTabBarHeight)


static inline BOOL isMSIPhoneXSeries() {
    if (@available(iOS 11.0, *)) {
        UIWindow *mainWindow = [[[UIApplication sharedApplication] delegate] window];
        if (mainWindow.safeAreaInsets.bottom > 0.0) {
            return YES;
        }
    }
    return NO;
}

#endif /* MSMacro_h */
