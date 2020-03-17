//
//  CSBusQRCodeSDKManager.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/7.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class CSBusConfiguration;
@class CSBusUsersModel;
@class CSBusTradeRecordModel;
@class CSBusRechargeRecordModel;

/** 获取短信验证码类型 */
typedef NS_ENUM(NSInteger, CSBusSMSType) {
    /** 注册短信验证码 */
    CSBusSMSTypeRegister    = 1,
    /** 登录短信验证码 */
    CSBusSMSTypeLogin       = 3
};

/** 登录类型 */
typedef NS_ENUM(NSInteger, CSBusLoginType) {
    /** 令牌登录 */
    CSBusLoginTypeToken    = 1,
    /** 短信验证码登录 */
    CSBusLoginTypeSMSCode  = 2
};

@interface CSBusQRCodeSDKManager : NSObject
/** 配置信息 */
@property (strong, nonatomic) CSBusConfiguration *configuration;
/** 导航栏返回按钮颜色 (默认白色) */
@property (strong, nonatomic) UIColor *navigationBarBackItemTintColor;

/** SDK Manager */
+ (CSBusQRCodeSDKManager *)sharedInstance;

/** 设置LicenseKey
@param licenseKey 分配给合作渠道的LicenseKey
 */
- (void)setLicenseKey:(NSString *)licenseKey;

/** 输出可供调试参考的log日志，默认YES */
- (void)setLogEnabled:(BOOL)logEnabled;

/** 是否登录 */
- (BOOL)isLogined;

/** 登录用户 */
- (CSBusUsersModel *)loginedUser;

/** 注册长沙公交用户
@param userToken 合作渠道APP的用户唯一标识
@param phoneNo 合作渠道APP的用户手机号码
@param idNo 合作渠道APP的用户身份证号码
@param realName 合作渠道APP的用户真实姓名
@param smsCode 短信验证码
@param callback 回调
*/
- (void)registerBusUserWithUserToken:(NSString *)userToken
                             phoneNo:(NSString *)phoneNo
                                idNo:(NSString *)idNo
                            realName:(NSString *)realName
                             smsCode:(NSString *)smsCode
                      completeHandle:(void(^)(CSBusUsersModel *model, NSError *error))callback;

/** 登录长沙公交系统
@param userToken 合作渠道APP的用户唯一标识
@param code 用户秘钥
@param loginType 登录类型(1:令牌登录、2:短信验证码登录)
@param callback 回调
*/
- (void)loginWithUserToken:(NSString *)userToken
                      code:(NSString *)code
                 loginType:(CSBusLoginType)loginType
            completeHandle:(void(^)(CSBusUsersModel *model, NSError *error))callback;

/** 注销登录
@param callback 回调
*/
- (void)logoutWithCompleteHandle:(void(^)(BOOL success, NSError *error))callback;

/** 获取已注册到长沙公交系统的用户信息
@param callback 回调
*/
- (void)getUserInfoWithCompleteHandle:(void(^)(CSBusUsersModel *model, NSError *error))callback;

/** 获取长沙公交乘车码
@param callback 回调
*/
- (void)getBusQRCodeWithCompleteHandle:(void(^)(NSString *qrcodeStr, NSError *error))callback;

/** 使用长沙银行呼啦支付充值
@param amount 充值金额(单位:分)
@param sourceViewController 源视图控制器
@param callback 回调
*/
- (void)useBCSPayRechargeWithAmount:(NSNumber *)amount
               sourceViewController:(UIViewController *)sourceViewController
                     completeHandle:(void(^)(NSString *tradeNo, BOOL isPayComplete, BOOL success, NSError *error))callback;

/** 查询充值结果
@param tradeNo 订单流水号
@param callback 回调
*/
- (void)getRechargeResultWithTradeNo:(NSString *)tradeNo
                      completeHandle:(void(^)(BOOL success, NSError *error))callback;

/** 获取交易记录列表
@param offset 其实下标
@param limit 显示条数
@param callback 回调
*/
- (void)getTradeRecordWithOffset:(NSUInteger)offset
                           limit:(NSUInteger)limit
                  completeHandle:(void(^)(NSArray<CSBusTradeRecordModel *> *records, NSError *error))callback;

/** 获取充值记录列表
@param offset 其实下标
@param limit 显示条数
@param callback 回调
*/
- (void)getRechargeRecordWithOffset:(NSUInteger)offset
                              limit:(NSUInteger)limit
                     completeHandle:(void(^)(NSArray<CSBusRechargeRecordModel *> *records, NSError *error))callback;

/** 获取短信验证码
@param phoneNo 合作渠道APP的用户手机号码
@param smsType 短信验证码类型(1:注册、3:登录)
@param callback 回调
*/
- (void)getSMSCodeWithPhoneNo:(NSString *)phoneNo
                      smsType:(CSBusSMSType)smsType
               completeHandle:(void(^)(NSError *error))callback;
@end

