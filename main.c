
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
    struct portfolio p = init_portfolio(
    10.00, "2021-04-16", 10000);
    p = update_stock_p_and_buy(&p, 12);
    p = update_portfolio_sell(&p);
    print_summary(&p, "2021-04-19");
}
