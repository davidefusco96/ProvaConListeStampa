#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "strutture.h"
#include "funzioni.h"

void stampa(char *outputFile, unsigned int clock, int id, int status){

    char *stato;

    if(status == 0)
        stato = "new";
    if(status == 1)
        stato = "ready";
    if(status == 2)
        stato = "running";
    if(status == 3)
        stato = "blocked";
    if(status == 4)
        stato = "exit";




    FILE *f = fopen(outputFile, "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }


    fprintf(f, "Clock %d, id %d, stato %s\n", clock,id,stato);

    fclose(f);

}
