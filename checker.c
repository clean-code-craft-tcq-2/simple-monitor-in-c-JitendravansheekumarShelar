#include <stdio.h>
#include <assert.h>
#include <checker.h>

void printOnConsole(char msg[]) {
    printf("%s out of range!\n",msg);
}

int isChargeRateOutOfRange(const struct data f_BatteryInformation)
{
    if(f_BatteryInformation.testChargeRate > 0.8)
    {
        printOnConsole("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int isSocOutOfRange(const struct data f_BatteryInformation)
{
     if(f_BatteryInformation.testSoc < 20 || f_BatteryInformation.testSoc > 80) 
     {
        printOnConsole("State of Charge out of range!\n");
        return 0;
    }
    return isChargeRateOutOfRange(f_BatteryInformation); //return could be either 0 or 1
}

int isTemperatureOutOfRange(const struct data f_BatteryInformation)
{
     if(f_BatteryInformation.testTemperature < 0 || f_BatteryInformation.testTemperature > 45) 
     {
        printOnConsole("Temperature out of range!\n");
        return 0;
    }
    return isSocOutOfRange(f_BatteryInformation); //return could be either 0 or 1
}

int testbatteryIsOk(float temperature, float soc, float chargeRate) {
 struct data l_BatteryInformation;
 l_BatteryInformation.testTemperature = temperature;
 l_BatteryInformation.testSoc = soc;
 l_BatteryInformation.testChargeRate = chargeRate;

 return isTemperatureOutOfRange(l_BatteryInformation); //return could be either 0 or 1 
}

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
  assert(testbatteryIsOk(25, 70, 0.7));
  assert(!testbatteryIsOk(50, 85, 0));
  assert(!testbatteryIsOk(25, 60, 0.9)); 
  #endif
}
