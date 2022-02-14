#include <stdio.h>
#include "checker.h"
#include "TemperatureRangeCheck.h"
#include "SOCRangeCheck.h"

int temperatureWarningCheck(float * f_BMSData)
{
    if(f_BMSData[TEMPERATURE] > TemperatureWarningMinLimit && f_BMSData[TEMPERATURE] < TemperatureMinLimit) 
    {
        printf("Warning : Temperature out of range!\n");
        return 0;
    }
    else if (f_BMSData[TEMPERATURE] > TemperatureWarningMaxLimit && f_BMSData[TEMPERATURE] < TemperatureMaxLimit) 
    {
        printf("Warning : Temperature out of range!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int isTemperatureOutOfRange(float * f_BMSData)
{
    int warningCheckFlag = 1;
    
    #if (TEMPERATURE_WARNING_CHECK == 1)
    warningCheckFlag = temperatureWarningCheck(&f_BMSData[0]);
    #endif
    
    if((f_BMSData[TEMPERATURE] < TemperatureMinLimit || f_BMSData[TEMPERATURE] > TemperatureMaxLimit) &&\
        (warningCheckFlag == 1))
    {
        printf("Error : Temperature out of range!\n");
        return 0;
    }
    return isSOCOutOfRange(&f_BMSData[0]);
}
