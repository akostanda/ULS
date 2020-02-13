#include "uls.h"

void mx_left_aligment(char *str, int count) {
    int len = mx_strlen_unicode(str);

    if (len == count) {
        mx_printchar(' ');
        mx_printstr(str);
    }
    else {
        mx_printchar(' ');
        for (int i = count - len; i > 0; i--)
            mx_printchar(' ');
            mx_printstr(str);
    }
}
