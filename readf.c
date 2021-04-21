
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LENGTH 270


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

typedef struct data_file {
    char* datetime;
    long double open;
    long double high;
    long double low;
    long double close;
    long int volume;
} data_file;

typedef struct curr_data {
    struct data_file curr_data_arr[20];
    long double min;
    long double max;
} curr_data;

/* struct curr_data propagate_data(){ */
/*     /\* struct curr_data ret; *\/ */
/*     /\* return ret; *\/ */
/* } */
    /* char* buf; */
    /* buf = read_file("data/aapl.txt"); */

    /* char** tokens; */
    /* tokens = str_split(buf, '\n'); */
    /* if (tokens){ */
    /*     int i = 0; */
    /*     for (i = 0; *(tokens+i); i++){ */
    /*         printf("%s\n", *(tokens+i)); */
    /*         free(*(tokens+i)); */
    /*     } */
    /*     printf("\n"); */
    /*     free(tokens); */
    /* } */
    /* return 0; */
