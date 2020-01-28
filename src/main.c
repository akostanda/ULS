#include "uls.h"

int main(int argc, char *argv[]) {
    t_uls *uls = mx_create_uls();
    mx_read_uls(uls, argc, argv);
    // mx_printstr("1\n");

    int i = 0;
    // int j = 0;
    // if (uls->files) {
    //     // while (uls->files) {
    //         mx_print_allfile_detail(uls->files);
           
    //     // }
    //     mx_printchar('\n');
    // }
    i = 0;
    // if (uls->dirs) {
    //     while (uls->dirs[i]) {
    //         j = 0;
            // printf("%s\n", uls->dirs[i]->path);
            // printf("%u\n", uls->dirs[i]->lenght);
    //         // while (j < uls->dirs[i]->lenght) {
    //             mx_printstr(uls->dirs[i]->path);
    //             mx_printstr(":\n");
    //             mx_sort_by_ascii(uls->dirs[i]->files, uls->dirs[i]->lenght);
    //             // mx_print_allfile_detail(uls->dirs[i]->files);
    //             // mx_printchar('\n');
    //             // mx_print_l_file_detail(uls->dirs[i]->files);
    //             // mx_printchar('\n');
    //             // mx_print_A_file_detail(uls->dirs[i]->files);
    //             mx_print_allfile(uls->dirs[i]->files);
    //             mx_printchar('\n');
    //             mx_print_A_file(uls->dirs[i]->files);
    //             mx_printchar('\n');
    //             mx_print_l_file(uls->dirs[i]->files);
    //             j++;
    //         // }
    //         // mx_printchar('\n');
    //         i++;
    //     }
    // }
mx_print_flags(uls);
    // OUTPUT ULS

    mx_dealloc_uls(&uls);
    // system("leaks -q uls");
    return 0;
}
