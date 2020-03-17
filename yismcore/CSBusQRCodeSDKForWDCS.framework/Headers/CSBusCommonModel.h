//
//  CSBusCommonModel.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/10.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSBusCommonModel : NSObject
/** 错误码 */
@property (strong, nonatomic) NSNumber *code;
/** 错误描述 */
@property (copy, nonatomic) NSString *message;

+ (instancetype)objectForSWGObject:(id)SWGObject;
@end

