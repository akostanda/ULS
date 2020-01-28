#include "uls.h"

int mx_rows_amount(int openfile_amt, int longest_name, int *columns) {
    int rows = 0;
    t_screen screen;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &screen);
    (*columns) = screen.ws_col / longest_name;
    if (openfile_amt % (*columns) == 0)
        rows = openfile_amt / (*columns);
    else
        rows = openfile_amt / (*columns) + 1;
    return rows;
}
