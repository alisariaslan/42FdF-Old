/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:46 by ali               #+#    #+#             */
/*   Updated: 2023/04/02 03:56:13 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_NAME "42 FdF by Msariasl"
# define ALTI_ZOOM 10
# define MAX_ZOOM 5
# define MAGNIFY 2

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "input-linux.h"

# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

typedef struct	s_img
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_img;

typedef	struct	s_map
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		**vals;
	int		len;
	int		breadth;
	int		coord_x;
	int		coord_y;
	int		scalin;
	int		isometric;
	double	z_value;
	double	angle_x;
	double	angle_y;
}				t_map;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_fdf
{
	t_vars	mlx;
	t_map	map;
	t_img	image;
	t_color	color;
}				t_fdf;

void	close_program(char *closing_text, int exit_code);
void	read_map(char *file, t_fdf *fdf);
int		count_lines(char *file, t_fdf *fdf);
int		count_words(char *text, char divider);

int			exit_button(int key, void *vars);
int			keyboard_click(int key, t_vars *vars);

void		show_invalid_file_input(char *argv0);
void		how_to_control();

#endif