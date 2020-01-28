#include "uls.h"

void mx_print_time(t_file *file, time_t this_time) {
    mx_printstr(" ");
    mx_printstr(file->time->mmdd);
    mx_printstr(" ");
    if (file->time->r_time <= (this_time - 15778463)
        || file->time->r_time > this_time) {
        mx_printchar(' ');
        mx_printstr(file->time->year);
    }
    else 
        mx_printstr(file->time->time);
    mx_printstr(" ");
    mx_printstr(file->name);
    if (file->link != NULL) {
        mx_printstr(" -> ");
        mx_printstr(file->link);
    }
    mx_printstr("\n");
}
