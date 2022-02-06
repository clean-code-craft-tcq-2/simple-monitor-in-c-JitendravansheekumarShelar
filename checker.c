#include <stdio.h>
#include <assert.h>

int testFailedCount = 0;

struct data
{
    float testTemperature,testSoc,testChargeRate;
};

int isChargeRateOutOfRange(struct data dataElem1)
{
    if(dataElem1.testChargeRate > 0.8)
    {
        printf("Charge Rate out of range!\n");
        testFailedCount+=1;
        return 0;
    }
    return 1;
}

int isSocOutOfRange(struct data dataElem1)
{
     if(dataElem1.testSoc < 20 || dataElem1.testSoc > 80) 
     {
        printf("State of Charge out of range!\n");
        testFailedCount+=1;
        return 0;
    }
    return isChargeRateOutOfRange(dataElem1);
}

int isTemperatureOutOfRange(struct data dataElem1)
{
     if(dataElem1.testTemperature < 0 || dataElem1.testTemperature > 45) 
     {
        printf("Temperature out of range!\n");
        testFailedCount+=1;
        return 0;
    }
    return isSocOutOfRange(dataElem1);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 struct data dataElem;
 dataElem.testTemperature = temperature;
 dataElem.testSoc = soc;
 dataElem.testChargeRate = chargeRate;

 return isTemperatureOutOfRange(dataElem);
 
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(25, 72, 0.9));
  
  if (testFailedCount == 0)
      printf("All Test Passed\n");
  else
      printf("%d Test Failed\n",testFailedCount);
  
}
