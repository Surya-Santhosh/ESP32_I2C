//*********************************** esp32 ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//******************************************************************************
// File    : esp32.cpp
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
static bool esp32Read(uint8 ucAt24c02Address);
static bool esp32Write(uint8 ucAt24c02Address, uint8 ucData);

//*******************************.esp32Test.************************************
// Purpose : Read and write data for STM32.
// Inputs  : None
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
bool esp32ReadWriteHandler()
{
    bool blResult = false;
    String ucChoice = "";
    uint8 ucAt24c02Address = 0;
    uint8 ucData = 0;
    
    if (Serial.available() > 0)
    {
        ucChoice = Serial.readStringUntil('\n');
        ucChoice.trim();

        if (ucChoice.startsWith("Write"))
        {
            if (EOF != sscanf(ucChoice.c_str(), "Write %x %x", 
                                            &ucAt24c02Address, &ucData))
            {
                if (true == esp32Write(ucAt24c02Address, ucData))
                {
                    blResult = true;
                }
            }
        } 
        else if (ucChoice.startsWith("Read"))
        {
            if (EOF != sscanf(ucChoice.c_str(), "Read %x", 
                                            &ucAt24c02Address))
            {
                if (true == esp32Read(ucAt24c02Address))
                {
                    blResult = true;
                }
            }
        }
        else
        {
            Serial.println("Invalid\n");
        }
    }

    return blResult;
}

//*******************************.esp32Write.***********************************
// Purpose : Write data to STM32.
// Inputs  : ucAt24c02Address - Memory Address in AT24C02 where the data will 
//           be stored.
//         : ucData - Data to store.
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
static bool esp32Write(uint8 ucAt24c02Address, uint8 ucData)
{
    bool blResult = false;
    uint8 ucWriteAck = 0;
    
    Wire.beginTransmission(SLAVE_ADDRESS);
    Wire.write(WRITE_CMD);
    Wire.write(ucAt24c02Address);
    Wire.write(ucData);

    if (0 == Wire.endTransmission())
    {
        Serial.print("Data send to STM32\n");

        delay(TWENTY_MS_DELAY);

        Wire.requestFrom(SLAVE_ADDRESS, SIZE_WRITE_ACK);

        if (Wire.available())
        {
            ucWriteAck = Wire.read();

            if (WRITE_ACK == ucWriteAck)
            {
                Serial.println("EEPROM Write Success\n");

                blResult = true;
            }
        }
    }

    return blResult;
}

//*******************************.esp32Read.************************************
// Purpose : Read data from STM32.
// Inputs  : ucAt24c02Address - Memory Address in AT24C02 where the data is 
//           read from.
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
static bool esp32Read(uint8 ucAt24c02Address)
{
    bool blResult = false;
    uint8 ucData = 0;
    uint8 ucReadeAck = 0;

    Wire.beginTransmission(SLAVE_ADDRESS);
    Wire.write(READ_CMD);
    Wire.write(ucAt24c02Address);

    if (0 == Wire.endTransmission())
    {
        Serial.println("Request send to STM32\n");

        delay(TWENTY_MS_DELAY);

        byte size = Wire.requestFrom(SLAVE_ADDRESS, SIZE_READ_DATA);

        if (Wire.available() == size)
        {
            ucReadeAck = Wire.read();
            ucData = Wire.read();

            if (READ_ACK == ucReadeAck)
            {
                Serial.println("Data : ");
                Serial.println(ucData);

                blResult = true;
            }
        }
    }

    return blResult;
}
    
//EOF
