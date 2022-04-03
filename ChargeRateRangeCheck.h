//define parameters limits
#define ChargeRateMaxLimit 0.8
#define ChargeRateWarningMaxLimit 0.76

//declarations
extern int isChargeRateOutOfRange(float * f_BMSData);
static int ChargeRate_RangeCheck(float * f_BMSData);
