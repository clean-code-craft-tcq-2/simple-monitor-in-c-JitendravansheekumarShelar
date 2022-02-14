#include <stdio.h>
#include "checker.h"
#include "ChargeRateRangeCheck.h"

int ChargeRateWarningCheck(float * f_BMSData)
{
    if(f_BMSData[CHARGE_RATE] > ChargeRateWarningMaxLimit && f_BMSData[CHARGE_RATE] < ChargeRateMaxLimit) 
    {
        printf("Warning : Approaching Discharge!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int isChargeRateOutOfRange(float * f_BMSData)
{
    int warningCheckFlag = 1;
    
    #if (SOC_WARNING_CHECK == 1)
    warningCheckFlag = ChargeRateWarningCheck(&f_BMSData[0]);
    #endif
    
    if((f_BMSData[CHARGE_RATE] > ChargeRateMaxLimit) &&\
    (warningCheckFlag == 1))
    {
        printf("Error : Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}
