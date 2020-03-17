//
//  yismcore.h
//  yismcore
//
//  Created by saint on 2018/8/4.
//  Copyright © 2018年 yiim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YiSM2KeyPair.h"
#import "YiCryptException.h"

@class YiWhiteBox;

typedef NS_ENUM(NSUInteger, YiCryptMode) {
    ENCRYPT,
    DECRYPT
};

typedef NS_ENUM(NSUInteger, YiPaddingMode) {
    NO_PADDING,
    PKCS7_PADDING
};

@interface YiSMCore : NSObject

@property (assign) BOOL debugMode;

+ (instancetype) defaultCore;

- (BOOL) setupSDK:(YiWhiteBox *) whiteBox andLicense:(NSString *) license;

#pragma mark - common -
/**
 * 随机生成二进制数据
 * @param length 二进制长度
 * @return 生成结果
 */
- (NSData *) genRandomBytes: (NSUInteger) length;

/**
 * 将BCD码转换为字符串
 * @param bytes 二进制数据
 * @return 返回BCD转换结果
 */
- (NSString *) bcd2Str:(NSData *) bytes;

/**
 * 将BCD码转换为字符串
 * @param bytes 二进制数据
 * @param range 数据范围
 * @return 返回BCD转换结果
 */
- (NSString *) bcd2Str:(NSData *) bytes withRange:(NSRange) range;

/**
 * 将字符串转换为BCD码，前补0
 * @param asc 字符串
 * @return 转换结果
 */
- (NSData *) str2Bcd:(NSString *) asc;

/**
 * 将字符串转换为BCD码，前补0
 * @param asc 字符串
 * @param length 将要转换到BCD长度，如12345，要转换为0x012345，则长度为6
 * @return 转换结果
 */
- (NSData *) str2Bcd:(NSString *) asc andLength: (NSUInteger) length;

#pragma mark - sm3 -
/**
 * SM3密码杂凑算法，国家密码局于2010年12月发布
 * @param input 待计算数据
 * @return 输出256比特(32字节)的杂凑值
 * @throws YiCryptException 计算出错时抛出异常。
 */
- (NSData *) sm3Hash: (NSData *) input;

#pragma mark - sms4 -
/**
 * 国密SMS4 ECB算法
 * @param key 密钥
 * @param cryptMode 算法模式，ENCRYPT为加密，DECRYPT为解密
 * @param paddingMode 填充模式，支持NO_PADDING及PKCS7_PADDING
 * @param input 输入数据
 * @return 输出计算结果
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sms4CryptECB: (NSData *) key withCryptMode:(YiCryptMode) cryptMode andPaddingMode:(YiPaddingMode) paddingMode andInput:(NSData *) input;

/**
 * 国密SMS4 CBC算法
 * @param key 密钥
 * @param iv 向量
 * @param cryptMode 算法模式，ENCRYPT为加密，DECRYPT为解密
 * @param paddingMode 填充模式，支持NO_PADDING及PKCS7_PADDING
 * @param input 输入数据
 * @return 输出计算结果
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sms4CryptCBC: (NSData *) key withIV:(NSData *) iv andCryptMode:(YiCryptMode) cryptMode andPaddingMode:(YiPaddingMode) paddingMode andInput:(NSData *) input;

#pragma mark - sm2 -

/**
 * 国密SM2，生成密钥对
 * @return SM2密钥对
 * @throws YiCryptException 计算出错时抛出异常
 */
- (YiSM2KeyPair *) sm2GenerateKeyPair;

/**
 * 国密SM2，私钥生成公钥
 * @param privKey 私钥
 * @return SM2公钥x||y
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2GetPubKey:(NSData *) privKey;

/**
 * 国密SM2，私钥生成压缩公钥
 * @param privKey 私钥
 * @return SM2压缩公钥yTilde||x
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2GetCompressedPubKey:(NSData *) privKey;

/**
 * 国密SM2，公钥压缩
 * @param pubKey 私钥
 * @return SM2压缩公钥yTilde||x
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2CompressPubKey:(NSData *) pubKey;

/**
 * 国密SM2，公钥解压
 * @param compressedPubKey 压缩公钥
 * @return SM2公钥x||y
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2DecompressPubKey:(NSData *) compressedPubKey;

/**
 * 国密SM2，私钥签名
 * @param privKey 私钥
 * @param userId user id
 * @param input 输入数据
 * @return 签名结果r||s
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2Sign:(NSData *) privKey withUserId: (NSData *) userId andInput:(NSData *) input;

/**
 * 国密SM2，私钥签名，采用默认的userId：1234567812345678
 * @param privKey 私钥
 * @param input 输入数据
 * @return 签名结果r||s
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2Sign:(NSData *) privKey withInput:(NSData *) input;

/**
 * 国密SM2，公钥验签
 * @param pubKey 公钥
 * @param userId user id
 * @param input 输入数据
 * @param signData 待验签名r||s
 * @return 验签结果，true验签成功
 * @throws YiCryptException 计算出错时抛出异常
 */
- (BOOL) sm2Verify:(NSData *) pubKey withUserId:(NSData *) userId andInput:(NSData *) input andSignData:(NSData *) signData;

/**
 * 国密SM2，公钥验签，采用默认的userId：1234567812345678
 * @param pubKey 公钥
 * @param input 输入数据
 * @param signData 待验签名r||s
 * @return 验签结果，true验签成功
 * @throws YiCryptException 计算出错时抛出异常
 */
- (BOOL) sm2Verify:(NSData *) pubKey withInput:(NSData *) input andSignData:(NSData *) signData;

/**
 * 国密SM2，公钥验签
 * @param compressedPubKey 压缩公钥
 * @param userId user id
 * @param input 输入数据
 * @param signData 待验签名r||s
 * @return 验签结果，true验签成功
 * @throws YiCryptException 计算出错时抛出异常
 */
- (BOOL) sm2VerifyByCompressedKey:(NSData *) compressedPubKey withUserId:(NSData *) userId andInput:(NSData *) input andSignData:(NSData *) signData;

/**
 * 国密SM2，公钥验签，采用默认的userId：1234567812345678
 * @param compressedPubKey 压缩公钥
 * @param input 输入数据
 * @param signData 待验签名r||s
 * @return 验签结果，true验签成功
 * @throws YiCryptException 计算出错时抛出异常
 */
- (BOOL) sm2VerifyByCompressedKey:(NSData *) compressedPubKey withInput:(NSData *) input andSignData:(NSData *) signData;

/**
 * 国密SM2，公钥加密
 * @param pubKey 公钥x||y
 * @param input 输入数据
 * @return 输出C1||C2||C3，其中C1=PC||x1||y1，C2=密文，C3=sm3_hash
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2Encrypt:(NSData *) pubKey withInput:(NSData *) input;

/**
 * 国密SM2，公钥加密
 * @param compressedPubKey SM2压缩公钥yTilde||x
 * @param input 输入数据
 * @return 输出C1||C2||C3，其中C1=PC||x1||y1，C2=密文，C3=sm3_hash
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2EncryptByCompressedKey:(NSData *) compressedPubKey withInput:(NSData *) input;

/**
 * 国密SM2，私钥解密
 * @param privKey 私钥
 * @param input 输入数据C1||C2||C3，其中C1=PC||x1||y1，C2=密文，C3=sm3_hash
 * @return 解密结果
 * @throws YiCryptException 计算出错时抛出异常
 */
- (NSData *) sm2Decrypt:(NSData *) privKey withInput:(NSData *) input;
@end
