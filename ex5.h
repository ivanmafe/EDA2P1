/* 
 * File:   ex5.h
 * Author: admin
 *
 * Created on 27 de abril de 2018, 9:40
 */

#ifndef EX5_H
#define	EX5_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define ERROR -1
    

    
typedef struct {
    
    int size;
    
    int *array; 
    int *top;
    int top_pos;
    
    
}stack;


int ask_size();

int crear_array(stack *Stack);

int pop(stack *Stack);

int push(stack *Stack, int element);

int is_full(stack *Stack);

int new_element();

void show_mat (stack stack);

#ifdef	__cplusplus
}
#endif

#endif	/* EX5_H */

