
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
int main() {
    data t = init_data("2021-09-21", 123.3, 314.43, 34.14, 1.234, 1234);
    printf("%s\n", t.datetime);

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = t;
    head->next = NULL;
    data t2 = init_data("2021-09-22", 12.34, 544,54, 5454.3, 988);
    push_front(&head, t2);

    printf("\n================\n");
    print_list(head);
}
