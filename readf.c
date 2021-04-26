
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

// For use in Donchian algorithm
/* struct curr_data { */
/*     struct data_file curr_data_arr[20]; */
/*     long double min; */
/*     long double max; */
/* }; */
/* typedef struct curr_data curr_data; */

struct data_file_array {
    struct data_file fdata[5000];
};
typedef struct data_file_array data_file_array;

struct TEMP_dfile{
    char file[5000][200];
};
typedef struct TEMP_dfile TEMP_dfile;

struct dfile{
    char** file;
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

void TEMP_copy_ch_dfile(char arr[][200], struct TEMP_dfile* f){
    int i = 0;
    while(arr[i+1] != NULL){
        if (i > 5000) break;
        strcpy(f->file[i], arr[i]);
        ++i;
    }
}

TEMP_dfile TEMP_save_char_buffer(char** buffer){
    struct TEMP_dfile ret;
    char temp_file[5000][200];
    int i = 0;
    while (*buffer++ != NULL){
        if (i > 5000) break;
        strcpy(temp_file[i], *buffer);
        ++i;
        ++buffer;
    }
    TEMP_copy_ch_dfile(temp_file, &ret);
    return ret;
}

TEMP_dfile TEMP_readf_main(char* fname){
    char *buf;
    char**  temp;
    buf = read_file(fname);
    temp = str_split(buf, '\n');
    struct TEMP_dfile d = TEMP_save_char_buffer(temp);
    return d;
}

dfile save_char_buffer(char** buffer){
    struct dfile ret;
    ret.file = buffer;
    return ret;
}

static char** _strsplit( const char* s, const char* delim, size_t* nb ) {
    void* data;
    char* _s = ( char* )s;
    const char** ptrs;
    size_t
        ptrsSize,
        nbWords = 1,
        sLen = strlen( s ),
        delimLen = strlen( delim );

    while ( ( _s = strstr( _s, delim ) ) ) {
        _s += delimLen;
        ++nbWords;
    }
    ptrsSize = ( nbWords + 1 ) * sizeof( char* );
    ptrs =
        data = malloc( ptrsSize + sLen + 1 );
    if ( data ) {
        *ptrs =
            _s = strcpy( ( ( char* )data ) + ptrsSize, s );
        if ( nbWords > 1 ) {
            while ( ( _s = strstr( _s, delim ) ) ) {
                *_s = '\0';
                _s += delimLen;
                *++ptrs = _s;
            }
        }
        *++ptrs = NULL;
    }
    if ( nb ) {
        *nb = data ? nbWords : 0;
    }
    return data;
}
char** strsplit( const char* s, char delim ) {
    return _strsplit( s, &delim, NULL );
}

struct dfile to_dfile(char* fname){
    char* buf;
    char** temp;
    buf = read_file(fname);
    temp = str_split(buf, '\n');
    free(buf);
    struct dfile d;
    d.file = temp;
    free(temp);
    return d;
}

struct data_file str_to_data(char** s){
    struct data_file ret;
    char* end;
    ret.datetime = s[0];
    ret.open = strtold(s[1], &end);
    ret.high = strtold(s[2], &end);
    ret.low = strtold(s[3], &end);
    ret.close = strtold(s[4], &end);
    ret.volume = strtol(s[5], &end, 10);
    return ret;
}

void clear_data_file(struct data_file* d){
    d->datetime = "";
    d->open = 0;
    d->high = 0;
    d->low = 0;
    d->close = 0;
    d->volume = 0;
}

struct data_file_array create_data(struct dfile* d){
    struct data_file_array ret;
    struct data_file t;
    int i = 0;
    char** temp;
    while(*d->file != NULL){
        temp = strsplit(*d->file, ';');
        t = str_to_data(temp);
        ret.fdata[i] = t;
        clear_data_file(&t);

        i++;
        d->file++;
    }
    return ret;
}
