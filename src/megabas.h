#ifndef RELAY8_H_
#define RELAY8_H_

#include <stdint.h>

#define ADC_CH_NO	8
#define DAC_CH_NO	4
#define ADC_RAW_VAL_SIZE	2
#define DAC_MV_VAL_SIZE		2
#define VOLT_TO_MILIVOLT	1000
#define OPTO_CH_NO 8
#define GPIO_CH_NO 4
#define COUNTER_SIZE 4
#define DRY_CONTACT_COUNT	8
#define DRY_CONTACT_CONTOR_SIZE 4

#define RETRY_TIMES	10
#define CALIBRATION_KEY 0xaa
#define RESET_CALIBRATION_KEY	0x55 
#define WDT_RESET_SIGNATURE 	0xCA
#define WDT_MAX_OFF_INTERVAL_S 4147200 //48 days

#define OWB_SENS_CNT 16
#define OWB_TEMP_SIZE_B 2

enum
{
	I2C_TRIACS_VAL_ADD = 0,
	I2C_TRIACS_SET_ADD,
	I2C_TRIACS_CLR_ADD,
	I2C_DRY_CONTACT_VAL_ADD,

	I2C_U0_10_OUT_VAL1_ADD,
	SPARE9,
	I2C_U0_10_OUT_VAL2_ADD,
	SPARE10,
	I2C_U0_10_OUT_VAL3_ADD,
	SPARE11,
	I2C_U0_10_OUT_VAL4_ADD,
	SPARE12,
	I2C_U0_10_IN_VAL1_ADD,
	SPARE17,
	I2C_U0_10_IN_VAL2_ADD,
	SPARE18,
	I2C_U0_10_IN_VAL3_ADD,
	SPARE19,
	I2C_U0_10_IN_VAL4_ADD,
	SPARE20,
	I2C_U0_10_IN_VAL5_ADD,
	SPARE1,
	I2C_U0_10_IN_VAL6_ADD,
	SPARE2,
	I2C_U0_10_IN_VAL7_ADD,
	SPARE3,
	I2C_U0_10_IN_VAL8_ADD,
	SPARE4,
	I2C_R_1K_CH1,
	SP21,
	I2C_R_1K_CH2,
	SP22,
	I2C_R_1K_CH3,
	SP23,
	I2C_R_1K_CH4,
	SP24,
	I2C_R_1K_CH5,
	SP31,
	I2C_R_1K_CH6,
	SP32,
	I2C_R_1K_CH7,
	SP33,
	I2C_R_1K_CH8,
	SP34,
	I2C_R_10K_CH1,
	SP121,
	I2C_R_10K_CH2,
	SP122,
	I2C_R_10K_CH3,
	SP123,
	I2C_R_10K_CH4,
	SP124,
	I2C_R_10K_CH5,
	SP131,
	I2C_R_10K_CH6,
	SP132,
	I2C_R_10K_CH7,
	SP133,
	I2C_R_10K_CH8,
	SP134,
	I2C_MEM_CALIB_VALUE,
	I2C_MEM_CALIB_CHANNEL = I2C_MEM_CALIB_VALUE + 2, //0-10V out [1,4]; 0-10V in [5, 12]; R 1K in [13, 20]; R 10K in [21, 28]
	I2C_MEM_CALIB_KEY, //set calib point 0xaa; reset calibration on the channel 0x55
	I2C_MEM_CALIB_STATUS,
	I2C_MODBUS_SETINGS_ADD = 65,
	I2C_NBS1,
	I2C_MBS2,
	I2C_MBS3,
	I2C_MODBUS_ID_OFFSET_ADD,
	I2C_RTC_YEAR_ADD,
	I2C_RTC_MONTH_ADD,
	I2C_RTC_DAY_ADD,
	I2C_RTC_HOUR_ADD,
	I2C_RTC_MINUTE_ADD,
	I2C_RTC_SECOND_ADD,
	I2C_RTC_SET_YEAR_ADD,
	I2C_RTC_SET_MONTH_ADD,
	I2C_RTC_SET_DAY_ADD,
	I2C_RTC_SET_HOUR_ADD,
	I2C_RTC_SET_MINUTE_ADD,
	I2C_RTC_SET_SECOND_ADD,
	I2C_RTC_CMD_ADD,
	I2C_MEM_WDT_RESET_ADD,
	I2C_MEM_WDT_INTERVAL_SET_ADD,
	I2C_MEM_WDT_INTERVAL_GET_ADD = I2C_MEM_WDT_INTERVAL_SET_ADD + 2,
	I2C_MEM_WDT_INIT_INTERVAL_SET_ADD = I2C_MEM_WDT_INTERVAL_GET_ADD + 2,
	I2C_MEM_WDT_INIT_INTERVAL_GET_ADD = I2C_MEM_WDT_INIT_INTERVAL_SET_ADD + 2,
	I2C_MEM_WDT_RESET_COUNT_ADD = I2C_MEM_WDT_INIT_INTERVAL_GET_ADD + 2,
	I2C_MEM_WDT_CLEAR_RESET_COUNT_ADD = I2C_MEM_WDT_RESET_COUNT_ADD + 2,
	I2C_MEM_WDT_POWER_OFF_INTERVAL_SET_ADD,
	I2C_MEM_WDT_POWER_OFF_INTERVAL_GET_ADD = I2C_MEM_WDT_POWER_OFF_INTERVAL_SET_ADD
		+ 4,
	I2C_MEM_DRY_CONTACT_RISING_ENABLE = I2C_MEM_WDT_POWER_OFF_INTERVAL_GET_ADD
		+ 4,
	I2C_MEM_DRY_CONTACT_FALLING_ENABLE,
	I2C_MEM_DRY_CONTACT_CH_CONT_RESET,
	I2C_DIAG_TEMPERATURE_MEM_ADD = 0x72,
	I2C_DIAG_24V_MEM_ADD,
	I2C_DIAG_24V_MEM_ADD1,
	I2C_DIAG_5V_MEM_ADD,
	I2C_DIAG_5V_MEM_ADD1,
	I2C_CAN_REC_MPS_MEM_ADD,
	I2C_REVISION_HW_MAJOR_MEM_ADD = 0x78,
	I2C_REVISION_HW_MINOR_MEM_ADD,
	I2C_REVISION_MAJOR_MEM_ADD,
	I2C_REVISION_MINOR_MEM_ADD,
	I2C_BUILD_DAY_MEM_ADD,
	I2C_BUILD_MOTH_MEM_ADD,
	I2C_BUILD_YEAR_MEM_ADD,
	I2C_BOARD_TYPE_MEM_ADD,
	I2C_MEM_DRY_CONTACT_CONTORS,
	I2C_MEM_DRY_CONTACT_CONTROL_END = 1 + I2C_MEM_DRY_CONTACT_CONTORS
		+ DRY_CONTACT_COUNT * DRY_CONTACT_CONTOR_SIZE,
	I2C_MEM_1WB_DEV = I2C_MEM_DRY_CONTACT_CONTROL_END,
	I2C_MEM_1WB_TEMP_ALL,
	I2C_EXT_INT_OUT_ENABLE = I2C_MEM_1WB_TEMP_ALL + 2,
	I2C_EXT_INT_OUT_FLAGS = I2C_EXT_INT_OUT_ENABLE+ 2,
	I2C_BUTTON_STATE = I2C_EXT_INT_OUT_FLAGS + 2,

	I2C_MEM_CPU_RESET = 0xaa,
	I2C_MEM_HSI_LO,
	I2C_MEM_HSI_HI,
	I2C_MEM_1WB_START_SEARCH,
	I2C_MEM_1WB_T1,
	I2C_MEM_1WB_T16_END =I2C_MEM_1WB_T1 + OWB_SENS_CNT * OWB_TEMP_SIZE_B - 1,
	I2C_MEM_1WB_ROM_CODE_IDX = I2C_MEM_1WB_T1 + OWB_SENS_CNT * OWB_TEMP_SIZE_B,
	I2C_MEM_1WB_ROM_CODE,//rom code 64 bits
	I2C_MEM_1WB_ROM_CODE_END = I2C_MEM_1WB_ROM_CODE + 7,
	I2C_MEM_UIN_SEL,
	I2C_MEM_1K_SEL,
	I2C_MEM_10K_SEL,

	SLAVE_BUFF_SIZE = 255
};

enum CAL_CH_START_ID{
	CAL_0_10V_OUT_START_ID = 1,
	CAL_0_10V_OUT_STOP_ID = 4,
	CAL_0_10V_IN_START_ID,
	CAL_0_10V_IN_STOP_ID = 12,
	CAL_1K_IN_START_ID,
	CAL_1K_IN_STOP_ID = 20,
	CAL_10K_IN_START_ID,
	CAL_10K_IN_STOP_ID = 28

};


#define CHANNEL_NR_MIN		1
#define TRIAC_CH_NR_MAX		8

#define CONTACT_CH_NR_MAX		8
#define OD_CH_NR_MAX			4
#define DAC_CH_NR_MAX		4
#define ADC_CH_NR_MAX		8

#define OD_PWM_VAL_MAX	10000

#define ERROR	-1
#define OK		0
#define FAIL	-1
#define ARG_CNT_ERR -3
#define COMM_ERR -4

#define SLAVE_OWN_ADDRESS_BASE 0x48

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef enum
{
	OFF = 0,
	ON,
	STATE_COUNT
} OutStateEnumType;

typedef struct
{
 const char* name;
 const int namePos;
 int(*pFunc)(int, char**);
 const char* help;
 const char* usage1;
 const char* usage2;
 const char* example;
}CliCmdType;

typedef struct
	__attribute__((packed))
	{
		unsigned int mbBaud :24;
		unsigned int mbType :4;
		unsigned int mbParity :2;
		unsigned int mbStopB :2;
		unsigned int add:8;
	} ModbusSetingsType;
const CliCmdType* gCmdArray[];
#endif //RELAY8_H_
