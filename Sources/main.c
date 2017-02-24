
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

const OS_ScheduledTasksListType OS_scheduledTaskList[] = {
  {1, foo3, 0, 512, 10},
  {2, foo2, 0, 512, 10},
  {3, foo1, 0, 512, 10},
  {.pMainHandler = NULL_PTR}   /* must ALWAYS be the last entry */
};

int main(void)
{ 
  SystemInit();
  
  GPIO_Init();
  
  OS_Init();
  
  OS_StartScheduler();

  while (1);
  return 0;
}