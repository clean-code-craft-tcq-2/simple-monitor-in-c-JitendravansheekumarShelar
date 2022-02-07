#include <stdio.h>
#include <assert.h>
#include "checker.h"

void printOnConsole(char inputMsg[] , int testResult , int testcaseNumber) {
    if(testResult != TEST_FAILED)
    {
        printf("Testcase no %d passed\n",testcaseNumber);
    }
    else
    {
        printf("Testcase no %d failed : %s out of range!\n",testcaseNumber,inputMsg);
    }
}

int isParameterOutOfRange(const BMSParameterInfo f_BMSParameterData[][2])
{
    for (int i=0;i < MAX_ARRAY_LENGTH;i++)
    {  
        if(f_BMSParameterData[i]->parameterValue < f_BMSParameterData[i]->minValue || f_BMSParameterData[i]->parameterValue > f_BMSParameterData[i]->maxValue) 
        {
            printOnConsole((f_BMSParameterData[i]->parameterMessage),TEST_FAILED,testPassedCounter);
            return 0;
        }
    }
    printOnConsole("Dummy",TEST_PASSED,testPassedCounter);
    return 1;
}

void testbatteryIsOk(float * f_BMSData) {
    int result = 0;
    testPassedCounter+=1;
    //Update Data which is passed as input
    for (int i=0;i < MAX_ARRAY_LENGTH ;i++)
    {
        BMSParameterData[i]->parameterValue = f_BMSData[i];
    }
    
    result = isParameterOutOfRange(BMSParameterData);
    
}

//ORIGINAL FUNCTION
int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  #if (SW_BUILD == TEST_ENV)
  float BMSData_A[] = {25,70,0.7};
  float BMSData_B[] = {50,85,0};
  float BMSData_C[] = {25,60,0.9};
  testbatteryIsOk(BMSData_A);
  testbatteryIsOk(BMSData_B);
  testbatteryIsOk(BMSData_C); 
  #endif
}
