
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LENGTH 270


struct data_file {
    char* datetime;
    long double open;
    long double high;
    long double low;
    long double close;
    long int volume;
};
typedef struct data_file data_file;

struct curr_data {
    struct data_file curr_data_arr[20];
    long double min;
    long double max;
};
typedef struct curr_data curr_data;

struct dfile{
    char file[5000][200];
};
typedef struct dfile dfile;
void print_dfile(struct dfile* d){
    printf("%s", d->file[0]);
}


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

void copy_ch_dfile(char arr[][200], struct dfile* f){
    int i = 0;
    while(arr[i] != NULL){
        strcpy(f->file[i], arr[i]);
        ++i;
    }
}

dfile save_char_buffer(char** buffer){
    struct dfile ret;
    char temp_file[5000][200];
    int i = 0;
    while (*buffer != NULL){
        strncpy(temp_file[i], *buffer, sizeof(char[200]));
        char* temp = temp_file[i];
        ++i;
    }
    copy_ch_dfile(temp_file, &ret);
    return ret;
}

dfile readf_main(char* fname){
    char *buf;
    char**  temp;
    buf = read_file(fname);
    temp = str_split(buf, '\n');
    struct dfile d = save_char_buffer(temp);
    return d;
}

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


