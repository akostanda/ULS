#include "uls.h"

static int check_flag(t_flags *flags, char flag) {
    if (flag == 'R') {
        flags->f_R = 1;
    }
    else if (flag == 'l') {
        flags->detail = 1;
    }
    else if (flag == 'a') {
        flags->def_dots = 1;
        flags->def_file_dots = 1;
    }
    else if (flag == 'A') {
        flags->def_file_dots = 1;
    }
    else
        return 1;
    return 0;
}

void mx_read_flags(t_uls *uls, int argc, char **argv) {
    t_flags *flags = uls->flags;
    unsigned int len = 0;

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && mx_strcmp("-\0", argv[i]) != 0) {
            len = mx_strlen(argv[i]);
            for (unsigned int j = 1; j < len; j++) {
                if (check_flag(flags, argv[i][j]))
                    mx_print_error(ERROR_USAGE, NULL, NULL);
            }
        }
    }
}
