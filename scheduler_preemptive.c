#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

void scheduler_preemptive(struct task_list *headTask) {
    unsigned int clock = 0;
    task *task_eseguibile;


    while (headTask != NULL) {
        headTask = srt(headTask,clock);
        task_eseguibile = &headTask->task;
        if (task_eseguibile->stato == 0) {//processo new
            if (clock >= task_eseguibile->arrival_time) {
                task_eseguibile->stato = 1;//processo ready
                //stampa("C:\Users\Veronica\Desktop\output.txt",clock,task_eseguibile->id,task_eseguibile->stato);
            }
        } else if (task_eseguibile->stato == 1) {
             esegui_preemptive(task_eseguibile, clock);
        }
        else if (task_eseguibile->stato == 2) {//processo running
             esegui_preemptive(task_eseguibile, clock);
        }
        else if (task_eseguibile->stato == 3) {//processo blocked
            task_eseguibile->stato = 1;
           // stampa("C:\Users\Veronica\Desktop\output.txt",clock,task_eseguibile->id,task_eseguibile->stato);
        }

        if (task_eseguibile->stato == 4)
            remove_firtTask(&headTask);

        clock++;
    }
}

