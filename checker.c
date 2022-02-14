
#include <stdio.h>
#include <assert.h>
#include "checker.h"

#define PROD_ENV 0
#define TEST_ENV 1
#define SW_BUILD TEST_ENV


int isChargeRateOutOfRange(float * f_BMSData)
{
    if(f_BMSData[CHARGE_RATE] > ChargeRateMaxLimit) 
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int isSOCOutOfRange(float * f_BMSData)
{
    if(f_BMSData[SOC] < SOCMinLimit || f_BMSData[SOC] > SOCMaxLimit) 
    {
        printf("SOC out of range!\n");
        return 0;
    }
    return isChargeRateOutOfRange(&f_BMSData[0]);
}

int isTemperatureOutOfRange(float * f_BMSData)
{
    if(f_BMSData[TEMPERATURE] < TemperatureMinLimit || f_BMSData[TEMPERATURE] > TemperatureMaxLimit) 
    {
        printf("Temperature out of range!\n");
        return 0;
    }
    return isSOCOutOfRange(&f_BMSData[0]);
}

//TEST FUNCTION
int testBatteryIsOk(float * f_BMSData) {
   int testFlag = 0;
   
   testFlag = isTemperatureOutOfRange(&f_BMSData[0]);
   
   if (testFlag)
   {
       assert(testFlag == 1);
   }
   else
   {
       assert(testFlag == 0);
   }
   
   
}


int main() {
  #if (SW_BUILD == TEST_ENV)
  float BMSData_A[] = {25,70,0.7};
  float BMSData_B[] = {50,85,0};
  float BMSData_C[] = {25,60,0.9};
  testBatteryIsOk(BMSData_A);
  testBatteryIsOk(BMSData_B);
  testBatteryIsOk(BMSData_C); 
  #endif
}
