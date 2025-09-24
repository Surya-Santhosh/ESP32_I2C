//******************************** main ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.cpp
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

//EOF

