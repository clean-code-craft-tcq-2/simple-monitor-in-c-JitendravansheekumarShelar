#include <stdio.h>
#include <assert.h>

int testFailedCount = 0;

struct data
{
    float testTemperature,testSoc,testChargeRate;
};

int isChargeRateOutOfRange(const struct data f_BatteryInformation)
{
    if(f_BatteryInformation.testChargeRate > 0.8)
    {
        printf("Charge Rate out of range!\n");
        testFailedCount+=1;
        return 0;
    }
    return 1;
}

int isSocOutOfRange(const struct data f_BatteryInformation)
{
     if(f_BatteryInformation.testSoc < 20 || f_BatteryInformation.testSoc > 80) 
     {
        printf("State of Charge out of range!\n");
        testFailedCount+=1;
        return 0;
    }
    return isChargeRateOutOfRange(f_BatteryInformation); //return could be either 0 or 1
}

int isTemperatureOutOfRange(const struct data f_BatteryInformation)
{
     if(f_BatteryInformation.testTemperature < 0 || f_BatteryInformation.testTemperature > 45) 
     {
        printf("Temperature out of range!\n");
        testFailedCount+=1;
        return 0;
    }
    return isSocOutOfRange(f_BatteryInformation); //return could be either 0 or 1
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 struct data l_BatteryInformation;
 l_BatteryInformation.testTemperature = temperature;
 l_BatteryInformation.testSoc = soc;
 l_BatteryInformation.testChargeRate = chargeRate;

  return isTemperatureOutOfRange(l_BatteryInformation); //return could be either 0 or 1
 
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(25, 60, 0.9));  
}
