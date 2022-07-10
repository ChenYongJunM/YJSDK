//
//  MSSplashAd.h
//  MSAdSDK
//  开屏广告
//  Created by cyy on 2022/7/9.
//  Copyright © 2022 xyy. All rights reserved.
//


#import "MSBaseAd.h"
#import "MSSplashAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface MSSplashAd : MSBaseAd
/**
 *  委托对象
 */
@property(nonatomic,weak) id<MSSplashAdDelegate> delegate;
/**
 * 自定义底部视图
 * 提示：如果需要再次设置bottomView的frame
 * 建议在收到- (void)msSplashLoaded:(MSSplashAd *)splashAd回调中设置
 */
@property(nonatomic,strong) UIView *bottomView;
 /** 自定义跳过控件 */
@property(nonatomic,strong) UIView *skipView;
/**
 获取广告是否正在显示
 */
@property(nonatomic,assign,readonly) BOOL adShow;
/** 广告展示时间 */
@property(nonatomic,assign) NSInteger showTime;
/**
 开屏图片或者视频素材尺寸
 提示：
 1、splashSize只有在收到- (void)msSplashLoaded:(MSSplashAd *)splashAd
 回调后才能取到真实的size
 2、width & height 代表像素值
 */
@property(nonatomic,assign) CGSize splashSize;
/**
 配置开屏可点击文案
 提示：请在加载广告前配置
 */
@property(nonatomic,copy)NSString *splashClickText;
/**
 隐藏跳过按钮 （YES：隐藏 NO：展示）默认展示
 注意⚠️：
 1、如果设置该属性为YES（隐藏），不支持隐藏跳过按钮的广告平台，将会从当前请求队列中移除，不再加载广告
 2、加载广告前设置有效
 3、仅ms和穿山甲支持设置隐藏跳过按钮
 */
@property(nonatomic,assign)BOOL hideSkipButton;
/**
 开屏广告页是否开启状态栏 hideSplashStatusBar（YES：隐藏 NO：展示）默认展示
 只支持MS平台
 */
@property(nonatomic,assign)BOOL hideSplashStatusBar;
/**
获取开屏点睛view
注意：
 1、收到msSplashAdReadySuccess回调后获取开屏点睛view
 2、推荐尺寸比例为9:16，最小尺寸推荐为126*224
 3、切记⚠️⚠️⚠️不要在splashZoomView添加UITapGestureRecognizer手势，否则会阻断事件响应链广告无法点击
 */
@property(nonatomic,strong,readonly)UIView *splashZoomView;
/**
 设置点睛VC
 注意：
 1、请在展示出开屏广告后设置VC，⚠️传入的VC不能present其他VC，否则页面无法跳转
 */
@property(nonatomic,weak)UIViewController *splashZoomViewController;
/**
 加载并显示
 详解：调用此接口，sdk内部会加载广告并在成功获取到广告物料后进行展示
 注意：调用此接口后无需再调用show接口
 */
- (void)loadAndShowSplashAd:(NSString *)pid;
/**
 *  广告发起请求并展示在Window中
 *  详解：[可选]发起拉取广告请求,并将获取的广告以全屏形式展示在传入的Window参数中
 *  提示: Splash广告只支持竖屏
 *  @param window 展示全屏开屏的容器
 *  注意⚠️sdk内部是weak引用window，保证展现广告过程中window不会被释放
 *  @param pid 广告id
 */
- (void)loadAndShowSplashAd:(NSString *)pid inWindow:(UIWindow *)window;
//加载
/**
 加载广告
 详解：调用该接口加载广告
 注意：如果调用此接口加载广告，请在收到msSplashAdReadySuccess回调后调用show接口
 */
- (void)loadSplashAd:(NSString *)pid;
/**
 注意⚠️为保证开屏广告正常展示，请在收到msSplashAdReadySuccess回调后调用该展示接口
 */
- (void)showSplashAd;
/**
 显示在指定window上
 @param window 指定window，该window需设置rootViewController后传入，否则会存在广告落地页无法弹出的情况
 提示：
 1、注意⚠️为保证开屏广告正常展示，请在收到msSplashAdReadySuccess回调后调用该接口，加载广告方式请务必调用- (void)loadSplashAd:(NSString *)pid;接口
 */
- (void)showSplashAdInWindow:(UIWindow *)window;
//取消加载
-(void)cancel;

@end

NS_ASSUME_NONNULL_END
