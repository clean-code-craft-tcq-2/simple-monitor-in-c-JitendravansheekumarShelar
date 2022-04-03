#include <stdio.h>
#include "checker.h"
#include "ChargeRateRangeCheck.h"

int isChargeRateApproachingDischarge(float * f_BMSData)
{

    if(f_BMSData[CHARGE_RATE] > ChargeRateWarningMaxLimit && f_BMSData[CHARGE_RATE] < ChargeRateMaxLimit) 
    {
        printf("Warning : Approaching Discharge!\n");
        return 1; //Since it is warning
    }
    return 0;
}

int ChargeRate_WarningRangeCheck(float * f_BMSData)
{
    return isApproachingDischarge(&f_BMSData[0]);
}

int isChargeRateOutOfRange(float * f_BMSData)
{
    if(!ChargeRate_WarningRangeCheck(&f_BMSData[0]) && (f_BMSData[CHARGE_RATE] > ChargeRateMaxLimit))
    {
        printf("Error : Charge Rate out of range!\n");
        return 0;
    }
    
    return 1;

}

