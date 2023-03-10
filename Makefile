NAME = fdf
MLX_LINUX = minilibx_linux
MLX_MACOS = minilibx_macos
MLX_MACOS_AR = libmlx.a
MLX_ARGS = -framework OpenGL -framework AppKit
MY_FILES = *.c *.h
MLX_FILES = $(MLX)/*.c $(MLX)/*.h 
ARGS = -Wall -Wextra -Werror

all: $(NAME)

$(MLX_MACOS_AR) : $(MLX_MACOS)/*.c $(MLX_MACOS)/*.h $(MLX_MACOS)/*.m
	cd $(MLX_MACOS) && make

$(NAME): $(MY_FILES) $(MLX_MACOS_AR)
	gcc -c $(MY_FILES)
	gcc *.o $(MLX_MACOS)/$(MLX_MACOS_AR) -o $(NAME) $(MLX_ARGS)

clean:
	rm -rf *.o
	rm -rf $(MLX_MACOS)/*.o
	rm -rf *.gch

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX_MACOS)/$(MLX_MACOS_AR)

re: fclean all

n:
	clear
	norminette $(MY_FILES) -R CheckForbiddenSourceHeader 

start: all
	./$(NAME)