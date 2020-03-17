//
//  CSBusRechargeRecordModel.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/10.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSBusRechargeRecordModel : NSObject
/** 交易流水号 */
@property (copy, nonatomic) NSString *tradeno;
/** 用户编号 */
@property (copy, nonatomic) NSString *uno;
/** 交易渠道*/
@property (copy, nonatomic) NSString *paychannel;
/** 付款金额(单位:分) */
@property (strong, nonatomic) NSNumber *payamount;
/** 充值金额(单位:分) */
@property (strong, nonatomic) NSNumber *amount;
/** 交易后余额(单位:分) */
@property (strong, nonatomic) NSNumber *afterbalance;
/** 支付手续费(单位:分) */
@property (strong, nonatomic) NSNumber *payfee;
/** 状态(1:待付款、2:付款成功、3:已关闭) */
@property (strong, nonatomic) NSNumber *status;
/** 完成时间 */
@property (copy, nonatomic) NSString *completeat;
/** 付款时间 */
@property (copy, nonatomic) NSString *payat;
/** 下单时间 */
@property (copy, nonatomic) NSString *creatat;

+ (instancetype)objectForSWGObject:(id)SWGObject;
@end

