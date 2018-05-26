#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "sort.h"

/*
 * La funcion recibe una palabra (string) y devuelve el indice de la
 * hash table, que deberia ser un entero entre 0 y 25 para considerar
 * un caracter vaido entre a y z, y que proviene del valor ASCII de 
 * la primera letra de la palabra menos 97.
 */
int hash_function(char* word) {

    int pos;
    pos = word[0];
    pos = pos - 97;
    if (pos >= 0 && pos < N)
        return (pos);
    else return (INVALID_WORD);
}

/*
 * La funcion recibe el diccionario e inicializa todas las listas a NULL,
 * y también establece el tamaño a 0.
 */
void init_table(HashTable* table) {

    for (int i = 0; i < N; i++) {
        table->list[i].start = NULL;
    }

    table->size = 0;
}

/*
 * La funcion recibe el diccionario y elimina todos los datos y libera
 * la memoria.
 */
void clear_table(HashTable* table) {

    for (int i = 0; i < N; i++) {
        if (table->list[i].start != NULL) {
            clear_list(&table->list[i]);
        }
    }
    table->size = 0;

}

/*
 * La funcion devuelve el tamaño de la tabla si es diferente de 0,
 * en caso contrario devuelve ERROR. Esto es porque cuando se llama
 * a esta funcion, el la tabla no deberia estar vacia.
 */
int size(HashTable* table) {
    int size_table;
    size_table = table->size;
    if (size_table > 0)
        return (size_table);

    else {
        return (ERROR);
    }
}

/*
 * La funcion busca el indice de la funcion hash y guarda el wordinfo
 * en la lista correspondiente, en caso de que la palabra sea valida.
 * Devuelve TRUE en caso de cumplirse que la palabra es valida, y FALSE
 * en caso contrario.
 */
bool insert_word_info(HashTable* table, WordInfo wi) {

    int pos = hash_function(wi.word);

    if (pos == INVALID_WORD) {
        return FALSE;
    } else {
        insert_into_list(&table->list[pos], wi);
        return TRUE;
    }

}

/*
 * La funcion comprueba si la palabra es valida y despues comprueba
 * si ya existe en el diccionario. Devvuelve TRUE si ya existe, 
 * y FALSE en caso de que no sea una palabra valida o que no exista.
 */
bool exists_word(HashTable* table, char* word) {

    Node* aux;
    int pos = hash_function(word);

    if (pos == INVALID_WORD)
        return FALSE;
    else {
        LinkedList l = table->list[pos];

        WordInfo* wi = find_first_in_list(&l, word);

        if (wi != NULL)
            return TRUE;
        else
            return FALSE;
    }
}

/*
 * La funcion busca en el diccionario el nodo de la palabra dada
 * y lo desenlaza, es decir, lo elimina,
 */
bool delete_word(HashTable* table, char* word) {

    Node *aux;

    if (exists_word(table, word) == FALSE) {
        printf("ERROR: Can't delete. Word %s does not exist. \n", word);
        return (ERROR);
    } else {

        while (aux->next != NULL) {

            if (strcmp(aux->data.word, word) == 0) {
                aux->prev->next = aux->next;
                aux->next->next = aux->prev;
                strcpy(aux->data.definition, "\0");
                strcpy(aux->data.word, "\0");
                aux->data.pos = '\0';
                return (SUCCESS);

            }

        }
    }

}

/* 
 * La funcion busca en el diccionario la palabra dada y devuelve
 * su WordInfo.
 */
WordInfo* find_word(HashTable* table, char* word) {

    if (exists_word(table, word) == FALSE) {
        return NULL;
    } else {

        int pos = hash_function(word);
        if (pos != INVALID_WORD)
            return (find_first_in_list(&(table->list[pos]), word));
        else return NULL;
        
    }
}

/* 
 * La funcion imprime las palabras del diccionario ordenadas alfabeticaente.
 */
void print_sorted_word_info(HashTable* table) {

    int x; // amount of words in each list

    Node *aux;

    for (int i = 0; i < N; i++) {

        if (table->list[i].start != NULL) {

            //calculamos el numero de palabras que hay
            x = 0;
            char** order;
            aux = table->list[i].start;
            while (aux != NULL) {
                x++;
                aux = aux->next;
            }

            order = (char**) calloc(x, sizeof (char*));

            int pos = 0;
            aux = table->list[i].start;
            while (aux != NULL) {
                order[pos] = get_word(&(aux->data));
                pos++;
                aux = aux->next;
            }

            sort(order, x);

            int val = 0;
            while (val < x) {
                WordInfo* wi = find_word(table, order[val]);
                printf("-> %s : %s\n", order[val], wi->definition);
                val++;
            }

        }

    }
}
