//******************************** main ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Read and write data for STM32.
// Note    : None
// Author  : Surya Santhosh
// Day     : 11/SEP/2025
//******************************************************************************

//**************************** Include Files ***********************************
#include "common.h"
#include "esp32.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//**************************** Local Variables *********************************

//***************************** Local Functions ********************************

//*****************************.mainFunction.***********************************
// Purpose : Read and write data for STM32.
// Inputs  : none
// Outputs : none
// Return  : 0
// Notes   : None
//******************************************************************************
void setup() 
{
  Wire.begin(STM32_SDA,STM32_SCL);
  Serial.begin(BAUD_RATE);

  Serial.println("Write <Address> <Data> / Read <Address> : ");
}

void loop() 
{
  if (true != esp32Test())
  {
    Serial.print("Error in uartTest");
  }
}

// void setup() 
// {
//   Wire.begin(STM32_SDA,STM32_SCL);
//   Serial.begin(115200);
//   Serial.println("Enter Write/Read:");

// }

// void loop() 
// {
//   uint8 ucFirstData = 0;
//   uint8 ucSecondData = 0;
//   String ucChoice = "";
//   uint8 unAddress = 0;
//   uint8 unValue = 0;

//   if (Serial.available() > 0)
//   {
//     ucChoice = Serial.readStringUntil('\n');
//     ucChoice.trim();

//     Serial.println(ucChoice);

//     if (ucChoice.startsWith(WRITE))
//     {
//       if (NUM_DATA_TO_WRITE == sscanf(ucChoice.c_str(), "Write %x %x", 
//                                       &unAddress, &unValue))
//       {
//         Wire.beginTransmission(STM32_ADDRESS);

//         Wire.write(WRITE_CMD);
//         Wire.write(unAddress);
//         Wire.write(unValue);

//         if (0 == Wire.endTransmission())
//         {
//           Serial.print("Write Success\n");

//           delay(20);

//           // Wire.setWireTimeout();

//           // Wire.setWireTimeout(1000,true);

//           Wire.requestFrom(STM32_ADDRESS, 2);

//           if (Wire.available())
//           {
//             ucFirstData = Wire.read();
//             ucSecondData = Wire.read();

//             Serial.println("FirstData : ");
//             Serial.println(ucFirstData);
//             Serial.println("SecondData : ");
//             Serial.println(ucSecondData);
//           }
//         }
//         else
//         {
//           Serial.print("Write Failed\n");
//         }
//       }
//     }
//     else
//     {
//       Serial.print("Invalid\n");
//     }
//   }
// }

// EOF

