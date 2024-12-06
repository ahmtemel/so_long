NAME = so_long
NAME_BNS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		handle_key.c \
		player_control.c \
		xpm_generate.c \
		so_long.c \
		error_exit.c \
		find_player_exit.c \
		memory_matrix.c \
		valid_different.c \
		walls.c \
		./printf/ft_printf.c \
		./printf/ft_itoa.c \
		./printf/ft_print_hexa.c \
		./printf/ft_print_num.c \
		./printf/ft_print_ptr.c \
		./printf/ft_print_str.c \
		./printf/ft_putchar.c \
		./printf/ft_un_num.c \

SRCS_BNS = ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		handle_key_bonus.c \
		player_control_bonus.c \
		xpm_generate_bonus.c \
		so_long_bonus.c \
		error_exit_bonus.c \
		find_player_exit_bonus.c \
		memory_matrix_bonus.c \
		valid_different_bonus.c \
		walls_bonus.c \
		./printf/ft_printf.c \
		./printf/ft_itoa.c \
		./printf/ft_print_hexa.c \
		./printf/ft_print_num.c \
		./printf/ft_print_ptr.c \
		./printf/ft_print_str.c \
		./printf/ft_putchar.c \
		./printf/ft_un_num.c \

all: $(NAME)

$(NAME): ${SRCS}
	@make -C ./printf
	@make -C ./mlx
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@clear
	@echo "The make is done"
bonus: $(SRCS_BNS)
	@make -C ./printf
	@make -C ./mlx
	@$(CC) $(SRCS_BNS) $(CFLAGS) -o $(NAME_BNS)
	@clear
	@echo "The make bonus is done"
clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME_BNS)
	@make clean -C mlx/
	@make clean -C printf/
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BNS)
	@make clean -C mlx/
	@make fclean -C printf/
re: fclean all
