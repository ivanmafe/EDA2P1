/* 
 * file_utils.h
 *
 * EDA II - Practice 1
 * Practice Group : P302
 *    - Daniel Sanchez (207554)
 *    - Joan Moya (206659)
 *    - Iván Martínez (206638)
 * Group ID : 33
 * 
 */

#ifndef UTIL_H
#define UTIL_H

#include "word_info.h"

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int read_info_file(char* path, WordInfo info_list[]);
int read_query_file(char* path, char* query_list[]);

#endif
