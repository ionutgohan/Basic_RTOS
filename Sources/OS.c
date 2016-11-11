
#include "OS.h"
#include "OS_Cfg.h"
#include "Port.h"
#include "Task.h"

void OS_Init(void)
{ 
  Port_Init();
  Task_Init();
  
  Task_Create(OS_IDLE_TASK, OS_IdleTask, 0, 512, OS_IDLE_TASK_PRIORITY);
}


void OS_TickHandler(void)
{
  if (OS_REQ_CONTEXT_SWITCH == Task_Schedule()) {
    OS_RequestContextSwitch();
  }
}

void OS_StartScheduler(void)
{
  Port_SetupInterrupts();
  Port_StartFirstTask();
}

void OS_IdleTask(void *params)
{
  while (1) {
    //Task_Delay(200);
  }
}

void ExecuteEndlessLoop(void)
{
  while (1);
}