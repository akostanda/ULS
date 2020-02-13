#include "uls.h"

void mx_left_s_aligment(char *str, int count) {
    int len = mx_strlen_unicode(str);

    if (len == count) {
        mx_printstr(str);
    }
    else {
        for (int i = count - len; i > 0; i--)
            mx_printchar(' ');
            mx_printstr(str);
    }
}
