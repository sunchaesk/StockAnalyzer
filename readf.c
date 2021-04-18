
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LENGTH 270

typedef struct stock_data {
    char datetime[40];
    double open;
    double high;
    double low;
    double close;
    long unsigned int volume;
} stock_data;

int num_lines(char fname[40]){
    int num_lines = 0;
    char c;
    FILE *fileptr = fopen(fname, "r");

    c = getc(fileptr);
    while (c != EOF){
        if (c == '\n') num_lines++;
        c = getc(fileptr);
    }
    fclose(fileptr);

    return num_lines;
}


/* struct data_file read_file(char fname[40]){ */
/*     FILE *f = fopen(fname, "r"); */
/*     struct data_file ret; */
/*     int n_lines = num_lines(fname); */
/*     for(int i = 0; i < n_lines; ++i){ */
/*         fgets(ret[i], LENGTH, f); */
/*     } */
/*     return ret; */
/* } */


char* read_file(char fname[40]){
    FILE *f = fopen(fname, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);

    string[fsize] = 0;
    return string;
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);
    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;
    result = malloc(sizeof(char*) * count);
    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);
        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}
