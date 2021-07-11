NAME = pipex

MAKE = make -C

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
	get_next_line/get_next_line.c \
	srcs/error.c \
	srcs/free_table_bonus.c \
	srcs/simple_redirection.c \
	srcs/lst_functions.c \
	srcs/functions_tool/get_env_var_path.c \
	srcs/functions_tool/fill_linked_list_of_cmds.c \
	srcs/functions_tool/check_for_the_right_path.c \
	srcs/functions_tool/read_from_input.c \
	srcs/execution/execution_part.c \
	srcs/execution/launching_child_processes.c \
	srcs/execution/waiting_for_processes.c \
	srcs/execution/first_cmd.c \
	srcs/execution/second_cmd.c \
	srcs/execution/last_cmd.c \

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = main_bonus.c \
	get_next_line/get_next_line_bonus.c \
	srcs/error_bonus.c \
	srcs/free_table.c \
	srcs/simple_redirection_bonus.c \
	double_redirection_bonus.c \
	srcs/lst_functions_bonus.c \
	srcs/functions_tool/get_env_var_path_bonus.c \
	srcs/functions_tool/fill_linked_list_of_cmds_bonus.c \
	srcs/functions_tool/check_for_the_right_path_bonus.c \
	srcs/functions_tool/read_from_input_bonus.c \
	srcs/execution/execution_part_bonus.c \
	srcs/execution/launching_child_processes_bonus.c \
	srcs/execution/waiting_for_processes_bonus.c \
	srcs/execution/first_cmd_bonus.c \
	srcs/execution/second_cmd_bonus.c \
	srcs/execution/last_cmd_bonus.c \

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME):
	@$(MAKE) libft
	@$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

bonus:
	@$(MAKE) libft
	@$(CC) $(CFLAGS) $(SRCS_BONUS) libft/libft.a -o $(NAME)

clean:
	@$(MAKE) libft clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@rm libft/libft.a
	@rm -f $(NAME)

re: fclean all

