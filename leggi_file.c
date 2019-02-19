#include "strutture.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "funzioni.h"

struct task_list *leggi_file(char *file, struct task_list *headTask,struct istr_list *headList, struct istruzione *istruzione, struct task *task ) {


    headTask->task.id = 0;
    headTask->task.arrival_time = 0;
    headTask->task.stato = 0;
    headTask->task.prossimaIstruzione = NULL;
    headTask->task.lista_istruzioni = NULL;
    headTask->next = NULL;
    int cont = 0;
    struct task_list *temp;

    FILE *fd;


/* apre il file */
    fd = fopen(file, "r");

    if (fd == NULL) {
        perror("Errore in apertura del file");
        exit(EXIT_FAILURE);
    }

    char tipo;

    while ((tipo = fgetc(fd)) != EOF) {

        if (tipo == 't') {
            headList = malloc(sizeof(istr_list));
            headList->next = NULL;
            headList->istruzione.length = 0;
            headList->istruzione.type_flag = 0;
            fgetc(fd);
            fscanf(fd, "%d", &task->id);
            fgetc(fd);
            fscanf(fd, "%d", &task->arrival_time);
            task->stato = 0;
            task->burst = 0;
            task->ratio = 0.0;


        }

        if (tipo == 'i') {
            fgetc(fd);
            fscanf(fd, "%d", &istruzione->type_flag);
            fgetc(fd);
            fscanf(fd, "%d", &istruzione->length);
            if (headList->istruzione.length == 0) {
                pushStartIstr(&headList, *istruzione);
                remove_lastIstr(headList);
                task->prossimaIstruzione = &headList->istruzione;
                task->lista_istruzioni = headList;
                if (cont == 0) {
                    pushStartTask(&headTask, *task);
                    remove_lastTask(headTask);
                    temp = headTask;
                    cont++;
                } else {
                    pushEndTask(headTask, *task);

                    headTask = headTask->next;
                }
            } else {
                pushEndIstr(headList, *istruzione);
            }
            if(istruzione->type_flag == 0)
                headTask->task.burst += istruzione->length;

        }
    }

    headTask = temp;
    fclose(fd);
    return headTask;

}
