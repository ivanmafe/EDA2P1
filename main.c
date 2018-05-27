#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "file_utils.h"
#include "main.h"
/*

 * EDA II - Practice 1
 * Practice Group : P302
 *    - Daniel Sanchez (207554)
 *    - Joan Moya (206659)
 *    - Iván Martínez (206638)
 * Group ID : 33
 * 
 *
 */

int main(int argc, char *argv[]) {
    
    printf("Task 3. Load dictionary data\n\n");

    printf("Loading file info...\n");
    WordInfo info_list[MAX_LINES];
    int info_size = read_info_file(INFO_FILE_PATH, info_list);
    printf("File info loaded!\n");

    HashTable dict;
    init_table(&dict);
    
    int i;
    
    for(i=0; i<info_size; i++) {
        
        
        if (exists_word(&dict,info_list[i].word) == FALSE){
            insert_word_info(&dict, info_list[i]);
            print_word_info(info_list[i]);}
        else
            printf("XX \"%s\" already exists \n",info_list[i].word);
    }
    
    
    printf("Dictionary loaded!\n");

    printf("\nTask 4. Search from query list\n\n");  
    
    char* query_list[MAX_LINES];
    int query_size = read_query_file(QUERY_FILE_PATH, query_list);
  
    int j;
    for(j=0; j<query_size; j++) {
        //printf(" %s\n", query_list[j]);
        WordInfo* wi = find_word(&dict, query_list[j]);
        if (wi == NULL) {
            printf("XX %s (Not found!)\n", query_list[j]);
        } else {
            print_word_info(*wi);
        }
    }

    printf("\nTask 5. Print sorted dictionary data\n\n");
    print_sorted_word_info(&dict);

    printf("\nDone!\n");

    clear_table(&dict);
    return 0;
}
