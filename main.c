
#include <stdio.h>

#include "readf.c"
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

int main() {
    /* char* s = "datetime;open;high;low;close;volume"; */
    /* char** buff = strsplit(s, ';'); */
    /* printf("%s\n", buff[0]); */
    /* printf("%s\n", buff[1]); */
    /* printf("%s\n", buff[2]); */
    /* printf("%s\n", buff[3]); */
    /* printf("%s\n", buff[4]); */
    /* printf("%s\n", buff[5]); */
    char* s = "12.22333";
    char* end;
    long double d = strtold(s, &end);

    char* ss = "23123213.2131";
    long double dd = strtold(ss, &end);
    printf("%Lg\n", d);
    printf("%Lg\n", dd);
    /* char* s = "Hello;OOoga;Anggi;"; */
    /* char** buff = strsplit(s, ';'); */
    /* while (*buff != NULL){ */
    /*     printf("%s", *buff); */
    /*     buff++; */
    /* } */
}

/* char** buf; */
/* buf = malloc(4 * sizeof(char*)); */
/* buf[0] = malloc(100); */
/* buf[1] = malloc(100); */
/* buf[2] = malloc(100); */
/* strcpy(buf[0], "FirstBuf\n"); */
/* strcpy(buf[1], "SecondBuf\n"); */
/* strcpy(buf[2], "ThirdBuffer\n"); */
/* printf("HELLO"); */
/* while(*buf != NULL){ */
/*     printf("%s", *buf); */
/*     buf++; */
/* } */

/* struct portfolio p = {}; */
/* init_portfolio(&p, 10.00, "2021-04-16", 20); */

/* buy_as_much(&p); */
/* printf("|%Lg|", p.current_portfolio); */
/* debug_print(&p); */
/* update_portfolio_stock_p(&p, 12); */
/* update_portfolio_sell(&p); */

/* update_portfolio_stock_p(&p, 9); */
/* buy_as_much(&p); */

/* update_portfolio_sell(&p); */

/* /\* buy_as_much(&p); *\/ */
/* print_summary(&p, "2021-04-19"); */
