#include "uls.h"

int mx_strlen_unicode(const char *s) {
    int i = 0;
    int count = 0;

    if (s == NULL)
        return 0;
    while (s[i] != '\0') {
        if ((s[i] & 0xC0) != 0x80)
            count++;
        i++;
    }
    return count;
}
