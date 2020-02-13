#include "uls.h"

void mx_right_alt(char *str, int count) {
    int len = mx_strlen_unicode(str);

    if (len == count) {
        mx_printchar(' ');
        mx_printstr(str);
        mx_printchar(' ');
    }
    else {
        mx_printchar(' ');
        mx_printstr(str);
        for (int i = count - len; i > 0; i--)
            mx_printchar(' ');
        mx_printchar(' ');
    }
}
