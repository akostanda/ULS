NAME = uls

ROOT_A = libmx.a \

LIB_A = ./libmx/libmx.a \

HEADERS = uls.h \

FILES = main \
	mx_check_is_folder \
	mx_clear_out \
	mx_count_in_dir \
	mx_create_dir \
	mx_create_dirs_array \
	mx_create_driver \
	mx_create_file \
	mx_create_files_array \
	mx_create_flags \
	mx_create_outnode \
	mx_create_uls \
	mx_dealloc_dir \
	mx_dealloc_dirs \
	mx_dealloc_driver \
	mx_dealloc_file \
	mx_dealloc_files \
	mx_dealloc_out \
	mx_dealloc_time \
	mx_dealloc_uls \
	mx_gen_acl_str \
	mx_get_group \
	mx_get_lstat \
	mx_get_major \
	mx_get_minor \
	mx_get_passwd \
	mx_left_aligment \
	mx_parse_ctime \
	mx_print_A_file \
	mx_print_A_file_detail \
	mx_print_allfile_detail \
	mx_print_allfile \
	mx_print_blocks \
	mx_print_error \
	mx_print_file_cycle \
	mx_print_file_detail \
	mx_print_flags \
	mx_print_l_file \
	mx_print_l_file_detail \
	mx_print_time \
	mx_print_warning \
	mx_read_dir \
	mx_read_driver \
	mx_read_file \
	mx_read_files_array \
	mx_read_flags \
	mx_read_link \
	mx_read_out \
	mx_read_uls \
	mx_right_alt \
	mx_rows_amount \
	mx_sort_dirs_by_ascii \
	mx_sort_files_by_ascii \

INC_H = $(addprefix "inc/", $(HEADERS))

ROOT_C = $(addsuffix ".c", $(FILES))

SRC_C = $(addprefix "src/", $(ROOT_C))

ROOT_O = $(addsuffix ".o", $(FILES))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx install
	@cp $(SRC_C) .
	@cp $(INC_H) .
	@cp $(LIB_A) .
#	@clang $(CFLAGS) -c $(ROOT_C)
#	@clang $(CFLAGS) $(ROOT_O) $(ROOT_A) -o $(NAME)
	# TEST MODE
	@clang -std=c11 -c $(ROOT_C)
	@clang -std=c11 $(ROOT_O) $(ROOT_A) -o $(NAME)
	@mkdir -p obj
	@cp $(ROOT_O) obj/
	@rm -rf $(ROOT_O)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)

clean:
	@make -C libmx clean
	@rm -rf $(ROOT_C)
	@rm -rf $(ROOT_A)
	@rm -rf $(HEADERS)
	@rm -rf obj

reinstall: uninstall install
