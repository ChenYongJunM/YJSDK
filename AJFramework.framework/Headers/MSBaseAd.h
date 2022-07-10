//
//  MSBaseLoader.h
//  MSAdSDK
//
//  Created by cyy on 2022/7/9.
//  Copyright © 2022 xyy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MSSDKDefines.h"

@class MSAdModel;

NS_ASSUME_NONNULL_BEGIN

@interface MSBaseAd : UIView
/** 广告位id */
@property(nonatomic,strong) NSString *pid;
/** 广告类型 */
@property(nonatomic,assign) MSAdType adType;
/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，超过此时间则放弃此次广告展示机会。
 */
@property(nonatomic,assign) NSInteger fetchDelay;
/**
 获取媒体配置信息
 */
-(NSDictionary *)mediaExt;
/**
 获取本次请求id
 详解：请在加载成功后获取
 */
-(NSString *)adRequestIdentifier;
@end

NS_ASSUME_NONNULL_END
