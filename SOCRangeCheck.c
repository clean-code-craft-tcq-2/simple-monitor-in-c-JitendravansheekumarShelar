#include <stdio.h>
#include "checker.h"
#include "SOCRangeCheck.h"
#include "ChargeRateRangeCheck.h"

int SOC_RangeCheck(float * f_BMSData)
{
    /*#if (SOC_WARNING_CHECK == 1)
    if(f_BMSData[SOC] > SOCWarningMinLimit && f_BMSData[SOC] < SOCMinLimit) 
    {
        printf("Warning : Approaching Discharge!\n");
        return 1; //Since it is warning
    }
    
    if (f_BMSData[SOC] > SOCWarningMaxLimit && f_BMSData[SOC] < SOCMaxLimit) 
    {
        printf("Warning : Approaching charge-peak!\n");
        return 1; //Since it is warning
    }
    #endif*/

    if(f_BMSData[SOC] < SOCMinLimit || f_BMSData[SOC] > SOCMaxLimit)
    {
        printf("Error : SOC out of range!\n");
        return 0;
    }
    
    return 1;

}

int isSOCOutOfRange(float * f_BMSData)
{
    return SOC_RangeCheck(&f_BMSData[0]) ? isChargeRateOutOfRange(&f_BMSData[0]) : 1;
}
