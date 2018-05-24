#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "sort.h"

int hash_function(char* word) {

    int pos;
    pos = word[0];
    pos = pos - 97;
    return (pos);
}

void init_table(HashTable* table) {

    for (int i = 0; i < N; i++) {
        table->list[i].start = NULL;
    }

    table->size = 0;
}

void clear_table(HashTable* table) {
    free(table);
}

int size(HashTable* table) {
    int size_table;
    size_table = table->size;
    if (size_table != 0)
        return (size_table);

    else {
        return (ERROR);
    }
}

bool insert_word_info(HashTable* table, WordInfo wi) {

    int pos = hash_function(wi.word);

    if ((pos < 0 || pos > N)) {
        return FALSE;
    }
    else {

        insert_into_list(&table->list[pos], wi);
        return TRUE;

    }

}

bool exists_word(HashTable* table, char* word) {

    Node* aux;
    int pos = hash_function(word);
    LinkedList l = table->list[pos];

    WordInfo* wi = find_first_in_list(&l, word);

    if (wi != NULL)
        return TRUE;
    else
        return FALSE;
}

bool delete_word(HashTable* table, char* word) {


    Node *aux;

    if (exists_word(table, word) == FALSE) {
        printf("This word does not exist \n");
        return (ERROR);
    }
    else {

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

WordInfo* find_word(HashTable* table, char* word) {

    if (exists_word(table, word) == FALSE) {
        //printf("This word does not exist in the dictionary... \n");
        return NULL;
    } else {

        int pos = hash_function(word);
        //LinkedList *aux = &(table->list[pos]);
        return (find_first_in_list(&(table->list[pos]), word));
        
    }

}

void print_sorted_word_info(HashTable* table) {

    LinkedList *printer;
    int i;


    for (i = 0; i < N; i++) {
        if (table->list[i].start != NULL) {
            printer = &(table->list[i]);
            print_list(printer);
        }

    }
} 
