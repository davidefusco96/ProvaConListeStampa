#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

struct task_list *srt(struct task_list *headTask, unsigned int clock){

    int min_burst = headTask->task.burst;
    struct task_list *temp = headTask;

    for (temp; temp != NULL; temp = temp->next) {
        if (clock >= temp->task.arrival_time) {
            if(temp->task.burst < min_burst)
                min_burst = temp->task.burst;
        }
    }

    task_list *current = headTask;
    for (current; current != NULL; current = current->next){
        if (clock >= current->task.arrival_time) {
            if (current->task.burst == min_burst) {
                pushStartTask(&headTask, current->task);
                remove_by_list(&headTask, current->task);
                break;
            }
        }
    }

return headTask;

}

