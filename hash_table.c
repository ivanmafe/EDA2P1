#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "sort.h"

int hash_function(char* word) {
        int  pos;
    pos = word[0];
    pos = pos-97; 
    return (pos);
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
    
    Node *aux;
    aux = table->list->start;
    
    while (aux->next != NULL){
        
        if (strcmp(aux->data.word,word)==0)
            return (TRUE);
        
        else
            aux = aux->next;
      
    }
    
    return FALSE;
}

bool delete_word(HashTable* table, char* word) {
    
    
    Node *aux; 
    
    if (exists_word(table, word)==FALSE){
        printf("This word does not exist \n");
        return(ERROR);
    }
    
    else { 
        
    while (aux->next != NULL){
        
        if (strcmp(aux->data.word,word)==0){
            aux->prev->next = aux->next;
            aux->next->next = aux->prev;
            strcpy(aux->data.definition,"\0");
            strcpy(aux->data.word, "\0");
            aux->data.pos = '\0';
            return(SUCCESS);
            
        }
     
    }
    }
   
}

WordInfo* find_word(HashTable* table, char* word) {
    
    if (exists_word(table,word) == FALSE){
        printf("This word does not exist in the dictionary... \n");
        return NULL;
    }
    else if (exists_word(table,word) == TRUE){
        
        int pos = hash_function(word);
        LinkedList *aux = &(table->list[pos]);
        return(find_first_in_list(aux, word));
        
       
    }
  
}

void print_sorted_word_info(HashTable* table) {
    
   
    LinkedList *printer;
    
    for (int i = 0 ; i < table->size; i++){
        printer = &(table->list[i]); 
        print_list(printer); 

    }
} 
