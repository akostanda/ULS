#include "uls.h"

static void check_flag(t_uls *uls, t_d_lst **head, char *arg, t_out *ip) {
    if (arg[0] == '-' && mx_strcmp("-\0", arg) != 0) {
        if (mx_strcmp("--\0", arg) != 0)
            mx_read_flags(uls, arg);
        else
            uls->flags->r_fd_only = true;
    }
    else
        mx_prepare_data(uls, head, arg, ip);
}

static void read_all_args(t_uls *uls, t_d_lst **head, char **argv, t_out *ip) {
    for (int i = 1; i < ip->argc; i++) {
        if (uls->flags->r_fd_only)
            mx_prepare_data(uls, head, argv[i], ip);
        else
            check_flag(uls, head, argv[i], ip);
    }
}

static void push_dot(t_uls *uls, t_out *ip) {
    uls->dirs = mx_create_dirs_array(1);
    uls->dirs[0] = mx_read_dir(uls->flags, ".", ip);
    uls->dirs_count = 1;
}

static void uls_sort_condition(t_uls *uls) {
    if (uls->files && !uls->flags->f_f) {
        mx_sort_files_by_ascii(uls->files, uls->files_count);
        if (uls->flags->f_ss)
            mx_sort_files_by_size(uls->files, uls->files_count);
        else if (uls->flags->f_t)
            mx_sort_files_by_time(uls->files, uls->files_count, uls->flags);
        if (uls->flags->f_r)
            mx_reverse_files(uls->files, uls->files_count);
    } 
    if (uls->dirs && !uls->flags->f_f) {
        mx_sort_dirs_by_ascii(uls->dirs, uls->dirs_count);
        if (uls->flags->f_ss)
            mx_sort_dirs_by_size(uls->dirs, uls->dirs_count);
        else if (uls->flags->f_t)
            mx_sort_dirs_by_time(uls->dirs, uls->dirs_count, uls->flags);
        if (uls->dirs && uls->flags->f_r)
            mx_reverse_dirs(uls->dirs, uls->dirs_count);
    }
}

void mx_read_uls(t_uls *uls, int argc, char **argv, t_out *ip) {
    t_d_lst *head = NULL;

    ip->argc = argc;
    read_all_args(uls, &head, argv, ip);
    if (head)
        mx_lst_to_arr(uls, &head);
    else if (!uls->flags->errtrig)
        push_dot(uls, ip);
    uls_sort_condition(uls);
}
