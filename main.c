
#include <stdio.h>
#include <assert.h>
#include <string.h>

// #include "file_read.c"
// #include "portfolio.c"
#include "donchian.c"


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
    // The problem curr:
    // THe **contents is only like a single file
    // contents[0] returns the whole file instead of the first line
    // contents[1] return SEG FAULT
    /* char *file = read_file("data/aapl.txt"); */
    /* char **contents = split_file_newline(file); */
    // printf("%s\n", contents[0]);
    data_list d = file_read_main("data/aapl.txt");
    printf("\n===%d\n", d.len);

    /* char * s = "Hellllo\nNOWNEWLINE\nAnothernewline"; */
    /* char ** ret = split_file_newline(s); */
    /* printf("%s", ret[3]); */
}
