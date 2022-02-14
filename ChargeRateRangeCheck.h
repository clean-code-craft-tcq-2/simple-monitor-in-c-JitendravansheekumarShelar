//define parameters limits
#define ChargeRateMaxLimit 0.8
#define ChargeRateWarningMaxLimit 0.076

//declarations
extern int isChargeRateOutOfRange(float * f_BMSData);
static int ChargeRateWarningCheck(float * f_BMSData);
