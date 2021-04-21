
#include <stdio.h>

#include "readf.c"

void help(){
    printf("help");
    /* print_help(); */
}

void test_algo(){
    printf("test_algo\n");
    /* propagate_data(); */
    /* algo_main_loop(); */
}

int main(int argc, char* argv[]) {
    if (argc == 2){
        if (strcmp(argv[1], "help") == 0){
            help();
        } else if (strcmp(argv[1], "test-algo") == 0){
            test_algo();
        }
    } else {
        printf("No args: print help\n");
    }
}
