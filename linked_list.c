#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "commons.h"
#include "linked_list.h"

void init_list(LinkedList* list) {
    
    
    Node* first;
    first = (Node*) calloc (1,sizeof(Node));
    
    list->start = first; 
    //list->last = list->start;
    
} //OK

void clear_list(LinkedList* list) {
    
    Node* pos; //we create a auxiliary node equal to the first of the list
    pos = list->start;
    
    
    while (pos->next != NULL){
        pos = pos->next; // we go to the last position of the list
    }
    
    while (pos->prev != NULL){
        
        strcpy(pos->data.definition,"\0"); //we delete the word info
        pos->data.pos = '\0';
        strcpy(pos->data.word,"\0");
       
        pos = pos->prev; //we now evaluate the previous element
        pos->next->prev = NULL; 
        free (pos->next); //we release the first node
        
        pos->next = NULL;  // we delete the connection with the element we wanted to delete
        
    }
    
    free(list->start);  //we release the space of the first node we created
    
} //OK

/*
 * This funtion must be summoned by the one that takes the word and definition
 * and sorts it in the hash table
 */
void insert_into_list(LinkedList* list, WordInfo wi) {
    
    Node *newnode;
    
    newnode = (Node*) calloc (1,sizeof(Node));
    
    newnode->data = wi;
    
    
    //strcpy(newnode->data.definition, wi.definition);
    //strcpy(newnode->data.word, wi.word);
    //newnode->data.pos = wi.pos;
 
    if (list->start == NULL){
        list->start = newnode; 
        newnode->prev = NULL; 
        newnode->next = NULL; 
    }
    else {  
    newnode->next = list->start;
    newnode->prev = NULL;
   
    list->start->prev = newnode;
    list->start = newnode;
    
    
    }
}

WordInfo* find_first_in_list(LinkedList* list, char* word) {
    
    Node* aux = list->start;
    
    while(aux!=NULL){
        if (strcmp(aux->data.word , word) == 0){
         return (&(aux->data));
        }
        aux = aux->next;
     
    }
  
    return NULL;

} //OK

int delete_from_list(LinkedList* list, char* word) {
    
    Node *node;
    node = list->start;
    
    while (node->next != NULL){
       
    if (strcmp (node->data.word,word) == 0 ){
        
        strcpy(node->data.definition,"\0");
        strcpy(node->data.word,"\0");
        node->data.pos = '\0';
        
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = NULL;
        node->prev = NULL;
        
        free (node);
        return (1);
    }
    else {
        node = node->next;
    }
   
}
        return ERROR;
    
}//OK


void print_list(LinkedList* list) {
    
    Node* aux;
    aux = list->start;
    
    
    
    printf("Words with : %c \n", aux->data.word[0] ); 
    
    while (aux != NULL){
        
        printf("\t%s  :  %s \n",aux->data.word,aux->data.definition);
        aux = aux->next;
       
    }
    
} //OK
