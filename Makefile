NAME = fdf
MLX = minilibx-linux
FILES = *.c *.h
MLX_FILES = $(MLX)/*.c $(MLX)/*.h 
ARGS = -Wall -Wextra -Werror

$(NAME): $(FILES) $(MLX_FILES)
	gcc -c $(FILES) $(MLX_FILES) 
	gcc *.o -o $(NAME) /usr/local/include main.c -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all:
	make $(NAME)

clean:
	rm -rf *.o
	rm -rf *.gch

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

n:
	clear
	norminette -R CheckForbiddenSourceHeader