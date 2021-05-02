
// Planning
// 1. read file
// 2. separate them into 1 lines each
// 3. for each of step 2, convert them to data
// 4. maybe use double linked list?
// 5. propagate list ( step 4 ) with data

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data_list.c"

// step 1
// simply use printf("%s", c) to print contents of char*
char* read_file(char* fname){
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

// step 2
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
char** split_file_newline(char* file_contents){
    char ** ret;
    ret = strsplit(file_contents, '\n');
    return ret;
}

//step 3
// example string:
// 2021-03-25;119.54000;121.66000;119.00000;120.59000;98844681
void d_print_data(data d){
    printf("\n==StrToData Print Test==\n");
    printf("%s\n", d.datetime);
    printf("%Lg\n", d.open);
    printf("%Lg\n", d.high);
    printf("%Lg\n", d.low);
    printf("%Lg\n", d.close);
    printf("%ld\n", d.volume);
    printf("======\n");
}
data str_to_data(char* s){
    char ** str_temp = strsplit(s, ';');
    char * pEnd;
    data ret;
    ret.datetime = str_temp[0];
    ret.open = strtold(str_temp[1], &pEnd);
    ret.high = strtold(str_temp[2], &pEnd);
    ret.low = strtold(str_temp[3], &pEnd);
    ret.close = strtold(str_temp[4], &pEnd);
    ret.volume = strtol(str_temp[5], &pEnd, 10);
    /* printf("%s\n", str_temp[0]); */
    /* printf("%s\n", str_temp[1]); */
    /* printf("%s\n", str_temp[2]); */
    /* printf("%s\n", str_temp[3]); */
    /* printf("%s\n", str_temp[4]); */
    /* printf("%s\n", str_temp[5]); */
    return ret;
}

// step 4
/* char * file = read_file("data/aapl.txt"); */
/* char ** contents = split_file(file); */
/* while (*contents != NULL){ */
/*     printf("%s\n", *contents); */
/*     contents++; */
/* } */
// The input is the file_contents separated by newline
node_t propagate_data_list(char ** file_contents){
    node_t * head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (head == NULL) return *head;
    head->val = init_null_data();
    head->next = NULL;

    while(*file_contents != NULL){
        data temp = str_to_data(*file_contents);
        push_front(&head, temp);
        file_contents++;
    }
    return *head;
}
