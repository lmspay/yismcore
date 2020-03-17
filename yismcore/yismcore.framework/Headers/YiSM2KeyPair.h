//
//  YiSM2KeyPair.h
//  yismcore
//
//  Created by saint on 2018/8/4.
//  Copyright © 2018年 yiim. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YiSM2KeyPair : NSObject

@property (nonatomic, readonly) NSData * privateKey;

@property (nonatomic, readonly) NSData * publicKey;

@property (nonatomic, readonly) NSData * compressedPublicKey;

- (instancetype) initWith:(NSData *) privKey andPublicKey:(NSData *) pubKey andCompressedKey:(NSData *) comKey;

@end
