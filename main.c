#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "file_utils.h"
#include "main.h"


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
        //print_word_info(info_list[i]);
        int sol = exists_word(&dict, info_list[i]);
        if(sol == FALSE){
            int res = insert_word_info(&dict, info_list[i]);
            if (res == ERROR){
                printf("ERROR: Palabra \"%s\" no introducida correctamente en el diccionario.\n", info_list[i]->word);
            }else printf("Introducida la palabra \"%s\" en el diccionario.\n", info_list[i]->word);
        }else{
            printf("La palabra \"%s\" ya está en el diccionario.\n", info_list[i]->word);
        }
    }
    printf("Dictionary loaded!\n");

    printf("\nTask 4. Search from query list\n\n");
    char* query_list[MAX_LINES];
    int query_size = read_query_file(QUERY_FILE_PATH, query_list);
    
    int j;
    for(j=0; j<query_size; j++) {
        //printf("%s\n", query_list[i]);
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

    return 0;
}
