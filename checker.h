//define parameters
#define TEMPERATURE 0
#define SOC 1
#define CHARGE_RATE 2

//define parameters limits
#define TemperatureMinLimit 0
#define TemperatureMaxLimit 45
#define SOCMinLimit 20
#define SOCMaxLimit 80
#define ChargeRateMaxLimit 0.8

//declarations
int isChargeRateOutOfRange(float * f_BMSData);
int isSOCOutOfRange(float * f_BMSData);
int isTemperatureOutOfRange(float * f_BMSData);
int testBatteryIsOk(float * f_BMSData);
