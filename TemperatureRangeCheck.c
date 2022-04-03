#include <stdio.h>
#include "checker.h"
#include "TemperatureRangeCheck.h"
#include "SOCRangeCheck.h"


int Temperature_RangeCheck(float * f_BMSData)
{
    /*#if (TEMPERATURE_WARNING_CHECK == 1)
    if(f_BMSData[TEMPERATURE] > TemperatureWarningMinLimit && f_BMSData[TEMPERATURE] < TemperatureMinLimit) 
    {
        printf("Warning : Drop in Temperature !\n");
        return 1; //Since it is warning
    }
    
    if (f_BMSData[TEMPERATURE] > TemperatureWarningMaxLimit && f_BMSData[TEMPERATURE] < TemperatureMaxLimit) 
    {
        printf("Warning : Rise in Temperature !\n");
        return 1; //Since it is warning
    }
    #endif*/
    
    if(f_BMSData[TEMPERATURE] < TemperatureMinLimit || f_BMSData[TEMPERATURE] > TemperatureMaxLimit)
    {
        
        printf("Error : Temperature out of range!\n");
        return 0;
    }

    return 1;

}

int isTemperatureOutOfRange(float * f_BMSData)
{
    return Temperature_RangeCheck(&f_BMSData[0]) ? isSOCOutOfRange(&f_BMSData[0]) : 0;
}
