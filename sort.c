#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

void sort(char** toSort, int size) {

    /*
    if (size > 1) {
        
        int i = 1; //we start by the position 1 (makes no sense to start by 0)
        int j = 0; //previous element on the array
        char *aux;
        while (i < size) {
            int a = i;
            int b = j;
            while (strcmp(toSort[a], toSort[b]) < 0) {
                aux = toSort[i];
                strcpy(toSort[i], toSort[i + 1]);
                strcpy(toSort[i + 1], aux);
                a--;
                b--;
            }
            i++;
            j++;
        }
        
    }
     */

    if (size > 1) {
        int i = 0;
        int a = 1;
        char *aux;

        while (i < size) {

            a = 1;
            while (a < size) {
                if (strcmp(toSort[a - 1], toSort[a]) > 0) {
                    aux = toSort[a - 1];
                    toSort[a - 1] = toSort[a];
                    toSort[a] = aux;

                }
                a++;

            }

            i++;
        }
    }


}

