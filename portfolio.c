
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct portfolio {
    double curr_stock;
    double start_stock;

    int stock_cnt;

    char* start_date;

    long double current_portfolio;
    long double initial_portfolio;
} portfolio;

// Should get the first field for data from the data file
struct portfolio init_portfolio(double stock, char* date, long double portfolio){
    struct portfolio p = {};
    p.curr_stock = stock;
    p.start_stock = stock;

    p.start_date = date;

    p.current_portfolio = portfolio;
    p.initial_portfolio = portfolio;
    return p;
}

struct portfolio buy_as_much(struct portfolio* p, double stock_p){

    return *p;
}

struct portfolio update_portfolio(struct portfolio* p, double stock_p){

    return *p;
}

void print_summary(struct portfolio* p, char* date){
    printf("\n===============PORTFOLIO SUMMARY==============\n");
    printf("DATE-RANGE: %s -> %s\n", p->start_date, date);
    // print start data
    printf("====START-DATA====\n");
    printf("START-PRICE: %Lg\n", p->initial_portfolio);
    printf("START-STOCK-PRICE: %g\n", p->start_stock);
    // print final data and overview
    printf("====FINAL-DATA====\n");
    printf("FINAL-PRICE: %Lg\n", p->current_portfolio);
    printf("FINAL-STOCK-PRICE: %g\n", p->curr_stock);
    printf("PROFIT-PER: %Lg\n", (p->current_portfolio / p->initial_portfolio) * 100);
    // If just kept onto the stock
    printf("==OTHER\n");
    printf("IF JUST KEPT STOCK: %g\n", (p->curr_stock / p->start_stock)*100);
    printf("PLUS-PROFIT-PER: %Lg\n", ((p->current_portfolio / p->initial_portfolio)-(p->curr_stock / p->start_stock))*100);

}
