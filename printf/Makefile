O_FILES = ft_printf.o ft_printf_utils.o
NAME 	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
CC		= gcc
ARFLAGS = -rcs

all: $(NAME)

$(NAME): $(O_FILES)
		ar $(ARFLAGS) $(NAME) $(O_FILES)

fclean: clean
		rm -rf $(NAME)

clean:
		rm -rf $(O_FILES)

re: fclean all

.c.o:
		$(CC) -c $< $(CFLAGS)

.PHONY: clean fclean all re