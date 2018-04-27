/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ex5.h" 




int main(int argc, char**argv) {

    int ans= 1;
    stack Stack;
    
    crear_array(&Stack);
    
    while (ans != 0){
       
        printf("Push [1] / Pop [2] / Show Stack [3] / Exit [0] \n");
        printf("Que desea hacer:");
        scanf("%d", &ans);
        
        if (ans == 1)
            push( &Stack , new_element() );
        else if (ans == 2)
            pop (&Stack);
        else if (ans == 3)
            show_mat(Stack);
    }
    
    
    return 0;
}


int ask_size(){
    
    int size;
    printf("Tamaño del array? : ");
    scanf("%d", &size);
    
    return (size); 
    
}

int crear_array(stack *Stack){
    
    int size = ask_size();
    
    int *matrix;
    matrix = (int*) calloc (size, sizeof(int));
    
    Stack->size = size; 
    
    Stack->array = matrix;  
    Stack->top_pos = -1; 
    Stack->top = NULL;
    
    return(SUCCESS); 
}

int pop(stack *Stack){
    
    
    if (Stack->top_pos = -1){
        
        printf("esta vacio \n");
        return (ERROR);
    }
    
    else {   
        
        Stack->array [Stack->top_pos] = 0;  
        
        Stack->top_pos = Stack->top_pos - 1;
        
        Stack->top = Stack->array[Stack->top_pos];
        
        return (SUCCESS);
    }
    
}

int push(stack *Stack, int element){
        
        
    if (Stack->top_pos == Stack->size){
        printf("esta lleno \n");
        return (ERROR);
    }
    
    else if (Stack->top_pos == -1){
        
        Stack->top_pos = 0;
        Stack->array[Stack->top_pos] = element;
        Stack->top= Stack->array[Stack->top_pos];
        
        return (SUCCESS);
        
    }
    else {
        
        Stack->top_pos = Stack->top_pos + 1;
        Stack->array[Stack->top_pos] = element; 
        Stack->top = Stack->array[Stack->top_pos];    
        return (SUCCESS);
    }    
   
}

int is_full(stack *Stack){
    
    if (Stack->array[Stack->size - 1] != NULL)
        return (FALSE);
    
    else if (Stack->array[Stack->size - 1] == NULL)
        return (TRUE);
    
    else 
        return (ERROR);
    
}

int new_element(){
    
    int x;
    printf("New element? : ");
    scanf(" %d", &x);
    
    
    return (x);
}

void show_mat (stack stack){
    
    
    for (int i =0; i < stack.size; i++){
        printf(" Array %d  : %d  \n", i, stack.array[i]); 
        
    }
    
    
    
}