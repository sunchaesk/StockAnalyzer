
#include <stdio.h>
#include <assert.h>

// #include "readf.c"
#include "file_read.c"
#include "portfolio.c"
#include "algo.c"


/*     if (argc == 2){ */
/*         if (strcmp(argv[1], "help") == 0){ */
/*             help(); */
/*         } else if (strcmp(argv[1], "test-algo") == 0){ */
/*             test_algo(); */
/*         } */
/*     } else { */
/*         printf("No args: print help\n"); */
/*     } */

/* void help(){ */
/*     printf("help"); */
/*     /\* print_help(); *\/ */
/* } */

/* void test_algo(){ */
/*     printf("test_algo\n"); */
/*     /\* propagate_data(); *\/ */
/*     /\* algo_main_loop(); *\/ */
/* } */

/* struct Node *temp, *t; */
/* temp = (struct Node*) malloc (sizeof(struct Node)); */
/* t = (struct Node*) malloc (sizeof(struct Node)); */
/* temp->data = d; */
/* temp->next = NULL; */
/* if (n == NULL){ */
/*     n = (struct Node*) malloc (sizeof(struct Node)); */
/*     n->data = d; */
/*     n->next = NULL; */
/*     return; */
/* } */
/* t = n; */
/* while(t->next != NULL){ */
/*     t = t->next; */
/* } */
/* n->next = t; */
/* n->next->data = d; */
/* t->next = NULL; */
/* void insert_front(data d){ */

/* } */

//datetime;open;high;low;close;volume
    /* char * file = read_file("data/aapl.txt"); */
    /* char ** contents = split_file(file); */
    /* while (*contents != NULL){ */
    /*     printf("%s\n", *contents); */
    /*     contents++; */
    /* } */
int main() {
    char * file = read_file("data/aapl.txt");
    char ** contents = split_file_newline(file);
    node_t t = propagate_data_list(contents);
}
