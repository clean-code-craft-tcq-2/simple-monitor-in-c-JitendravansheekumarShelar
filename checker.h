#define TemperatureMinLimit 0
#define TemperatureMaxLimit 45
#define SOCMinLimit 20
#define SOCMaxLimit 80
#define ChargeRateMinLimit 0.0
#define ChargeRateMaxLimit 0.8

struct BMSdata
{
    float testTemperature,testSoc,testChargeRate;
};

void printOnConsole(char msg[]);
int testbatteryIsOk(float temperature, float soc, float chargeRate);
int isParameterOutOfRange(const struct data f_ParameterInformation);
