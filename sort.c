#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

/*
 * EDA II - Practice 1
 * Practice Group : P302
 *    - Daniel Sanchez (207554)
 *    - Joan Moya (206659)
 *    - Iván Martínez (206638)
 * Group ID : 33
 * 
 *
 */

/* 
La funcion sort es la que se encargará de que en caso de que en una letra de nuestro diccionario
contenga mas de una entrada, lo que hará esta función es ordenar las palabras en orden
alfabético. Para poder ordenar de manera alfabética las palabras hemos utilizado como base un algoritmo 
visto en un seminario de clase.
*/

void sort(char** toSort, int size) {


    if (size > 1) {

        int i = 0; //we start by the position 1 (makes no sense to start by 0)
        int j = 1; //previous element on the array
        char *aux;

        while (j < size) {
            int a = i;
            int b = j;
            while ((strcmp(toSort[a], toSort[b]) > 0) && (b < size)) {
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





