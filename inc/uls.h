#ifndef ULS_H
#define ULS_H

/* DEFINES */

#define IFMT 0170000
#define IFIFO 0010000
#define IFCHR 0020000
#define IFDIR 0040000
#define IFBLK 0060000
#define IFREG 0100000
#define IFLNK 0120000
#define IFSOCK 0140000

#define IRWXU 0000700
#define IRUSR 0000400
#define IWUSR 0000200
#define IXUSR 0000100

#define IRWXG 0000070
#define IRGRP 0000040
#define IWGRP 0000020
#define IXGRP 0000010

#define IRWXO 0000007
#define IROTH 0000004
#define IWOTH 0000002
#define IXOTH 0000001

#define ISUID 0004000
#define ISGID 0002000
#define ISVTX 0001000

#define ISBLK(m) (((m) & IFMT) == IFBLK)
#define ISCHR(m) (((m) & IFMT) == IFCHR)
#define ISDIR(m) (((m) & IFMT) == IFDIR)
#define ISFIFO(m) (((m) & IFMT) == IFIFO)
#define ISREG(m) (((m) & IFMT) == IFREG)
#define ISLNK(m) (((m) & IFMT) == IFLNK)
#define ISSOCK(m) (((m) & IFMT) == IFSOCK)

#define MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MINOR(x) ((int32_t)((x) & 0xffffff))

#define ERROR_USAGE "usage: uls [-laA] [file ...]\n"
#define ERROR_ULS "uls: "
#define ERROR_NSFOD ": No such file or directory\n"

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

typedef struct s_flags {
    bool f_R;
    bool detail;
    bool def_dots;
    bool def_file_dots;
    bool first_out;
} t_flags;

typedef struct s_out {
    int i;
    int j;
    int k;
    int count_link;
    int count_uname;
    int count_group;
    unsigned int count_size;
    int file_amount;
    int openfile_amt;
    int columns;
    int rows;
    unsigned long long blocks;
    char *nlink;
    char *size;
    char *gid;
} t_out;

typedef struct s_time {
    char *mmdd;
    char *time;
    char *year;
    time_t r_time;
} t_time;

typedef struct s_driver {
    char *driver;
    unsigned int size;
} t_driver;

typedef struct s_file {
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
} t_file;

typedef struct s_dir {
    char *path;
    unsigned int lenght;
    t_file **files;
} t_dir;

typedef struct s_uls {
    t_flags *flags;
    unsigned int files_count;
    unsigned int dirs_count;
    t_file **files;
    t_dir **dirs;
} t_uls;

char *mx_read_link(t_file *file, char *path);
char *mx_gen_acl_str(t_file *file, char *path);
int mx_check_is_folder(char *path);
int mx_rows_amount(int openfile_amt, int longest_name, int *columns);
t_dir *mx_create_dir();
t_dir **mx_create_dirs_array(unsigned int size);
t_dir *mx_read_dir(t_uls *uls, char *path);
t_driver *mx_create_driver();
t_file *mx_create_file();
t_file **mx_create_files_array(unsigned int size);
t_file *mx_read_file(char *file_path, char *file_name);
t_file **mx_read_files_array(DIR **dr, t_direntry **direntry,
char *path, unsigned int lenght);
t_flags *mx_create_flags();
t_out *mx_create_outnode();
t_time *mx_parse_ctime(time_t time);
t_uls *mx_create_uls();
unsigned int mx_count_in_dir(char *path);
unsigned int mx_get_major(t_file *file);
unsigned int mx_get_minor(t_file *file);
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
void mx_print_A_file(t_file **file);
void mx_print_A_file_detail(t_file **file);
void mx_print_allfile_detail(t_file **file);
void mx_print_allfile(t_file **file);
void mx_print_blocks(unsigned long long blocks);
void mx_print_error(char *str1, char *str2, char *str3);
void mx_print_file_cycle(t_file **file, t_out *ip, int index, int count);
void mx_print_file_detail(t_file **file);
void mx_print_flags(t_uls *uls);
void mx_print_l_file(t_file **file);
void mx_print_l_file_detail(t_file **file);
void mx_print_time(t_file *file, time_t this_time);
void mx_print_warning(char *str1, char *str2, char *str3);
void mx_read_driver(t_file *file, t_driver *driver);
void mx_read_flags(t_uls *uls, int argc, char **argv);
void mx_read_out(t_file *file, t_out *ip);
void mx_read_uls(t_uls *uls, int argc, char **argv);
void mx_right_alt(char *str, int count);
void mx_sort_dirs_by_ascii(t_dir **dirs, unsigned int lenght);
void mx_sort_files_by_ascii(t_file **files, unsigned int lenght);

/* -------- */

#endif
