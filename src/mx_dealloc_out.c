#include "uls.h"

void mx_dealloc_out(t_out *ip) {
    mx_clear_out(ip);
    free(ip);
}
