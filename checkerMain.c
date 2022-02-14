#include <stdio.h>
#include <assert.h>
#include "checker.h"
#include "TemperatureRangeCheck.h"


//TEST FUNCTION
int testBatteryIsOk(float * f_BMSData) 
{
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
