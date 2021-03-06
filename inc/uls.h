#ifndef ULS_H
#define ULS_H

/* DEFINES */

#define MX_IFMT 0170000
#define MX_IFIFO 0010000
#define MX_IFCHR 0020000
#define MX_IFDIR 0040000
#define MX_IFBLK 0060000
#define MX_IFREG 0100000
#define MX_IFLNK 0120000
#define MX_IFSOCK 0140000

#define MX_IRWXU 0000700
#define MX_IRUSR 0000400
#define MX_IWUSR 0000200
#define MX_IXUSR 0000100

#define MX_IRWXG 0000070
#define MX_IRGRP 0000040
#define MX_IWGRP 0000020
#define MX_IXGRP 0000010

#define MX_IRWXO 0000007
#define MX_IROTH 0000004
#define MX_IWOTH 0000002
#define MX_IXOTH 0000001

#define MX_ISUID 0004000
#define MX_ISGID 0002000
#define MX_ISVTX 0001000

#define MX_ISBLK(m) (((m) & MX_IFMT) == MX_IFBLK)
#define MX_ISCHR(m) (((m) & MX_IFMT) == MX_IFCHR)
#define MX_ISDIR(m) (((m) & MX_IFMT) == MX_IFDIR)
#define MX_ISFIFO(m) (((m) & MX_IFMT) == MX_IFIFO)
#define MX_ISREG(m) (((m) & MX_IFMT) == MX_IFREG)
#define MX_ISLNK(m) (((m) & MX_IFMT) == MX_IFLNK)
#define MX_ISSOCK(m) (((m) & MX_IFMT) == MX_IFSOCK)

#define MX_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x) ((int32_t)((x) & 0xffffff))

#define MX_BLACK 0
#define MX_RED 1
#define MX_GREEN 2
#define MX_YELLOW 3
#define MX_BLUE 4
#define MX_MAGENTA 5
#define MX_CYAN 6
#define MX_WHITE 7
#define MX_DEF 9

#define MX_RESET "\x1B[0m"

#define MX_ERR_USAGE "usage: uls [-ACGRSTUacfghlmoqrstu1] [file ...]\n"
#define MX_ERR_OPTION "uls: illegal option -- "
#define MX_ERR_ULS "uls: "
#define MX_ERR_NSFOD ": No such file or directory\n"
#define MX_ERR_PERMD ": Permission denied\n"

/* -------- */

/* INClUDES */

#include <dirent.h>
#include "libmx/inc/libmx.h"
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <sys/acl.h>
#include <sys/errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <time.h>

/* -------- */

/* DECLARATIONS */

typedef struct stat t_stat;
typedef struct dirent t_direntry;
typedef struct passwd t_passwd;
typedef struct group t_group;
typedef struct winsize t_screen;

typedef struct  s_flags {
    bool f_cc;
    bool f_gg;
    bool f_rr;
    bool f_ss;
    bool f_tt;
    bool f_uu;
    bool f_c;
    bool f_f;
    bool f_h;
    bool f_g;
    bool f_m;
    bool f_q;
    bool f_o;
    bool f_r;
    bool f_s;
    bool f_t;
    bool f_u;
    bool f_1;
    bool detail;
    bool def_dots;
    bool def_file_dots;
    bool print_empty_lines;
    bool print_pathes;
    bool r_fd_only;
    bool errtrig;
}               t_flags;

typedef struct  s_out {
    int i;
    int j;
    int k;
    int count;
    int count_group;
    int count_link;
    int count_uname;
    int file_amount;
    int argc;
    int columns;
    int rows;
    int screen_size;
    int count_blocks;
    unsigned int count_size;
    unsigned int array_size;
    unsigned int lenght;
    unsigned long long blocks;
    char *name;
    char *nlink;
    char *size;
    char *gid;
    char *sblocks;
    t_flags *flags;
}               t_out;

typedef struct  s_time {
    char *mmdd;
    char *time;
    char *year;
    time_t r_time;
}               t_time;

typedef struct  s_driver {
    char *driver;
    unsigned int size;
}               t_driver;

typedef struct  s_file {
    char *name;
    char *username;
    char *gr;
    char *acl;
    char *link;
    unsigned int gid;
    unsigned long long blocks;
    t_stat stat;
    t_driver *driver;
    t_time *time;
}               t_file;

typedef struct  s_dir {
    char *path;
    unsigned int lenght;
    bool permission;
    t_stat stat;
    t_file **files;
}               t_dir;

typedef struct  s_uls {
    t_flags *flags;
    unsigned int files_count;
    unsigned int dirs_count;
    t_file **files;
    t_dir **dirs;
}               t_uls;

typedef struct  s_d_lst {
    t_file *file;
    t_dir *dir;
    struct s_d_lst *next;
}               t_d_lst;

bool mx_aa_file_condition(char *name);
bool mx_check_for_open_err(char *path);
bool mx_islower(int c);
bool mx_isupper(int c);

char *mx_read_link(t_file *file, char *path);
char *mx_gen_acl_str(t_file *file, char *path);
char *mx_gen_sizconstr(unsigned long long size);
char *mx_strjoin_path(char *s1, char *s2, const char c);

int mx_change_color(unsigned char t, unsigned char b);
int mx_check_is_folder(char *path);
int mx_check_lower_flag(t_flags *flags, char flag);
int mx_check_upper_flag(t_flags *flags, char flag);
int mx_color_reset();
int mx_d_lst_len(t_d_lst **head, int mode);
int mx_longest_name(t_file **file, int *file_amount, t_flags *flags);
int mx_rows_amount(int openfile_amt, int longest_name, int *columns,
                   t_out **ip);
int mx_space_amount(char *str, int size);
int mx_strcmp_unicode(const char *s1, const char *s2);
int mx_strlen_unicode(const char *s);
int mx_tab_amount(char *str, int size);

unsigned int mx_count_in_dir(char *path, t_flags *flags);
unsigned int mx_get_major(t_file *file);
unsigned int mx_get_minor(t_file *file);

unsigned char mx_acl_bkcol(char *acl);
unsigned char mx_acl_strcol(char *acl);

t_d_lst *mx_create_data_node(t_file *file, t_dir *dir);
t_dir *mx_create_dir();
t_dir **mx_create_dirs_array(unsigned int size);
t_dir *mx_read_dir(t_flags *flags, char *path, t_out *ip);
t_driver *mx_create_driver();
t_flags *mx_create_flags();
t_file *mx_create_file();
t_file **mx_create_files_array(unsigned int size);
t_file *mx_read_file(char *file_path, char *file_name, t_flags *flags);
t_file **mx_read_files_array(DIR **dr, t_direntry **direntry, char *path,
t_out *ip);
t_out *mx_create_out();
t_time *mx_parse_ctime(time_t time, t_flags *flags);
t_uls *mx_create_uls();

void mx_aligment_file(t_file **file, t_out *ip);
void mx_clear_out(t_out *ip);
void mx_dealloc_dir(t_dir **dir);
void mx_dealloc_dirs(t_dir ***dirs);
void mx_dealloc_driver(t_driver **driver);
void mx_dealloc_file(t_file **file);
void mx_dealloc_files(t_file ***files);
void mx_dealloc_out(t_out *ip);
void mx_dealloc_time(t_time **time);
void mx_dealloc_uls(t_uls **uls);
void mx_get_group(t_file *file);
void mx_get_lstat(t_file *file, char *file_path);
void mx_get_passwd(t_file *file);
void mx_left_aligment(char *str, int count);
void mx_left_s_aligment(char *str, int count);
void mx_lst_to_arr(t_uls *uls, t_d_lst **head);
void mx_pop_data_front(t_d_lst **head);
void mx_prepare_data(t_uls *uls, t_d_lst **head, char *arg, t_out *ip);
void mx_print_allfile_detail(t_file **file, t_flags *flags, t_out *ip);
void mx_print_blocks(unsigned long long blocks);
void mx_print_error(char *str1, char *str2, char *str3);
void mx_print_gg(char *name, char *acl);
void mx_print_file_without_details_cycle(t_file **file, t_out *ip);
void mx_print_file_detail(t_file **file, t_flags *flags, t_out *ip);
void mx_print_file_without_details(t_file **file, t_flags *flags, t_out *ip);
void mx_print_flags(t_uls *uls, t_out *ip);
void mx_print_m_cycle(t_file **file, t_out *ip);
void mx_print_path(char *path);
void mx_print_rrflag(char *path, t_flags *flags, char *name, t_out *ip);
void mx_print_rrflag_cycle(t_dir *dir, t_flags *flags, t_out *ip);
void mx_print_time_name_color(t_file *file, time_t this_time,
                              t_flags *flags, t_out *ip);
void mx_print_warning(char *str1, char *str2, char *str3);
void mx_push_data_back(t_d_lst **head, t_file *file, t_dir *dir);
void mx_read_driver(t_file *file, t_driver *driver);
void mx_read_flags(t_uls *uls, char *arg);
void mx_read_out(t_file *file, t_out *ip);
void mx_read_uls(t_uls *uls, int argc, char **argv, t_out *ip);
void mx_reverse_dirs(t_dir **dirs, unsigned int lenght);
void mx_reverse_files(t_file **files, unsigned int lenght);
void mx_right_alt(char *str, int count);
void mx_set_acl_ads(char *path, char *acl);
void mx_sort_dirs_by_ascii(t_dir **dirs, unsigned int lenght);
void mx_sort_dirs_by_size(t_dir **dirs, unsigned int lenght);
void mx_sort_dirs_by_time(t_dir **dirs, unsigned int lenght, t_flags *flags);
void mx_sort_files_by_ascii(t_file **files, unsigned int lenght);
void mx_sort_files_by_size(t_file **files, unsigned int lenght);
void mx_sort_files_by_time(t_file **files, unsigned int lenght,
                           t_flags *flags);
void mx_swap_dirs(t_dir **dir1, t_dir **dir2);
void mx_swap_files(t_file **file1, t_file **file2);
void mx_zeroing_out(t_out *ip);

/* -------- */

#endif
