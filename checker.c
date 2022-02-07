/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <assert.h>
#include "checker.h"

#define PROD_ENV 0
#define TEST_ENV 1
#define SW_BUILD TEST_ENV

void printOnConsole(const char* inputMsg , int testResult , int testcaseNumber) {
    if(testResult != TEST_FAILED)
    {
        printf("Testcase no %d passed\n",testcaseNumber);
    }
    else
    {
        printf("Testcase no %d failed : %s out of range!\n",testcaseNumber,inputMsg);
    }
}

int isParameterOutOfRange(const BMSParameterInfo f_BMSParameterData[][MAX_ARRAY_CONTENT],int indexValue)
{
    if(indexValue >= MAX_ARRAY_LENGTH )
    {
        printOnConsole("Dummy",TEST_PASSED,testPassedCounter);
        return 1;
    }
    
    if((f_BMSParameterData[indexValue]->parameterValue < f_BMSParameterData[indexValue]->minValue) ||(f_BMSParameterData[indexValue]->parameterValue > f_BMSParameterData[indexValue]->maxValue)) 
    {
            printOnConsole((f_BMSParameterData[indexValue]->parameterMessage),TEST_FAILED,testPassedCounter);
            return 0;
    }
    
    return isParameterOutOfRange(BMSParameterData,indexValue+1);
}

void testbatteryIsOk(float * f_BMSData) {
    testPassedCounter+=1;
    //Update Data which is passed as input
    for (int i=0;i < MAX_ARRAY_LENGTH ;i++)
    {
        BMSParameterData[i]->parameterValue = f_BMSData[i];
    }
    
    isParameterOutOfRange(BMSParameterData, 0);
    
}

//ORIGINAL FUNCTION
/*int batteryIsOk(float temperature, float soc, float chargeRate) {
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
}*/

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

