//define parameters limits
#define TemperatureMinLimit 0
#define TemperatureMaxLimit 45
#define TemperatureWarningMinLimit 2.25
#define TemperatureWarningMaxLimit 42.75

extern int isTemperatureOutOfRange(float * f_BMSData);
static int temperatureWarningCheck(float * f_BMSData);
