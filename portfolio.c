
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct portfolio {
    double curr_stock;
    double start_stock;

    int stock_cnt;

    char* start_date;

    long double current_portfolio;
    long double initial_portfolio;
} portfolio;

void portfolio_copy(struct portfolio* p, const struct portfolio* pf){

    p->curr_stock = pf->curr_stock;
    p->start_stock = pf->start_stock;
    p->stock_cnt = pf->stock_cnt;
    p->start_date = pf->start_date;
    p->current_portfolio = pf->current_portfolio;
    p->initial_portfolio = pf->initial_portfolio;
}

// Should get the first field for data from the data file
void init_portfolio(struct portfolio* p, double stock, char* date, long double portfolio){
    p->curr_stock = stock;
    p->start_stock = stock;

    p->start_date = date;

    p->current_portfolio = portfolio;
    p->initial_portfolio = portfolio;
}

inline long double get_total_portfolio(const struct portfolio* pf){
    struct portfolio p;
    portfolio_copy(&p, pf);
    long double temp;
    temp = p.current_portfolio + p.stock_cnt * p.curr_stock;
    return temp;
}


void update_portfolio_stock_p(struct portfolio* p, double stock_p){
    p->curr_stock = stock_p;
}
void update_portfolio_sell(struct portfolio *p){
    p->current_portfolio = p->current_portfolio + (p->curr_stock * p->stock_cnt);
    printf("\n\n\n%Lg\n\n", p->current_portfolio);
    p->stock_cnt = 0;
}
void update_stock_p_and_sell(struct portfolio* p, double stock_p){
    update_portfolio_stock_p(p, stock_p);
    update_portfolio_sell(p);
}
void buy_as_much(struct portfolio* p){
    if (p->current_portfolio < p->curr_stock){
        printf("NOT ENOUGH CASH\n");
    }
    long double curr_cash = p->current_portfolio;
    long double bought_stock_cnt = floor(curr_cash / p->curr_stock);
    long double remaining_cash =  p->curr_stock * ((curr_cash / p->curr_stock) - floor(curr_cash / p->curr_stock));
//    printf("\n~~~~~~~~~%Lg~~~~~~~~~~~~~~~\n", remaining_cash);
    p->current_portfolio = remaining_cash;
    p->stock_cnt = p->stock_cnt + bought_stock_cnt;
}
void update_stock_p_and_buy(struct portfolio *p, double stock_p){
    update_portfolio_stock_p(p, stock_p);
    buy_as_much(p);
}

void debug_print(struct portfolio* p){
    printf("\n\n%d\n\n", p->stock_cnt);
}

// finish writing later
void print_summary_sell(struct portfolio* p, char* date){
    printf("\n===============PORTFOLIO SUMMARY SELL ALL==============\n");
    printf("DATE-RANGE: %s -> %s\n", p->start_date, date);
    // print start data
    printf("====START-DATA====\n");
    printf("START-PORTFOLIO: %.3Lg\n", p->initial_portfolio);
    printf("START-STOCK-PRICE: %.3g\n", p->start_stock);
    printf("STOCK-CNT: %d\n", p->stock_cnt);
    // print final data and overview
    printf("====FINAL-DATA====\n");
    printf("FINAL-PORTFOLIO: %.3Lg\n", p->current_portfolio);
    printf("FINAL-STOCK-PRICE: %.3g\n", p->curr_stock);
    printf("PROFIT-PER: %.3Lg\n", ((p->current_portfolio / p->initial_portfolio) * 100)-100);
}
void print_summary_portfolio(struct portfolio* p, char* date){
    printf("\n===============PORTFOLIO SUMMARY==============\n");
    printf("DATE-RANGE: %s -> %s\n", p->start_date, date);
    // print start data
    printf("====START-DATA====\n");
    printf("START-PORTFOLIO: %.3Lg\n", p->initial_portfolio);
    printf("START-STOCK-PRICE: %.3g\n", p->start_stock);
    printf("STOCK-CNT: %d\n", p->stock_cnt);
    // print final data and overview
    printf("====FINAL-DATA====\n");
    printf("FINAL-PORTFOLIO: %.3Lg\n", p->current_portfolio);
    printf("FINAL-STOCK-PRICE: %.3g\n", p->curr_stock);
    printf("PROFIT-PER: %.3Lg\n", ((p->current_portfolio / p->initial_portfolio) * 100)-100);
    // If just kept onto the stock
    /* printf("==OTHER\n"); */
    /* printf("IF JUST KEPT STOCK: %g\n", ((p->curr_stock / p->start_stock)*100)-100); */
    /* printf("PLUS-PROFIT-PER: %Lg\n", ((p->current_portfolio / p->initial_portfolio)-(p->curr_stock / p->start_stock))*100); */

}
