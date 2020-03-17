//
//  CSBusUsersModel.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/10.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSBusUsersModel : NSObject<NSCoding>
/** 用户ID */
@property (strong, nonatomic) NSNumber *_id;
/** 用户编号 */
@property (copy, nonatomic) NSString *uno;
/** 用户手机号 */
@property (copy, nonatomic) NSString *phoneno;
/** 用户余额 */
@property (strong, nonatomic) NSNumber *balance;
/** 预授权总金额 */
@property (strong, nonatomic) NSNumber *frozenamount;
/** 提现冻结总金额 */
@property (strong, nonatomic) NSNumber *transfersamount;
/** 赠送账户余额 */
@property (strong, nonatomic) NSNumber *givenbalance;
/** 单笔最高金额 */
@property (strong, nonatomic) NSNumber *limitamount;
/** 昵称 */
@property (copy, nonatomic) NSString *nickname;
/** 真实姓名 */
@property (copy, nonatomic) NSString *realname;
/** 头像 */
@property (copy, nonatomic) NSString *avatar;
/** 性别（0:女、1:男、2:未设置） */
@property (strong, nonatomic) NSNumber *gender;
/** 用户状态（1:正常、2:冻结 ） */
@property (strong, nonatomic) NSNumber *status;
/** 冻结备注 */
@property (copy, nonatomic) NSString *frozenremark;
/** 票制类型 */
@property (strong, nonatomic) NSNumber *maincardid;
/** 票制名称 */
@property (copy, nonatomic) NSString *maincardname;
/** 过期时间 */
@property (copy, nonatomic) NSString *afterat;
/** 白盒加密后的盐值 */
@property (copy, nonatomic) NSString *salt;
/** 白盒加密后的用户公钥 */
@property (copy, nonatomic) NSString *publickey;
/** 白盒加密后的用户私钥 */
@property (copy, nonatomic) NSString *privatekey;
/** 扩展字段 */
@property (copy, nonatomic) NSString *extra;
/** 用户令牌 */
@property (copy, nonatomic) NSString *authtoken;
/** 是否开通乘车码 */
@property (strong, nonatomic) NSNumber *isqrcode;
/** 虚拟账号 */
@property (copy, nonatomic) NSString *accountno;
/** 注册时间 */
@property (copy, nonatomic) NSString *creatat;
/** 登录版本 */
@property (copy, nonatomic) NSString *loginversion;
/** 最低乘车余额 */
@property (strong, nonatomic) NSNumber *limitbalance;
/** 是否是司机(0:否、1:是) */
@property (strong, nonatomic) NSNumber *isdriver;
/** 身份证号 */
@property (copy, nonatomic) NSString *idno;

+ (instancetype)objectForSWGObject:(id)SWGObject;
@end

