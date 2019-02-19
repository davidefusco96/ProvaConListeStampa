#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

int main() {

    task_list *headTask;
    headTask = malloc(sizeof(task_list));
    istruzione *istruzione=NULL;
    istruzione = malloc(sizeof(istruzione));
    istr_list *headList = NULL;
    task *task = NULL;
    task = malloc(1024*sizeof(task));

    char *file = "C:\\Users\\Veronica\\Desktop\\progetto\\SimulatorSchedulerSO-master\\file_input\\03_tasks.csv";

    headTask = leggi_file(file,headTask,headList,istruzione,task);

   /*
    unsigned int clock = 1000000;
    headTask = srt(headTask,clock);
    task_list *current = headTask;
    while (current != NULL) {
        printf("Processo %d burst: %d\n",current->task.id,current->task.burst);
        current = current->next;
    }
    */

    scheduler_not_preemptive(headTask);
    //scheduler_preemptive(headTask);
    return 0;
}
