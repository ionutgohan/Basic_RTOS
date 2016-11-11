
#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO_PORTS_NUMBER       9u
#define GPIO_PORT0              0u
#define GPIO_PORT1              1u
#define GPIO_PORT2              2u
#define GPIO_PORT3              3u
#define GPIO_PORT4              4u
#define GPIO_PORT5              5u
#define GPIO_PORT6              6u
#define GPIO_PORT14             7u
#define GPIO_PORT15             8u

#define GPIO_WEAK_PAD_DRIVER    7u
#define GPIO_MEDIUM_PAD_DRIVER  4u
#define GPIO_STRONG_PAD_DRIVER  0u

#define GPIO_SOFTWARE_CONTROL   0u
#define GPIO_HW0_CONTROL        1u
#define GPIO_HW1_CONTROL        2u



typedef enum{
  DIRECT_INPUT = 0, /* No internal pull device active */
  DIRECT_INPUT_PULL_DOWN, /* Internal pull-down device active */
  DIRECT_INPUT_PULL_UP, /* Internal pull-up device active */
  DIRECT_INPUT_CONT_SAMPLE, /* No internal pull device active; Pn_OUTx continuously samples the input value */
  INVERTED_INPUT, /* Internal pull-down device active */
  INVERTED_INPUT_PULL_DOWN, /* Internal pull-down device active */
  INVERTED_INPUT_PULL_UP, /* Internal pull-up device active */
  INVERTED_INPUT_CONT_SAMPLE, /* No internal pull device active; Pn_OUTx continuously samples the input value */
  OUT_PUSH_PULL_GPIO = 16, /* General-purpose output */
  OUT_PUSH_PULL_ALT1, /* Alternate output function 1 */
  OUT_PUSH_PULL_ALT2, /* Alternate output function 2 */
  OUT_PUSH_PULL_ALT3, /* Alternate output function 3 */
  OUT_PUSH_PULL_ALT4, /* Alternate output function 4 */
  OUT_OPEN_DRAIN_GPIO = 24,/* General-purpose output */
  OUT_OPEN_DRAIN_ALT1,     /* Alternate output function 1 */
  OUT_OPEN_DRAIN_ALT2,     /* Alternate output function 2 */
  OUT_OPEN_DRAIN_ALT3,     /* Alternate output function 3 */
  OUT_OPEN_DRAIN_ALT4      /* Alternate output function 4 */
}GPIO_ControlRegType;

typedef enum{
  PIN_0 = 0,
  PIN_1,
  PIN_2,
  PIN_3,
  PIN_4,
  PIN_5,
  PIN_6,
  PIN_7,
  PIN_8,
  PIN_9,
  PIN_10,
  PIN_11,
  PIN_12,
  PIN_13,
  PIN_14,
  PIN_15
}GPIO_PinMapType;

typedef struct{
  uint8_t ui8Port;
  uint8_t ui8Pin;
  uint8_t ui8Function;
  uint8_t ui8PadDriverMode;
} GPIO_PinConfigType;

void GPIO_Init();
void GPIO_SetPortControlReg0(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);
void GPIO_SetPortControlReg4(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);
void GPIO_SetPortControlReg8(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);
void GPIO_SetPortControlReg12(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);
void GPIO_ResetPin(uint8_t ui8Port, uint8_t ui8Pin);
void GPIO_SetPin(uint8_t ui8Port, uint8_t ui8Pin);
void GPIO_TogglePin(uint8_t ui8Port, uint8_t ui8Pin);
uint8_t GPIO_ReadPin(uint8_t ui8Port, uint8_t ui8Pin);
void GPIO_EnablePin(uint8_t ui8Port, uint8_t ui8Pin);
void GPIO_DisablePin(uint8_t ui8Port, uint8_t ui8Pin);
void GPIO_SetPadDriverMode0(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);
void GPIO_SetPadDriverMode1(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);
void GPIO_SetHardwareSelectReg(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode);

#endif
