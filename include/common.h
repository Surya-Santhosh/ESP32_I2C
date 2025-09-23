//******************************* common ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
// 
// Summary : Typedefs are included.
// Note    : None
// 
//******************************************************************************
#ifndef COMMON_H
#define COMMON_H 

//**************************** Include Files ***********************************
#include <Arduino.h>
#include <Wire.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//**************************** Global Types ************************************
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef unsigned long uint32;
typedef char int8;
typedef signed short int16;

//************************* Global Constants ***********************************
#define WRITE                       ("Write")
#define READ                        ("Read")
#define STM32_ADDRESS               (0xc)
#define STM32_SDA                   (21)
#define STM32_SCL                   (22)
#define WRITE_CMD                   (0x01)
#define READ_CMD                    (0x02)
#define NUM_DATA_TO_WRITE           (2)
#define NUM_DATA_TO_READ            (1)
#define WRITE_ACK                   (0x01)
#define READ_ACK                    (0x02)
#define SIZE_WRITE_ACK              (1)
#define SIZE_READ_DATA              (2)
#define BAUD_RATE                   (115200)
#define BAUD_RATE                   (115200)
#define NEW_LINE                    ('\n')

//************************* Global Variables *********************************** 

//************************* Forward Declarations *******************************  

//************************ Inline Method Implementations *********************** 

#endif 

// COMMON_H 
// EOF