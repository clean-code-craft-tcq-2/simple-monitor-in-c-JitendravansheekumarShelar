//define parameters limits
#define SOCMinLimit 20
#define SOCMaxLimit 80
#define SOCWarningMinLimit 76
#define SOCWarningMaxLimit 24

extern int isSOCOutOfRange(float * f_BMSData);
static int SOCWarningCheck(float * f_BMSData);
