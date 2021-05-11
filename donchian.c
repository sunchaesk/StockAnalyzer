
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
    data_list dlist;
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
//     d_print_data(&d.data_curr);
}

void update_donchian(donchian* don){
    don->start++;
    don->end++;

    // for storing min and max vals when updating
    long double temp = -1;
    // find max;
    for (int i = don->start; i < don->end; i++){
        printf("%Lg||\n", don->dlist.val[i].close);
        if (temp == -1 || don->dlist.val[i].close > temp){
            temp = don->dlist.val[i].close;
        }
    }
    don->curr_max = temp;
    temp = -1;
printf("\n============================HELLO\n");
    for (int i = don->start; i < don->end; i++){
        printf("%Lg||\n", don->dlist.val[i].close);
        if (temp == -1 || don->dlist.val[i].close < temp){
            temp = don->dlist.val[i].close;
        }
    }
    don->curr_min = temp;
}

enum DECISION {BUY = 0, SELL = 1};
enum DECISION make_decision_donchian(){
    return BUY;
}

void stepper_donchian(){

}

//
portfolio donchian_main(data_list d, long double init_portfolio_cash){
    // donchian don = init_donchian(d);
    // don.dlist = d;
    portfolio p;
    data init = d.val[0];
    init_portfolio(&p, init.close, init.datetime, init_portfolio_cash);

    int i = 0;
    while ((unsigned long)i < d.len - DONCHIAN_RANGE) {
        // update_donchian(&don);
        // make_decision_donchian();
        // stepper_donchian();
    }
    print_summary_portfolio(&p, d.val[d.len - 1].datetime);
    return p;
}
