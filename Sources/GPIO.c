
#include "XMC4500.h"
#include "GPIO.h"

#define GPIO_CONFIGURED_PINS            11u


typedef PORT0_Type      GPIO_PortType; 

static GPIO_PortType * GPIO_Port[GPIO_PORTS_NUMBER] = { (GPIO_PortType*)PORT0, (GPIO_PortType*)PORT1, (GPIO_PortType*)PORT2, 
(GPIO_PortType*)PORT3, (GPIO_PortType*)PORT4, (GPIO_PortType*)PORT5, 
(GPIO_PortType*)PORT6, (GPIO_PortType*)PORT14, (GPIO_PortType*)PORT15 };

static const GPIO_PinConfigType GPIO_PinConfig[GPIO_CONFIGURED_PINS] = {\
  {GPIO_PORT1, PIN_0, OUT_PUSH_PULL_GPIO, GPIO_MEDIUM_PAD_DRIVER}, // LED
  {GPIO_PORT1, PIN_1, OUT_PUSH_PULL_ALT2, GPIO_MEDIUM_PAD_DRIVER}, //SCLK
  {GPIO_PORT1, PIN_3, OUT_PUSH_PULL_ALT2, GPIO_MEDIUM_PAD_DRIVER}, // MCLK
  {GPIO_PORT5, PIN_1, OUT_PUSH_PULL_ALT1, GPIO_MEDIUM_PAD_DRIVER}, //DOUT
  {GPIO_PORT1, PIN_11, OUT_PUSH_PULL_ALT2, GPIO_MEDIUM_PAD_DRIVER}, //CS
  {GPIO_PORT1, PIN_5, DIRECT_INPUT, GPIO_STRONG_PAD_DRIVER}, //DIN
  {GPIO_PORT0, PIN_2, OUT_PUSH_PULL_GPIO, GPIO_STRONG_PAD_DRIVER}, //LCD_RS
  {GPIO_PORT0, PIN_4, OUT_PUSH_PULL_GPIO, GPIO_STRONG_PAD_DRIVER}, //LCD_WR
  {GPIO_PORT0, PIN_6, OUT_PUSH_PULL_GPIO, GPIO_STRONG_PAD_DRIVER}, //LCD_RD
  {GPIO_PORT1, PIN_15, OUT_PUSH_PULL_GPIO, GPIO_STRONG_PAD_DRIVER}, //LCD_CS
  {GPIO_PORT1, PIN_13, OUT_PUSH_PULL_GPIO, GPIO_STRONG_PAD_DRIVER}, //LCD_REST
};


void GPIO_Init()
{
  uint32_t idx;
  /* enable clock for GPIO PORTS */
  
  for (idx = 0; idx < GPIO_CONFIGURED_PINS; idx++){
    GPIO_SetPortControlReg0(GPIO_PinConfig[idx].ui8Port, GPIO_PinConfig[idx].ui8Pin, GPIO_PinConfig[idx].ui8Function);
    GPIO_SetPadDriverMode0(GPIO_PinConfig[idx].ui8Port, GPIO_PinConfig[idx].ui8Pin, GPIO_PinConfig[idx].ui8PadDriverMode);
  }  
}

void GPIO_SetPortControlReg0(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  switch (ui8Pin){
    case 0u: 
    GPIO_Port[ui8Port]->IOCR0 &= ~(uint32_t)(0x0Fu << 3u);
    GPIO_Port[ui8Port]->IOCR0 |= (uint32_t)(ui8Mode << 3u); break;
    case 1u: 
    GPIO_Port[ui8Port]->IOCR0 &= ~(uint32_t)(0x0Fu << 11u);
    GPIO_Port[ui8Port]->IOCR0 |= (uint32_t)(ui8Mode << 11u); break;
    case 2u:
    GPIO_Port[ui8Port]->IOCR0 &= ~(uint32_t)(0x0Fu << 19u);
    GPIO_Port[ui8Port]->IOCR0 |= (uint32_t)(ui8Mode << 19u); break;
    case 3u:
    GPIO_Port[ui8Port]->IOCR0 &= ~(uint32_t)(0x0Fu << 27u);
    GPIO_Port[ui8Port]->IOCR0 |= (uint32_t)(ui8Mode << 27u); break;
  }
}


void GPIO_SetPortControlReg4(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  switch (ui8Pin){
    case 4u: 
    GPIO_Port[ui8Port]->IOCR4 &= ~(uint32_t)(0x0Fu << 3u);
    GPIO_Port[ui8Port]->IOCR4 |= (uint32_t)(ui8Mode << 3u); break;
    case 5u: 
    GPIO_Port[ui8Port]->IOCR4 &= ~(uint32_t)(0x0Fu << 11u);
    GPIO_Port[ui8Port]->IOCR4 |= (uint32_t)(ui8Mode << 11u); break;
    case 6u: 
    GPIO_Port[ui8Port]->IOCR4 &= ~(uint32_t)(0x0Fu << 19u);
    GPIO_Port[ui8Port]->IOCR4 |= (uint32_t)(ui8Mode << 19u); break;
    case 7u: 
    GPIO_Port[ui8Port]->IOCR4 &= ~(uint32_t)(0x0Fu << 27u);
    GPIO_Port[ui8Port]->IOCR4 |= (uint32_t)(ui8Mode << 27u); break;
  }
}

void GPIO_SetPortControlReg8(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  switch (ui8Pin){
    case 8u: 
    GPIO_Port[ui8Port]->IOCR8 &= ~(uint32_t)(0x0Fu << 3u);
    GPIO_Port[ui8Port]->IOCR8 |= (uint32_t)(ui8Mode << 3u); break;
    case 9u: 
    GPIO_Port[ui8Port]->IOCR8 &= ~(uint32_t)(0x0Fu << 11u);
    GPIO_Port[ui8Port]->IOCR8 |= (uint32_t)(ui8Mode << 11u); break;
    case 10u: 
    GPIO_Port[ui8Port]->IOCR8 &= ~(uint32_t)(0x0Fu << 19u);
    GPIO_Port[ui8Port]->IOCR8 |= (uint32_t)(ui8Mode << 19u); break;
    case 11u: 
    GPIO_Port[ui8Port]->IOCR8 &= ~(uint32_t)(0x0Fu << 27u);
    GPIO_Port[ui8Port]->IOCR8 |= (uint32_t)(ui8Mode << 27u); break;
  }
}


void GPIO_SetPortControlReg12(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  switch (ui8Pin){
    case 12u:
    GPIO_Port[ui8Port]->IOCR12 &= ~(uint32_t)(0x0Fu << 3u);
    GPIO_Port[ui8Port]->IOCR12 |= (uint32_t)(ui8Mode << 3u); break;
    case 13u: 
    GPIO_Port[ui8Port]->IOCR12 &= ~(uint32_t)(0x0Fu << 11u);
    GPIO_Port[ui8Port]->IOCR12 |= (uint32_t)(ui8Mode << 11u); break;
    case 14u:
    GPIO_Port[ui8Port]->IOCR12 &= ~(uint32_t)(0x0Fu << 19u);
    GPIO_Port[ui8Port]->IOCR12 |= (uint32_t)(ui8Mode << 19u); break;
    case 15u: 
    GPIO_Port[ui8Port]->IOCR12 &= ~(uint32_t)(0x0Fu << 27u);
    GPIO_Port[ui8Port]->IOCR12 |= (uint32_t)(ui8Mode << 27u); break;
  }
}

void GPIO_ResetPin(uint8_t ui8Port, uint8_t ui8Pin)
{
  GPIO_Port[ui8Port]->OUT &= ~(uint32_t)((uint32_t)0x01u << ui8Pin);
}

void GPIO_SetPin(uint8_t ui8Port, uint8_t ui8Pin)
{
  GPIO_Port[ui8Port]->OUT |= (uint32_t)((uint32_t)0x01 << ui8Pin);
}

void GPIO_TogglePin(uint8_t ui8Port, uint8_t ui8Pin)
{
  GPIO_Port[ui8Port]->OMR |= (uint32_t)(0x00010001 << ui8Pin);
}

uint8_t GPIO_ReadPin(uint8_t ui8Port, uint8_t ui8Pin)
{
  return (uint8_t)((GPIO_Port[ui8Port]->IN & (0x01 << ui8Pin)) >> ui8Pin);
}

void GPIO_EnablePin(uint8_t ui8Port, uint8_t ui8Pin)
{
  GPIO_Port[ui8Port]->PPS |= (uint32_t)0x01 << ui8Pin;
}

void GPIO_DisablePin(uint8_t ui8Port, uint8_t ui8Pin)
{
  GPIO_Port[ui8Port]->PPS &= ~((uint32_t)0x01 << ui8Pin);
}

void GPIO_SetPadDriverMode0(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  GPIO_Port[ui8Port]->PDR0 &= ~(uint32_t)((uint32_t)0x07u << (ui8Pin * 4u));
  GPIO_Port[ui8Port]->PDR0 |= (uint32_t)((uint32_t)ui8Mode << (ui8Pin * 4u));
}

void GPIO_SetPadDriverMode1(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  GPIO_Port[ui8Port]->PDR1 &= ~(uint32_t)((uint32_t)0x07u << ((ui8Pin - 8u) * 4u));
  GPIO_Port[ui8Port]->PDR1 |= (uint32_t)((uint32_t)ui8Mode << ((ui8Pin - 8u) * 4u));
}

void GPIO_SetHardwareSelectReg(uint8_t ui8Port, uint8_t ui8Pin, uint8_t ui8Mode)
{
  GPIO_Port[ui8Port]->HWSEL &= ~(uint32_t)((uint32_t)0x03 << (ui8Pin * 2u));
  GPIO_Port[ui8Port]->HWSEL |= (uint32_t)((uint32_t)ui8Mode << (ui8Pin * 2u));
}



