#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

void scheduler_not_preemptive(struct task_list *headTask) {
    unsigned int clock = 0;
    task *task_eseguibile = &headTask->task;
    int eseguito = 0;

    while (headTask != NULL) {
        if (task_eseguibile->stato == 0) {//processo new
            if (clock >= task_eseguibile->arrival_time) {
                task_eseguibile->stato = 1; //processo ready
                stampa("C:\\Users\\Veronica\\Desktop\\output.txt",clock,task_eseguibile->id,task_eseguibile->stato);


            }
            eseguito = 0;

        } else if (task_eseguibile->stato == 1) {
            clock = esegui_not_preemptive(task_eseguibile, clock);
            eseguito = 1;

        } else if (task_eseguibile->stato == 3) {//processo blocked
            task_eseguibile->stato = 1;
            stampa("C:\\Users\\Veronica\\Desktop\\output.txt",clock,task_eseguibile->id,task_eseguibile->stato);
            eseguito = 0;

        }

        if (task_eseguibile->stato == 4)
            remove_firtTask(&headTask);

        if (eseguito == 0)
            clock++;

//devo trovare il prossimo
        headTask = hrnn(headTask,clock);
        task_eseguibile = &headTask->task;
    }
}

