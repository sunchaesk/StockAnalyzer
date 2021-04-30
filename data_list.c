// Planning:
// Node struct with data as dataw;
// Methods:
// 1. add node
// 2. maybe a functionality to loop through the node?

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char* datetime;
    long double open;
    long double high;
    long double low;
    long double close;
    long int volume;
} data;

data init_data(char* date, long double open, long double high, long double low, long double close, long int volume){
    data ret;
    ret.datetime = date;
    ret.open = open;
    ret.high = high;
    ret.low = low;
    ret.close = close;
    ret.volume = volume;
    return ret;
}

typedef struct node {
    data val;
    struct node * next;
} node_t;

// NOTE:
// - You should already have the head node malloc
// - Set the head->next = NULL & head->val : intialized
// will add a new node to the head of the list
// Eg Code:
    /* data t = init_data("2021-09-21", 123.3, 314.43, 34.14, 1.234, 1234); */
    /* printf("%s\n", t.datetime); */

    /* node_t * head = NULL; */
    /* head = (node_t *) malloc(sizeof(node_t)); */
    /* if (head == NULL) { */
    /*     return 1; */
    /* } */

    /* head->val = t; */
    /* head->next = NULL; */
    /* data t2 = init_data("2021-09-22", 12.34, 544,54, 5454.3, 988); */
    /* push_front(&head, t2); */
// Output:
// 2021-09-22
// 2021-09-21
void push_front(node_t ** head, data val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%s\n", current->val.datetime);
        current = current->next;
    }
}
