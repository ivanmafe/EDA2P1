#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "file_utils.h"
#include "word_info.h"

int read_info_file(char* path, WordInfo info_list[]) {
    FILE* fd = fopen(path, "r");

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fd) != NULL) {
        
        char* ptr = line;
        
        char* word = strsep(&ptr, "\t");
        char* definition = strsep(&ptr, "\t");
        char pos = ptr[0];
        
        create_word_info(&info_list[count], word, definition, pos);
        count++;
    }
    fclose(fd);
    
    return count;
}

int read_query_file(char* path, char* query_list[]) {
    
    FILE* fd = fopen(path, "r");

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fd) != NULL) {
        
        char* word = (char*) malloc(sizeof(MAX_WORD_LENGTH));
        int result = sscanf(line, "%s\n", word);
        if (result != EOF && result == 1) {
            query_list[count] = word;
            count++;
        } else {
            free(word);
        }
    }
    fclose(fd);
    
    return count;
}
