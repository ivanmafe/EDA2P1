#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

void sort(char** toSort, int size){ 
    int i, j;
    char buffer[size ];
    
    for(i = 0; i < size; i++){
        j = i+1;
        printf("\nIteracion %d\n", i);

        while (j < size) {
            if (strcmp(toSort[i], toSort[j]) > 0) {
                printf("Swapping \"%s\" and \"%s\"\n", toSort[i], toSort[j]);
                strncpy(buffer, toSort[i], size);
                strncpy(toSort[i], toSort[j], size);
                strncpy(toSort[j], buffer, size);
            }
            j++;
        }
    }
}
