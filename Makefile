NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OTHERS =  ./libft/libft.a ./mlx/libmlx.a ./printf/libftprintf.a
SRCS = gnl/get_next_line.c main.c data.c render.c valid.c
HEADER = so_long.h
OBJS = $(SRCS:.c=.o)

all: $(OTHERS) $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OTHERS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

fclean : clean
	$(RM) $(NAME)
	make fclean -C ./libft
	make fclean -C ./printf

clean : cleanothers
	$(RM) ./*.o

cleanothers :
	make clean -C ./libft
	make clean -C ./printf
	rm gnl/get_next_line.o

re : fclean all

.PHONY : all fclean clean re

$(OTHERS): 
	make -C ./libft
	make -C ./printf