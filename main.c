
#include <stdio.h>

#include "readf.c"
#include "portfolio.c"


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

int main() {
    struct portfolio p = {};
    init_portfolio(&p, 10.00, "2021-04-16", 20);

    buy_as_much(&p);
    printf("|%Lg|", p.current_portfolio);
    debug_print(&p);
    update_portfolio_stock_p(&p, 12);
    update_portfolio_sell(&p);

    update_portfolio_stock_p(&p, 9);
    buy_as_much(&p);

    update_portfolio_sell(&p);

    /* buy_as_much(&p); */
    print_summary(&p, "2021-04-19");
}
