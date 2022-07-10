//
//  MSSplashAdDelegate.h
//  MSAdSDKDev
//
//  Created by cyy on 2022/7/9.
//  Copyright © 2022 xyy. All rights reserved.
//

#ifndef MSSplashAdDelegate_h
#define MSSplashAdDelegate_h

@class MSSplashAd;

@protocol MSSplashAdDelegate <NSObject>

@optional
/**
 * 开始加载广告
 */
- (void)msSplashStartLoaded:(MSSplashAd *)splashAd;
/**
 * 开屏广告加载成功
 */
- (void)msSplashLoaded:(MSSplashAd *)splashAd;
/**
 开屏广告展示准备就绪，在此回调中调用show接口
 注意⚠️：如果调用是loadAndShowSplashAd接口则不需要调用show接口
 */
- (void)msSplashAdReadySuccess:(MSSplashAd *)splashAd;
/**
 * 开屏广告投屏成功
 */
- (void)msSplashPresent:(MSSplashAd *)splashAd;
/**
 *  开屏广告曝光成功
 */
- (void)msSplashShow:(MSSplashAd *)splashAd;
/**
 *  开屏广告曝光失败
 */
- (void)msSplashAdShowFail:(MSSplashAd *)splashAd error:(NSError *)error;
/**
 *  开屏广告失败（最终请求失败）
 */
- (void)msSplashError:(MSSplashAd *)splashAd withError:(NSError *)error;
/**
 *  开屏广告点击回调
 */
- (void)msSplashClicked:(MSSplashAd *)splashAd;
/**
 *  开屏广告将要关闭回调
 */
- (void)msSplashWillClosed:(MSSplashAd *)splashAd;
/**
 *  开屏广告关闭回调
 */
- (void)msSplashClosed:(MSSplashAd *)splashAd;
/**
 *  点击以后全屏广告页已经关闭
 */
- (void)msSplashDetailClosed:(MSSplashAd *)splashAd;
/**
 * 当用户点击跳过按钮时触发
 */
- (void)msSplashSkip:(MSSplashAd *)splashAd;
/**
 开屏被点击
 */
- (void)msSplashZoomOutViewAdDidClick:(UIView *)zoomView;
/**
 开屏被关闭
 */
- (void)msSplashZoomOutViewAdDidClose:(UIView *)zoomView;
/**
 开屏展示结束
 */
- (void)msSplashZoomOutViewAdDidFinish:(UIView *)zoomView;
/**
 开屏落地页被关闭
 */
- (void)msSplashZoomOutViewAdDidCloseOtherController:(UIView *)zoomView;

@end

#endif /* MSSplashAdDelegate_h */
