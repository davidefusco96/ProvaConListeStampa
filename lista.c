#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

void pushEndIstr(istr_list *headIstr, istruzione val) {
    istr_list * current = headIstr;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(istr_list));
    current->next->istruzione = val;
    current->next->next = NULL;
}

void pushEndTask(task_list *headTask, task val) {
    task_list *current = headTask;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(task_list));
    current->next->task = val;
    current->next->next = NULL;
}

void pushStartIstr(istr_list **headIstr, istruzione val) {
    istr_list *new_node;
    new_node = malloc(sizeof(istr_list));

    new_node->istruzione = val;
    new_node->next = *headIstr;
    *headIstr = new_node;
}

void pushStartTask(task_list **headTask, task val) {
    task_list *new_node;
    new_node = malloc(sizeof(task_list));

    new_node->task = val;
    new_node->next = *headTask;
    *headTask = new_node;
}

void remove_lastTask(task_list *headTask) {
    task retval;
    if (headTask->next == NULL) {
        retval = headTask->task;
        free(headTask);
    }
    task_list *current = headTask;
    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->task;
    free(current->next);
    current->next = NULL;
}

void remove_lastIstr(istr_list *headList) {
    istruzione retval;
    if (headList->next == NULL) {
        retval = headList->istruzione;
        free(headList);
    }
    istr_list *current = headList;
    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->istruzione;
    free(current->next);
    current->next = NULL;
}

void remove_firtTask(task_list ** headTask) {
    task retval;
    task_list* next_node = NULL;



    next_node = (*headTask)->next;
    retval = (*headTask)->task;
    free(*headTask);
    *headTask = next_node;

}

void remove_firtIstr(istr_list ** headList) {
    istruzione retval;
    istr_list* next_node = NULL;
    next_node = (*headList)->next;
    retval = (*headList)->istruzione;
    free(*headList);
    *headList = next_node;
    }

void remove_by_list(task_list ** headTask, task task) {
    struct task retval;
    task_list *current = *headTask;
    task_list * temp_node = NULL;

    if (current->next == NULL) {
         remove_firtTask(headTask);
        return;
    }

    for (current;current != NULL; current = current->next) {
         if(current->next->task.id == task.id)
             break;
    }

    temp_node = current->next;
    retval = temp_node->task;
    current->next = temp_node->next;
    free(temp_node);
}