#define TemperatureMinLimit 0
#define TemperatureMaxLimit 45
#define SOCMinLimit 20
#define SOCMaxLimit 80
#define ChargeRateMinLimit 0.0
#define ChargeRateMaxLimit 0.8

#define TEST_FAILED 0
#define TEST_PASSED 1

#define MAX_ARRAY_CONTENT 4
#define MAX_ARRAY_LENGTH 3

typedef struct {
  float parameterValue;
  float minValue;
  float maxValue;
  char parameterMessage[20];
} BMSParameterInfo;

BMSParameterInfo BMSParameterData[][MAX_ARRAY_CONTENT] = {
    {0,TemperatureMinLimit,TemperatureMaxLimit,"Temperature"},
    {0,SOCMinLimit,SOCMaxLimit,"State of charge"},
    {0,ChargeRateMinLimit,ChargeRateMaxLimit,"Charge Rate"}
};

int testPassedCounter = 0;

void printOnConsole(const char* inputMsg , int testResult , int testcaseNumber);
int isParameterOutOfRange(const BMSParameterInfo f_BMSParameterData[][MAX_ARRAY_CONTENT],int indexValue);
void testbatteryIsOk(float * f_BMSData);
