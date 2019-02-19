#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

unsigned int esegui_not_preemptive(struct task *task, unsigned int clock){

    struct  task* eseguibile = task;

    while(1){
        eseguibile->stato = 2; // processo running
        stampa("C:\\Users\\Veronica\\Desktop\\output.txt",clock,eseguibile->id,eseguibile->stato);
        if(eseguibile->prossimaIstruzione == NULL) {
            eseguibile->stato = 4; //processo exit
            stampa("C:\\Users\\Veronica\\Desktop\\output.txt",clock,eseguibile->id,eseguibile->stato);
            break;
        }else {
            if (eseguibile->prossimaIstruzione->type_flag == 0) {
                eseguibile->burst -= eseguibile->prossimaIstruzione->length;
                clock += eseguibile->prossimaIstruzione->length;

                eseguibile->prossimaIstruzione = &eseguibile->lista_istruzioni->next->istruzione;
                remove_firtIstr(&eseguibile->lista_istruzioni);

            } else {
                eseguibile->stato = 3; //processo blocked
                stampa("C:\\Users\\Veronica\\Desktop\\output.txt",clock,eseguibile->id,eseguibile->stato);
                int low = 1;
                int upp = eseguibile->prossimaIstruzione->length;
                int randomBlock = (rand() % (upp - low + 1)) + low;
                eseguibile->arrival_time += randomBlock;
                eseguibile->prossimaIstruzione = &eseguibile->lista_istruzioni->next->istruzione;
                remove_firtIstr(&eseguibile->lista_istruzioni);
                break;
            }
        }
    }

    return (clock);
}

