#include "uls.h"

void mx_left_aligment(char *str, int count) {
    int len = mx_strlen(str);

    if (len == count) {
        mx_printstr(" ");
        mx_printstr(str);
    }
    else {
        mx_printchar(' ');
        for (int i = count - len; i > 0; i--)
            mx_printchar(' ');
            mx_printstr(str);
    }
}
