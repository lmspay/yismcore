//
//  YiWhiteBox.h
//  yismcore
//
//  Created by saint on 2019/5/16.
//  Copyright © 2019年 yiim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YiSMCore.h"

@interface YiWhiteBox : NSObject

/**
 * 白盒密码初始化，用存放了白盒密码查找表的文件初始化白盒密码。
 * 即可用加密查找表初始化，也可用解密查找表初始化。
 * @param path 文件名
 */
- (instancetype) initWithFile:(NSString *) path;

/**
 * 白盒密码初始化，用存放了白盒密码查找表的文件初始化白盒密码。
 * 因为查找表被置乱了，所以需要转入用于置乱查找表的SBOX。
 * 即可用加密查找表初始化，也可用解密查找表初始化。
 * @param path 文件名
 * @param sbox 用于置乱白盒密码查找表的SBOX
 */
- (instancetype) initWithFile:(NSString *) path andSBox: (NSData *) sbox;

/**
 * 白盒密码加密，加密的结果只能用拥有解密查找表的白盒进行解密
 * @param paddingMode 填充模式，支持NO_PADDING及PKCS7_PADDING
 * @param input 输入数据
 * @return 输出计算结果
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) wbsms4Encrypt: (YiPaddingMode) paddingMode andInput: (NSData *) input;

/**
 * 白盒密码解密，只能用于解拥有加密查找表的白盒加密结果
 * @param paddingMode 填充模式，支持NO_PADDING及PKCS7_PADDING
 * @param input 输入数据
 * @return 输出计算结果
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) wbsms4Decrypt: (YiPaddingMode) paddingMode andInput: (NSData *) input;

/**
 * 获取配置
 * @param tag 配置的TAG
 * @return 配置
 * @throws YiCryptException
 */
- (NSString *) getConfig:(int) tag;

/**
 * 另类白盒加密，适用于将军令
 * @param input 待加密数据
 * @return base64后的加密结果
 * @throws YiCryptException
 */
- (NSString *) whiteBoxEncrypt: (NSData *) input;

/**
 * 另类白盒解密，适用于将军令
 * @param input 待解密base64数据
 * @return 解密后的数据
 * @throws UnsupportedEncodingException
 * @throws YiCryptException
 */
- (NSData *) whiteBoxDecrypt: (NSString *) input;

/**
 * 黑盒加密
 * @param input 待加密数据
 * @return base64后的加密结果
 * @throws YiCryptException
 */
- (NSString *) blackBoxEncrypt: (NSData *) input;

/**
 * 黑盒解密
 * @param input 待解密的base64数据
 * @return 解密结果
 * @throws YiCryptException
 */
- (NSData *) blackBoxDecrypt: (NSString *) input;

- (NSString *) safeSign:(YiSM2KeyPair *) privKey andInput:(NSString *) input andSalt: (NSData *) salt andSaltEncoded:(BOOL) saltEncoded;
- (NSString *) safeSignTourist: (NSString *) input;

- (BOOL) safeVerify:(YiSM2KeyPair *) pubKey andInput:(NSString *) input andSalt: (NSData *) salt andSaltEncoded:(BOOL) saltEncoded andSignData: (NSString *) signData;
- (BOOL) safeVerifyTourist: (NSString *) input andSignData: (NSString *) signData;

@end
