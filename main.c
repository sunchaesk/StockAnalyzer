
#include <stdio.h>
#include <assert.h>
#include <string.h>

// #include "file_read.c"
// #include "portfolio.c"
#include "donchian.c"



int main() {
    data_list d = file_read_main("data/aapl.txt");
    donchian donc = init_donchian(d);
    d_print_donchian(donc);
    update_donchian(&donc);
    d_print_donchian(donc);
}
