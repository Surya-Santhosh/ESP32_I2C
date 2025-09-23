//********************************* esp32 ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//******************************************************************************
// File    : esp32.c
// Summary : Read and write data for STM32.
// Note    : None
// Author  : Surya Santhosh
// Date    : 11/SEP/2024
//******************************************************************************

//************************ Include Files ***************************************
#include "esp32.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//**************************** Local Variables *********************************

//***************************** Local Functions ********************************
static bool esp32Read(uint8 ucAddress);
static bool esp32Write(uint8 unAddress, uint8 ucValue);

//*******************************.esp32Test.************************************
// Purpose : Read and write data for STM32.
// Inputs  : None
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool esp32Test()
{
    bool blResult = false;
    String ucChoice = "";
    uint8 unAddress = 0;
    uint8 unValue = 0;
    
    if (Serial.available() > 0)
    {
        ucChoice = Serial.readStringUntil(NEW_LINE);
        ucChoice.trim();

        if (ucChoice.startsWith(WRITE))
        {
            if (NUM_DATA_TO_WRITE == sscanf(ucChoice.c_str(), "Write %x %x", 
                                            &unAddress, &unValue))
            {
                if (true != esp32Write(unAddress, unValue))
                {
                    Serial.println("Error in esp32Write\n");
                }
            }
        } 
        else if (ucChoice.startsWith(READ))
        {
            if (NUM_DATA_TO_READ == sscanf(ucChoice.c_str(), "Read %x", 
                                            &unAddress))
            {
                if (true != esp32Read(unAddress))
                {
                    Serial.println("Error in esp32Read\n");
                }
            }
        }
        else
        {
            Serial.println("Invalid\n");
        }
    }

    return true;
}

//*******************************.esp32Write.***********************************
// Purpose : Write data to STM32.
// Inputs  : unAddress - EEPROM Address.
//         : unValue - Data to store.
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
static bool esp32Write(uint8 unAddress, uint8 ucValue)
{
    bool blResult = false;
    uint8 ucWriteAck = 0;
    
    Wire.beginTransmission(STM32_ADDRESS);
    Wire.write(WRITE_CMD);
    Wire.write(unAddress);
    Wire.write(ucValue);

    if (0 == Wire.endTransmission())
    {
        Serial.print("Data send to STM32\n");

        delay(20);

        // Wire.setTimeOut(500);

        Wire.requestFrom(STM32_ADDRESS, SIZE_WRITE_ACK);

        if (Wire.available())
        {
            ucWriteAck = Wire.read();

            if (WRITE_ACK == ucWriteAck)
            {
                Serial.println("EEPROM Write Success\n");
            }
            else
            {
                Serial.println("EEPROM Write Failed\n");
            }
        }

        blResult = true;
    }

    return blResult;
}

//*******************************.esp32Read.************************************
// Purpose : Read data from STM32.
// Inputs  : unAddress - EEPROM Address.
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
static bool esp32Read(uint8 ucAddress)
{
    bool blResult = false;
    uint16 ucValue = 0;
    uint8 ucReadeAck = 0;

    Wire.beginTransmission(STM32_ADDRESS);
    Wire.write(READ_CMD);
    Wire.write(ucAddress);
    Wire.write(ucValue);

    if (0 == Wire.endTransmission())
    {
        Serial.println("Request send to STM32\n");

        delay(20);
        // Wire.setTimeOut(100);

        byte size = Wire.requestFrom(STM32_ADDRESS, SIZE_READ_DATA);

        if (Wire.available() == size)
        {
            ucReadeAck = Wire.read();
            ucValue = Wire.read();

            if (READ_ACK == ucReadeAck)
            {
                Serial.println("Data : ");
                Serial.println(ucValue);
            }

            blResult = true;
        }
    }

    return blResult;
}
    
//EOF
