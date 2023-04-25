NAME = fdf
MLX = minilibx
OS = linux
AR = libmlx

LIBFT = libft/libft.a

NAME_LINUX = $(NAME)-$(OS)
MLX_LINUX = $(MLX)-$(OS)
MLX_LINUX_AR = $(AR).a

NAME_MACOS = $(NAME)-macos
MLX_MACOS = $(MLX)-macos
MLX_MACOS_AR = $(AR).a

MLX_MACOS_ARGS = -framework OpenGL -framework AppKit
MLX_LINUX_ARGS = -lXext -lX11 -lm

ARGS = -Wall -Wextra -Werror

all:$(OS)
	./$(NAME_LINUX) "maps/42.fdf"

build-libft:
	cd libft && make

macos: $(NAME_MACOS)

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
	rm -rf libft/*.o
	rm -rf *.gch

fclean: clean
	rm -rf $(NAME_LINUX)
	rm -rf $(NAME_MACOS)
	rm -rf $(MLX_MACOS)/$(MLX_MACOS_AR)
	rm -rf $(MLX_LINUX)/*.a
	rm -rf $(LIBFT)

re: fclean all

n:
	clear
	norminette *.c -R CheckForbiddenSourceHeader

leak: $(NAME_LINUX)
	valgrind --leak-check=yes --log-file=valgrind.rpt ./$(NAME_LINUX) "maps/42.fdf"
	cat valgrind.rpt