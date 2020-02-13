NAME = uls

ROOT_A = libmx.a \

LIB_A = ./libmx/libmx.a \

HEADERS = uls.h \

FILES = main \
	mx_aa_file_condition \
	mx_acl_strcol \
	mx_acl_bkcol \
	mx_aligment_file \
	mx_change_color \
	mx_check_is_folder \
	mx_check_lower_flag \
	mx_check_upper_flag \
	mx_clear_out \
	mx_color_reset \
	mx_count_in_dir \
	mx_create_data_node \
	mx_create_dir \
	mx_create_dirs_array \
	mx_create_driver \
	mx_create_file \
	mx_create_files_array \
	mx_create_flags \
	mx_create_out \
	mx_create_uls \
	mx_dealloc_dir \
	mx_dealloc_dirs \
	mx_dealloc_driver \
	mx_dealloc_file \
	mx_dealloc_files \
	mx_dealloc_out \
	mx_dealloc_time \
	mx_dealloc_uls \
	mx_d_lst_len \
	mx_gen_acl_str \
	mx_gen_sizconstr \
	mx_get_group \
	mx_get_lstat \
	mx_get_major \
	mx_get_minor \
	mx_get_passwd \
	mx_left_aligment \
	mx_left_s_aligment \
	mx_longest_name \
	mx_lst_to_arr \
	mx_parse_ctime \
	mx_pop_data_front \
	mx_prepare_data \
	mx_print_allfile_detail \
	mx_print_blocks \
	mx_print_error \
	mx_print_gg \
	mx_print_file_without_details_cycle \
	mx_print_file_detail \
	mx_print_file_without_details \
	mx_print_flags \
	mx_print_m_cycle \
	mx_print_path \
	mx_print_rrflag \
	mx_print_rrflag_cycle \
	mx_print_time_name_color \
	mx_print_warning \
	mx_push_data_back \
	mx_read_dir \
	mx_read_driver \
	mx_read_file \
	mx_read_files_array \
	mx_read_flags \
	mx_read_link \
	mx_read_out \
	mx_read_uls \
	mx_reverse_dirs \
	mx_reverse_files \
	mx_right_alt \
	mx_rows_amount \
	mx_sort_dirs_by_ascii \
	mx_sort_dirs_by_size \
	mx_sort_dirs_by_time \
	mx_sort_files_by_ascii \
	mx_sort_files_by_size \
	mx_sort_files_by_time \
	mx_space_amount \
	mx_strcmp_unicode \
	mx_strjoin_path \
	mx_strlen_unicode \
	mx_swap_dirs \
	mx_swap_files \
	mx_tab_amount \
	mx_zeroing_out \
	mx_set_acl_ads \

INC_H = $(addprefix "inc/", $(HEADERS))

ROOT_C = $(addsuffix ".c", $(FILES))

SRC_C = $(addprefix "src/", $(ROOT_C))

ROOT_O = $(addsuffix ".o", $(FILES))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@make -C libmx install
	@cp $(SRC_C) .
	@cp $(INC_H) .
	@cp $(LIB_A) .
	@clang $(CFLAGS) -c $(ROOT_C)
	@clang $(CFLAGS) $(ROOT_O) $(ROOT_A) -o $(NAME)
	@mkdir -p obj
	@cp $(ROOT_O) obj/
	@rm -rf $(ROOT_O)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)
	@rm -rf $(ROOT_A)

clean:
	@make -C libmx clean
	@rm -rf $(ROOT_O)
	@rm -rf $(ROOT_C)
	@rm -rf $(HEADERS)
	@rm -rf obj

reinstall: uninstall install
