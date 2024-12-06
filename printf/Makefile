NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
CC = gcc -c
RM = rm -rf
AR = ar -rcs

SRC = ft_itoa.c \
		ft_print_hexa.c \
		ft_print_num.c \
		ft_print_ptr.c \
		ft_print_str.c \
		ft_printf.c \
		ft_putchar.c \
		ft_un_num.c \

OBJ = $(SRC:.c=*.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

$(OBJ):
		@$(CC) $(FLAGS) $(SRC)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
