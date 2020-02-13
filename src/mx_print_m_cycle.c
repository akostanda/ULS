#include "uls.h"

static bool m_cond(char *name, int screen, t_out *ip) {
    if ((mx_strlen_unicode(name) + 3) <= screen
        || (ip->j == ip->file_amount - 1
        && mx_strlen_unicode(name) + 1 <= screen)
        || ip->j == 0) {
        return true;
    }
    return false;
}

static void m_cycle_cond(char *name, char *acl, int *screen, t_out *ip) {
    if (ip->flags->f_gg) {
        mx_print_gg(name, acl);
        (*screen) = (*screen) - (mx_strlen_unicode(name) + 2);
    }
    else{
        mx_printstr(name);
        (*screen) = (*screen) - (mx_strlen_unicode(name) + 2);
    }
}

void mx_print_m_cycle(t_file **file, t_out *ip) {
    int screen = ip->screen_size;

    for (; file[ip->j]; ip->j++) {
            if (m_cond(file[ip->j]->name, screen, ip))
                m_cycle_cond(file[ip->j]->name, file[ip->j]->acl, &screen, ip);
            else if (ip->j != 0) {
                mx_printstr("\n");
                screen = ip->screen_size;
                m_cycle_cond(file[ip->j]->name, file[ip->j]->acl, &screen, ip);
            }
        if (ip->j < ip->file_amount - 1)
            mx_printstr(", ");
    }
    if (ip->flags->f_r && !ip->flags->def_dots && !ip->flags->def_file_dots)
        mx_printstr(",");
    mx_printstr("\n");
}
