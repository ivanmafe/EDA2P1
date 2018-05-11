#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "sort.h"

int hash_function(char* word) {
    return ERROR;
}

void init_table(HashTable* table) {
}

void clear_table(HashTable* table) {
}

int size(HashTable* table) {
    return ERROR;
}

bool insert_word_info(HashTable* table, WordInfo wi) {
    return FALSE;
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
