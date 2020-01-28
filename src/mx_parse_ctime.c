#include "uls.h"

t_time *mx_parse_ctime(time_t time) {
    t_time *parsed_time = (t_time *)malloc(sizeof(t_time));
    char *date = ctime(&time);
    int i = 0;

    parsed_time->mmdd = mx_strnew(6);
    for (i = 0; i < 6; i++)
        parsed_time->mmdd[i] = date[i + 4];
    parsed_time->time = mx_strnew(5);
    for (i = 0; i < 5; i++)
        parsed_time->time[i] = date[i + 11];
    parsed_time->year = mx_strnew(4);
    for (i = 0; i < 4; i++)
        parsed_time->year[i] = date[i + 20];
    parsed_time->r_time = time;
    return parsed_time;
}
