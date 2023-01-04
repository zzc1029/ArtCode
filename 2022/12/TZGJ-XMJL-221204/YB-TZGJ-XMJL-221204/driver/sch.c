/*
 * sch.c
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#include "system_init.h"


sTask SCH_tasks_G[SCH_MAX_TASKS];


uint8_t sch_add_task(void (* pFunction)(), const uint16_t DELAY, const uint16_t PERIOD)
{
	uint8_t Index = 0;

   // First find a gap in the array (if there is one)
   while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
   {
      Index++;
   }

   // If we're here, there is a space in the task array
   SCH_tasks_G[Index].pTask  = pFunction;

   SCH_tasks_G[Index].Delay  = DELAY;
   SCH_tasks_G[Index].Period = PERIOD;

   SCH_tasks_G[Index].RunMe  = 0;

   return Index; // return position of task (to allow later deletion)
}


uint8_t sch_delete_task(const uint8_t TASK_INDEX)//SCH_Delete_Task(const u8 TASK_INDEX)
{
   uint8_t Return_code = 0;

   if (SCH_tasks_G[TASK_INDEX].pTask == 0)
      {
      // No task at this location...
      //
      // Set the global error variable
     // Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;

      // ...also return an error code
    //  Return_code = RETURN_ERROR;
      }
   else
      {
    //  Return_code = RETURN_NORMAL;
      }

   SCH_tasks_G[TASK_INDEX].pTask   = 0x0000;
   SCH_tasks_G[TASK_INDEX].Delay   = 0;
   SCH_tasks_G[TASK_INDEX].Period  = 0;

   SCH_tasks_G[TASK_INDEX].RunMe   = 0;

   return Return_code;       // return status
}

void sch_dispatch_tasks(void)//SCH_Dispatch_Tasks(void)
{
	uint8_t Index;

   // Dispatches (runs) the next task (if one is ready)
   for (Index = 0; Index < SCH_MAX_TASKS; Index++)
   {
		if (SCH_tasks_G[Index].RunMe > 0)
		{
			(*SCH_tasks_G[Index].pTask)();  // Run the task

			SCH_tasks_G[Index].RunMe -= 1;   // Reset / reduce RunMe flag

			// Periodic tasks will automatically run again
			// - if this is a 'one shot' task, remove it from the array
			if (SCH_tasks_G[Index].Period == 0)
			{
				(void)sch_delete_task(Index);
			}
		}
    }

}

void sch_update(void)
{
	uint8_t Index;

	// NOTE: calculations are in *TICKS* (not milliseconds)
	for(Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
		// Check if there is a task at this location
		if (SCH_tasks_G[Index].pTask)
		{
			if (SCH_tasks_G[Index].Delay == 0)
			{
				// The task is due to run
				SCH_tasks_G[Index].RunMe += 1;  // Inc. the 'Run Me' flag

				if (SCH_tasks_G[Index].Period)
				{
				   // Schedule periodic tasks to run again
				   SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
			else
			{
			// Not yet ready to run: just decrement the delay
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
}

void sch_init(void)
{
   uint8_t i;

   for (i = 0; i < SCH_MAX_TASKS; i++)
   {
      (void)sch_delete_task(i);
   }
}
