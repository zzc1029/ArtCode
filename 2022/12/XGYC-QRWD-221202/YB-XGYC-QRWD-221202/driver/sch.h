
/*
 * sch.h
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#ifndef _SCH_H_
#define _SCH_H_

#define SCH_MAX_TASKS   (15 + DISPLAYTASKNUM + 5)
#define COOP_TASK		1		//task is co-operative
#define PRE_TASK		0		//task is pre-emptive


typedef  struct
{
   // Pointer to the task (must be a 'void (void)' function)
   void (* pTask)(void);

   // Delay (ticks) until the function will (next) be run
   uint16_t Delay;

   // Interval (ticks) between subsequent runs.
   uint16_t Period;

   // Incremented (by scheduler) when task is due to execute
   uint8_t RunMe;

   } sTask;



extern void  sch_dispatch_tasks(void);
extern uint8_t sch_add_task(void (*) (void), const uint16_t, const uint16_t);
extern uint8_t   sch_delete_task(const uint8_t);
extern void  SCH_Report_Status(void);
extern void sch_init(void);
extern void sch_update(void);













#endif
