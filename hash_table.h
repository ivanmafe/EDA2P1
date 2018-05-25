#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "commons.h"
#include "linked_list.h"

#define N 26          // number of slots in the hash table (number of letters)
#define INVALID_WORD -1

typedef struct {
    
    LinkedList list[N];
    int size;
    
} HashTable;

void init_table(HashTable* table);
void clear_table(HashTable* table);//Hacer free para liberar la memória dinámica
int size(HashTable* table);

bool insert_word_info(HashTable* table, WordInfo wi);
bool exists_word(HashTable* table, char* word);
bool delete_word(HashTable* table, char* word);

WordInfo* find_word(HashTable* table, char* word);

void print_sorted_word_info(HashTable* table);

#endif