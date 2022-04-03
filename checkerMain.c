#include <stdio.h>
#include <assert.h>
#include "checker.h"
#include "TemperatureRangeCheck.h"


//TEST FUNCTION
int testBatteryIsOk(float * f_BMSData) 
{   
   return isTemperatureOutOfRange(&f_BMSData[0]);
}


int main() {
  #if (SW_BUILD == TEST_ENV)
  float BMSData_A[] = {25,70,0.7};
  float BMSData_B[] = {50,85,0};
  float BMSData_C[] = {25,60,0.9};
   
  assert(testBatteryIsOk(BMSData_A) == 1);
  assert(testBatteryIsOk(BMSData_B) == 0);
  assert(testBatteryIsOk(BMSData_C) == 0);
   
  #endif
}
