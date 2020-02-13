#include "uls.h"

int main(int argc, char *argv[]) {
    t_uls *uls = mx_create_uls();
    t_out *ip = mx_create_out();
    int exit_code = 0;

    mx_read_uls(uls, argc, argv, ip);
    ip->flags = uls->flags;
    mx_print_flags(uls, ip);
    exit_code = uls->flags->errtrig;
    mx_dealloc_out(ip);
    mx_dealloc_uls(&uls);
    return exit_code;
}
