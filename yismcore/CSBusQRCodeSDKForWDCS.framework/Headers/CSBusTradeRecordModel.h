//
//  CSBusTradeRecordModel.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/10.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSBusTradeRecordModel : NSObject
/** 用户编号 */
@property (copy, nonatomic) NSString *uno;
/** 支付金额(单位:分) */
@property (strong, nonatomic) NSNumber *price;
/** 乘车时间 */
@property (copy, nonatomic) NSString *getonat;
/** 扣款时间 */
@property (copy, nonatomic) NSString *completeat;
/** 订单号 */
@property (copy, nonatomic) NSString *tradeno;
/** 线路 */
@property (copy, nonatomic) NSString *linename;
/** 车牌号 */
@property (copy, nonatomic) NSString *buscode;
/** 票价(单位:分) */
@property (strong, nonatomic) NSNumber *oldprice;
/** 优惠金额(单位:分) */
@property (strong, nonatomic) NSNumber *couponvalue;

+ (instancetype)objectForSWGObject:(id)SWGObject;
@end

