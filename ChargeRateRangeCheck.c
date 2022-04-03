#include <stdio.h>
#include "checker.h"
#include "ChargeRateRangeCheck.h"

int isChargeRateOutOfRange(float * f_BMSData)
{
    /*#if (CHARGE_RATE_WARNING_CHECK == 1)
    if(f_BMSData[CHARGE_RATE] > ChargeRateWarningMaxLimit && f_BMSData[CHARGE_RATE] < ChargeRateMaxLimit) 
    {
        printf("Warning : Approaching Discharge!\n");
        return 1; //Since it is warning
    }
    #endif*/

    if(f_BMSData[CHARGE_RATE] > ChargeRateMaxLimit)
    {
        printf("Error : Charge Rate out of range!\n");
        return 0;
    }
    
    return 1;

}

