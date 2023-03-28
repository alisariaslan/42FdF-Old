/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:46 by ali               #+#    #+#             */
/*   Updated: 2023/03/28 12:38:17 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_NAME "42 FdF by Msariasl"

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void *img_ptr; // img'nin işaretçisi
	char *addr;    // img'nin başlangıç adresi
	int bpp;       // her pikselde kaç bit veri olduğunu belirtir
	int size_line; // her satırın bellekte kaç byte alanda saklandığını belirtir
	int endian;    // verilerin bellekte nasıl saklandığını belirtir
	int		width;
	int		height;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			p_vars;

enum		X11_EVENTS
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY_MAC = 17,
	ON_DESTROY_UBUNTU = 33,
	ON_RESIZE = 25,

};

enum		KEYS
{
	KEY_ESC_MAC = 53,
	KEY_ESC_UBUNTU = 65307
};

enum		COLORS
{
	WHITE = 0xFFFFFFFF,
	BLACK = 0xFF000000,
	RED = 0xFFFF0000,
	GREEN = 0xFF00FF00,
	BLUE = 0xFF0000FF
};

int			exit_button(int key, void *vars);
int			keyboard_click(int key, p_vars *vars);

#endif