NAME = fdf
MLX = minilibx

LIBFT = libft/libft.a

NAME_LINUX = $(NAME)-linux
MLX_LINUX = $(MLX)-linux
MLX_LINUX_AR = libmlx_Linux.a

NAME_MACOS = $(NAME)-mac
MLX_MACOS = $(MLX)-macos
MLX_MACOS_AR = libmlx.a

MLX_MACOS_ARGS = -framework OpenGL -framework AppKit
MLX_LINUX_ARGS = -lXext -lX11 -lm

ARGS = -Wall -Wextra -Werror

all: linux
	./$(NAME_LINUX) "maps/42.fdf"

build-libft:
	cd libft && make

mac: $(NAME_MACOS)

linux: $(NAME_LINUX)

$(MLX_MACOS_AR) : $(MLX_MACOS)/*.c $(MLX_MACOS)/*.m
	make -C ${MLX_MACOS}
	make build-libft

$(MLX_LINUX_AR) : $(MLX_LINUX)/*.c 
	make -C ${MLX_LINUX}
	make build-libft

$(NAME_MACOS): *.c $(MLX_MACOS_AR)
	gcc -c *.c
	gcc *.o $(MLX_MACOS)/$(MLX_MACOS_AR) $(LIBFT) -o $(NAME_MACOS) $(MLX_MACOS_ARGS)

$(NAME_LINUX): *.c $(MLX_LINUX_AR)
	gcc -c *.c
	gcc *.o $(MLX_LINUX)/$(MLX_LINUX_AR) $(LIBFT) -o $(NAME_LINUX) $(MLX_LINUX_ARGS)

clean:
	rm -rf *.o
	rm -rf $(MLX_MACOS)/*.o
	rm -rf $(MLX_LINUX)/*.o
	rm -rf *.gch

fclean: clean
	rm -rf $(NAME_LINUX)
	rm -rf $(NAME_MACOS)
	rm -rf $(MLX_MACOS)/$(MLX_MACOS_AR)
	rm -rf $(MLX_LINUX)/*.a

re: fclean all

n:
	clear
	norminette *.c -R CheckForbiddenSourceHeader
