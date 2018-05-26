#include <stdio.h>
#include <string.h>

#include "word_info.h"

/* 
 * La funcion rellena el WordInfo dado con los datos recibidos.
 */
void create_word_info(WordInfo* wi, char* word, char* definition, char pos) {
    strncpy(wi->word, word, MAX_WORD_LENGTH);
    strncpy(wi->definition, definition, MAX_DEFINITION_LENGTH);
    wi->pos = pos;
}

/*
 * La funcion retorna la palabra (string) que corresponde al WordInfo dado.
 */
char* get_word(WordInfo* wi) {
    return wi->word;
}

/*
 * Dado un WordInfo, la funcion imprime sus datos por pantalla.
 */
void print_word_info(WordInfo wi) {
    printf("-> %s (%c): %s\n", wi.word, wi.pos, wi.definition);
}
