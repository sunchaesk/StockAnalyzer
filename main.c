
#include <stdio.h>

#include "readf.c"


int main() {
    char* buf;
    buf = read_file("data/aapl.txt");

    char** tokens;
    tokens = str_split(buf, '\n');
    if (tokens){
        int i = 0;
        for (i = 0; *(tokens+i); i++){
            printf("%s\n", *(tokens+i));
            free(*(tokens+i));
        }
        printf("\n");
        free(tokens);
    }
    return 0;
}
