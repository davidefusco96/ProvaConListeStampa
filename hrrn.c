#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

struct task_list *hrnn(struct task_list *headTask, unsigned int clock) {

    int turn_round_time = 0;
    int waiting_time = 0;
    struct task_list *temp = headTask;
    float max_ratio = 0.0;

    for (temp; temp != NULL; temp = temp->next) {
        if (clock >= temp->task.arrival_time) {
            turn_round_time = clock - temp->task.arrival_time;
            waiting_time = turn_round_time + temp->task.burst;
            temp->task.ratio = (float) waiting_time / temp->task.burst;
            if(temp->task.ratio > max_ratio)
                max_ratio = temp->task.ratio;
        }
    }

    task_list *current = headTask;
    for (current; current != NULL; current = current->next){
        if (clock >= current->task.arrival_time) {
            if (current->task.ratio == max_ratio) {
                pushStartTask(&headTask, current->task);
                remove_by_list(&headTask, current->task);
                break;
            }
        }
    }


    return  headTask;
}

