//
//  CSBusLog.h
//  CSBusQRCodeSDKForWDCS
//
//  Created by Donney on 2020/1/7.
//  Copyright © 2020 lmspay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define CSBUS_FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define CSBUS_LOG(fmt, ...) \
do { \
    [CSBusLog devLog:CSBUS_FILENAME \
                line:__LINE__ \
              format:(fmt), ## __VA_ARGS__]; \
} while(0)

#define CSBUSLog(format, ...)           CSBUS_LOG(format, ##__VA_ARGS__)

@interface CSBusLog : NSObject
+ (void)devLog:(const char *)fileName line:(NSUInteger)line format:(NSString *)format, ... NS_FORMAT_FUNCTION(3,4);
@end

