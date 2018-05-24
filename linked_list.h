#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "word_info.h"

typedef struct _Node {
    WordInfo data;
    struct _Node* next;
    struct _Node* prev;
}Node;

typedef struct {
    
    Node* start;
    //Node* last;
    
}LinkedList;

void init_list(LinkedList* list);
void clear_list(LinkedList* list);

void insert_into_list(LinkedList* list, WordInfo wi);
WordInfo* find_first_in_list(LinkedList* list, char* word);
int delete_from_list(LinkedList* list, char* word);

void print_list(LinkedList* list);

#endif
