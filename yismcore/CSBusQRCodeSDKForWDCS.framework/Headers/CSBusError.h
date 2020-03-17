//
//  CSBusError.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/7.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CSBusCommonModel;

/** SDK错误码定义 */
typedef NS_ENUM(NSInteger, CSBusSDKError) {
    /** 未知错误 */
    CSBusSDKErrorUnknown                            = -1,
    /** 操作失败 */
    CSBusSDKErrorOperationFail                      = 1000,
    /** 数据已存在 */
    CSBusSDKErrorDataExist                          = 1001,
    /** 参数验证失败 */
    CSBusSDKErrorParamVerifyFail                    = 1002,
    /** 数据不存在 */
    CSBusSDKErrorDataNotExist                       = 1003,
    /** 用户未注册 */
    CSBusSDKErrorUserUnregistered                   = 1005,
    /** 无效令牌 */
    CSBusSDKErrorInvalidToken                       = 1007,
    /** 用户已冻结 */
    CSBusSDKErrorUserFreeze                         = 1008,
    /** 验证码错误 */
    CSBusSDKErrorSMSFail                            = 1010,
    /** 证件号已被其他用户使用 */
    CSBusSDKErrorIdNoInUse                          = 1022,
    /** 证件号码或姓名错误 */
    CSBusSDKErrorIdNoOrRealNameFail                 = 1023,
    /** 用户未开通乘车码 */
    CSBusSDKErrorNotOpenQRCode                      = 1024,
    /** 订单已存在 */
    CSBusSDKErrorOrderExist                         = 1025,
    /** 总余额不得超过5000元 */
    CSBusSDKErrorType                               = 1027,
    /** 订单不存在 */
    CSBusSDKErrorOrderNotExist                      = 1028,
    /** 订单金额不一致 */
    CSBusSDKErrorOrderAmountInconformity            = 1029,
    /** 订单已处理回调结果 */
    CSBusSDKErrorOrderHasProcessedCallbackResult    = 1030,
    /** 订单已关闭 */
    CSBusSDKErrorOrderClose                         = 1031,
    /** 签名验证失败 */
    CSBusSDKErrorSignVerifyFail                     = 1032,
    /** 余额不能低于最低乘车金额 */
    CSBusSDKErrorBelowMinimumAmount                 = 1044,
    /** 服务升级中 */
    CSBusSDKErrorServiceUpdateing                   = 1045,
    /** 不在充值有效时间内(银行卡充值支持时间为1:00-22:00) */
    CSBusSDKErrorNotBankCardRechargeServiceTime     = 1046,
    /** 用户已发起提现 */
    CSBusSDKErrorUserWithdraw                       = 1048,
    /** 用户编号已存在 */
    CSBusSDKErrorUnoExist                           = 1052,
    /** 没有API访问权限 */
    CSBusSDKErrorNoApiAccessPermissions             = 1060,
    /** 秘钥版本不存在 */
    CSBusSDKErrorSecretKeyVersionNotExist           = 1061,
    /** 证件已过期 */
    CSBusSDKErrorExpiredCredential                  = 1062,
    /** 用户信息不一致  */
    CSBusSDKErrorUserInfoInconformity               = 1063
};

@interface CSBusError : NSObject
+ (CSBusCommonModel *)errorParsing:(NSError *)error;
+ (NSError *)errorWithErrorCode:(NSNumber *)errorCode errorMessage:(NSString *)errorMessage;
@end

