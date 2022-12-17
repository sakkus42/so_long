NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit
MLX = ./minilibx/libmlx.a
LIBPR = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): *.o $(MLX) $(LIBPR)
	$(CC) $(FLAGS) -o $(NAME) *.o $(MLX) $(LIBPR) $(FREAMS)

*.o: *.c
	$(CC) $(FLAGS) -c *.c gnl/*.c

$(MLX):
	@make -C ./minilibx

$(LIBPR):
	@make -C ./ft_printf

clean:
	rm -f *.o
	@make clean -C ./ft_printf
	@make clean -C ./minilibx

fclean: clean
	rm -f so_long
	@make fclean -C ./ft_printf

re:fclean all
