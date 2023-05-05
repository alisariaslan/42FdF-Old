# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 18:50:27 by msariasl          #+#    #+#              #
#    Updated: 2023/05/05 12:42:45 by msariasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
MLX = minilibx
AR = libmlx.a

LIBFT = libft/libft.a

NAME_LINUX = $(NAME)-linux
MLX_LINUX = $(MLX)-linux
MLX_LINUX_AR = $(AR)

NAME_MACOS = $(NAME)-macos
MLX_MACOS = $(MLX)-macos
MLX_MACOS_AR = $(AR)

MLX_MACOS_ARGS = -framework OpenGL -framework AppKit
MLX_LINUX_ARGS = -lXext -lX11 -lm
NORM_ARGS = -Wall -Wextra -Werror

all: macos
	./$(NAME_MACOS) "maps/42.fdf"

macos: $(NAME_MACOS)

linux: $(NAME_LINUX)

$(NAME_MACOS): *.c
	make -C ${MLX_MACOS}
	make -C libft
	gcc -c *.c
	gcc *.o $(MLX_MACOS)/$(MLX_MACOS_AR) $(LIBFT) -o $(NAME_MACOS) $(MLX_MACOS_ARGS) $(NORM_ARGS)

$(NAME_LINUX): *.c $(MLX_LINUX_AR)
	make -C ${MLX_LINUX}
	make -C libft
	gcc -c *.c
	gcc *.o $(MLX_LINUX)/$(MLX_LINUX_AR) $(LIBFT) -o $(NAME_LINUX) $(MLX_LINUX_ARGS) $(NORM_ARGS)

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