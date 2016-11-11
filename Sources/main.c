
#include "stdlib.h"
#include "System_XMC4500.h"
#include "GPIO.h"
#include "OS.h"
#include "Task.h"
#include "XMC4500.h"

volatile int x1, x2, x3;

void foo1(void *params)
{
  uint32_t i;
  while (1) {
    i = 1000000u;
    while (i--);
    x1++;
    
    GPIO_TogglePin(1, 0);
    Task_Delay(500);
    
    
  }
}


void foo2(void *params)
{
  uint32_t i;
  while (1) {
    i = 1000000u;
    //while (i--);
    x2++;
    //GPIO_TogglePin(1, 0);
    Task_Delay(300);
  }
}

void foo3(void *params)
{
  uint32_t i;
  while (1) {
    i = 1000000u;
    //while (i--);
    x3++;
    Task_Delay(600);
  }
}

int main(void)
{ 
  SystemInit();
  
  GPIO_Init();
  
  OS_Init();
  
  Task_Create(1, foo1, 0, 512, 10);
  
  Task_Create(2, foo2, 0, 512, 10);
  
  Task_Create(3, foo3, 0, 512, 10);

  OS_StartScheduler();

  while (1);
  return 0;
}