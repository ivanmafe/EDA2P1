#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "sort.h"

int hash_function(char* word) {
    return ERROR;
}

void init_table(HashTable* table) {
    table->list->start=NULL;
    table->size=0;
}

void clear_table(HashTable* table) {
    free(table);
}

int size(HashTable* table) {
    int size_table;
    size_table=table->size;
    if (size_table != 0)
        return(size_table);
    
    else 
    {
        return (ERROR);
    }
}

bool insert_word_info(HashTable* table, WordInfo wi) {
        char categoria;
    categoria=wi.pos;
    strcpy(table->list->start->data.word, wi.word);
    strcpy(table->list->start->data.definition,wi.definition);
    table->list->start->data.pos = categoria;
    if (table->list->start->data.word==wi.word && table->list->start->data.definition == wi.definition && table->list->start->data.pos == categoria )
    {
        return (TRUE);
    }
    else 
    {
        return FALSE;
    }
}

bool exists_word(HashTable* table, char* word) {
    return FALSE;
}

bool delete_word(HashTable* table, char* word) {
    return FALSE;
}

WordInfo* find_word(HashTable* table, char* word) {
    return NULL;
}

void print_sorted_word_info(HashTable* table) {
}
