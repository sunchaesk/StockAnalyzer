
#include "file_read.c"
#include "portfolio.c"

#define DONCHIAN_RANGE 20

// 1. get the data
// 2. make a way to keep track of the range of data being analyzed
// 3. loop over the data and analyze data / make sell and by decision
// 4. use the portfolio struct
// 5. make a way to stop the program and step through each data

// the main loop of the donchian function should accept data_list

struct donchian {
    int start;
    int end;

    long double curr_min;
    long double curr_max;

    data data_curr;
};
typedef struct donchian donchian;

donchian init_donchian(data_list d){
    if (d.len < DONCHIAN_RANGE -1){
        fprintf(stderr, "Error: The data doesn't have enough data\n");
        exit(1);
    }
    donchian initial_donchian;
    initial_donchian.start = 0;
    initial_donchian.end = DONCHIAN_RANGE - 1;
    initial_donchian.curr_min = -1;
    initial_donchian.curr_max = -1;

    for (int i = initial_donchian.start; i < initial_donchian.end; i++){
        data curr_d = d.val[i];
        if (initial_donchian.curr_min == -1 || curr_d.close < initial_donchian.curr_min){
            initial_donchian.curr_min = curr_d.close;
        }
        if (initial_donchian.curr_max == -1 || curr_d.close > initial_donchian.curr_max){
            initial_donchian.curr_max = curr_d.close;
        }
    }
    initial_donchian.data_curr = d.val[DONCHIAN_RANGE];

    return initial_donchian;
}
void d_print_donchian(donchian d){
    printf("\n====Print Donchian=====\n");
    printf("start: %d\n", d.start);
    printf("end/curr: %d\n", d.end);
    printf("curr_min: %Lg\n", d.curr_min);
    printf("curr_max: %Lg\n", d.curr_max);
    d_print_data(&d.data_curr);
}


//
/* portfolio donchian_main(data_list d, long double init_portfolio){ */

/* } */
