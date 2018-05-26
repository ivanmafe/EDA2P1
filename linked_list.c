#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "commons.h"
#include "linked_list.h"

/*
*La función init_list lo que hace es inicializar la lista que nosotros le pasemos como parámetro, es decir
*hacemos la reserva de memória de cada nodo utilizando la función calloc y definimos cual será el principio 
*de nuestra lista mediante un nodo que hemos creado.
*/
void init_list(LinkedList* list) {


    Node* first;
    first = (Node*) calloc(1, sizeof (Node));

    list->start = first;


} //OK
/*
*La función clear_list lo que hará es liberar toda nuestra lista de todos los datos que contenga.
*Para poder hacer esto lo que haremos es crear un nodo auxilir igual al primero de la lista a través del
*cual iremos recorriendo todos los apartados de nuestra lista poniendolos a NULL. Finalmente lo que haremos
*es un free del comienzo de nuestra lista
*/

void clear_list(LinkedList* list) {

    Node* pos; //Creamos un nodo auxiliar igual al primero de la lista
    pos = list->start;


    while (pos->next != NULL) {
        pos = pos->next; // Vamos a la última posición de la lista
    }

    while (pos->prev != NULL) {

        strcpy(pos->data.definition, "\0"); //Borramos la word info
        pos->data.pos = '\0';
        strcpy(pos->data.word, "\0");

        pos = pos->prev; //Evaluamos el elemento anterior 
        pos->next->prev = NULL;
        free(pos->next); //Liberamos el primer nodo

        pos->next = NULL; // Borramos la conexion con el elemento que queríamos borrar
    }

    free(list->start); // Liberamos el espacio del primer nodo que hemos creado
} //OK

/*
 * Esta funcion ha de ser llamada por una que coje la palabra con su definición
 * y la ordena en la hash table.
 * Lo que hacemos es crear un nuevo nodo en el cual nosotros meteremos toda la información que queramos 
 * guardar y lo introduciremos a nuestra lista.
 */
void insert_into_list(LinkedList* list, WordInfo wi) {

    Node *newnode;

    newnode = (Node*) calloc(1, sizeof (Node));

    newnode->data = wi;


    //strcpy(newnode->data.definition, wi.definition);
    //strcpy(newnode->data.word, wi.word);
    //newnode->data.pos = wi.pos;

    if (list->start == NULL) {
        list->start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    } else {
        newnode->next = list->start;
        newnode->prev = NULL;

        list->start->prev = newnode;
        list->start = newnode;


    }
}
/*
*La función find first in list lo que hace es que nosotros cuando le pasamos una palabra y una lista
*busca la palabra que le hemos pasado en la lista y en el caso de que la palabra que nosotros le hemos 
*pasado exista nos devuelve su WordInfo. En caso de que la palabra no exista nos devuelve NULL.
*/
WordInfo* find_first_in_list(LinkedList* list, char* word) {

    Node* aux = list->start;

    while (aux != NULL) {
        if (strcmp(aux->data.word, word) == 0) {
            return (&(aux->data));
        }
        aux = aux->next;

    }

    return NULL;

} //OK

/*
*La función delete_from_list lo que hace es borrar la palabra que nosotros le hayamos pasado como parametro de la
*lista que nosotros también le hayamos pasado por parametro. Para hacer esto, simplemente lo que hacemos es poner 
*todos los campos de nuestra palabra a NULL mediante strcpy. También liberamos a memória.
*/
int delete_from_list(LinkedList* list, char* word) {

    Node *node;
    node = list->start;

    while (node->next != NULL) {

        if (strcmp(node->data.word, word) == 0) {

            strcpy(node->data.definition, "\0");
            strcpy(node->data.word, "\0");
            node->data.pos = '\0';

            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->next = NULL;
            node->prev = NULL;

            free(node);
            return (1);
        } else {
            node = node->next;
        }

    }
    return ERROR;

}//OK
/*
*La función print_list lo que hace es imprimir la lista que nosotros le hayamos pasado como parámetro
*/
void print_list(LinkedList* list) {

    Node* aux;
    aux = list->start;



    printf("Words with : %c \n", aux->data.word[0]);

    while (aux != NULL) {

        printf("\t%s  :  %s \n", aux->data.word, aux->data.definition);
        aux = aux->next;

    }

} //OK
