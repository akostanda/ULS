#include "uls.h"

int mx_strcmp_unicode(const char *s1, const char *s2) {
    int i = 0;

    while ((unsigned char)s1[i] == (unsigned char)s2[i]
        && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
