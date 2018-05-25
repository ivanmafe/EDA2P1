#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

void sort(char** toSort, int size) {

    
    if (size > 1) {
        
        int i = 0; //we start by the position 1 (makes no sense to start by 0)
        int j = 1; //previous element on the array
        char *aux;
        
        while (j < size) {
            int a = i;
            int b = j;
            while ( (strcmp(toSort[a], toSort[b]) > 0) && (b < size)) {
                    aux = toSort[a];
                    toSort[a] = toSort[b];
                    toSort[b] = aux;

                a++;
                b++;
            }
            i++;
            j++;
        }
        
    }

}






