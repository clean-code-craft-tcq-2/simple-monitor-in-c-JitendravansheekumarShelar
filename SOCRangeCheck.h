//define parameters limits
#define SOCMinLimit 20
#define SOCMaxLimit 80
#define SOCWarningMinLimit 24
#define SOCWarningMaxLimit 76

extern int isSOCOutOfRange(float * f_BMSData);
static int SOC_RangeCheck(float * f_BMSData);
