/*
 * I2CHandler.c
 *
 *  Created on: 6 maj 2016
 *      Author: kirk
 */


#include <stdio.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>


#define I2C_FILE_NAME "/dev/i2c-1"


//static int set_i2c_register(int file,
//                            unsigned char addr,
//                            unsigned char reg,
//                            int32_t value) {
//  __s32 res;
//  res = i2c_smbus_write_word_data(file, reg, value);
//  if (res < 0) {
//    /* ERROR HANDLING: i2c transaction failed */
//  } else {
//    /* res contains the read word */
//       }
//  return 0;
//}
//
//
//static int get_i2c_register(int file,
//                            unsigned char addr,
//                            unsigned char reg,
//                            int32_t *val) {
//     __s32 res;
//     res = i2c_smbus_read_word_data(file, reg);
//     if (res < 0) {
//       /* ERROR HANDLING: i2c transaction failed */
//     } else {
//       /* res contains the read word */
//     }
//
//    *val = res;
//    printf("Get register %x: %d (%x)\n", reg, res, res);
//
//    return 0;
//}


