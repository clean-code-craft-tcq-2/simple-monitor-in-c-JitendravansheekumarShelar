#include <stdio.h>
#include "checker.h"
#include "SOCRangeCheck.h"
#include "ChargeRateRangeCheck.h"

int SOCWarningCheck(float * f_BMSData)
{
    if(f_BMSData[SOC] > SOCWarningMinLimit && f_BMSData[SOC] < SOCMinLimit) 
    {
        printf("Warning : Approaching Discharge!\n");
        return 0;
    }
    else if (f_BMSData[SOC] > SOCWarningMaxLimit && f_BMSData[SOC] < SOCMaxLimit) 
    {
        printf("Warning : Approaching charge-peak!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int isSOCOutOfRange(float * f_BMSData)
{
    int warningCheckFlag = 1;
    
    #if (CHARGE_RATE_WARNING_CHECK == 1)
    warningCheckFlag = SOCWarningCheck(&f_BMSData[0]);
    #endif
    
    if((f_BMSData[SOC] < SOCMinLimit || f_BMSData[SOC] > SOCMaxLimit) &&\
        (warningCheckFlag == 1))
    {
        printf("Error : SOC out of range!\n");
        return 0;
    }
    return isChargeRateOutOfRange(&f_BMSData[0]);
}
