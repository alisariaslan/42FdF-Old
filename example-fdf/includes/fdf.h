/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:08:53 by oldurosi          #+#    #+#             */
/*   Updated: 2023/04/25 08:40:20 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include "./keys.h"
# include <math.h>
# define P_WIDTH  1920
# define P_HEIGHT 1080
# define ALTI_ZOOM 10
# define MAX_ZOOM 5
# define MAGNIFY 2

typedef	struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef	struct	s_map
{
	int		**values;
	int		length;
	int		breadth;
	int		coord_x;
	int		coord_y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
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
	t_mlx	mlx;
	t_map	map;
	t_image	image;
	t_color	color;
}				2662t_fdf;

void			read_lines(char *argv0, t_fdf *fdf);
int				fdf_draw(t_fdf *fdf);
void			nomalize_map(t_fdf *fdf);
void			get_values(t_fdf *fdf, int x, int y, char *line);
void			validate_lines(char *line);
int				count_values(char *line);
void			mix_color(t_fdf *fdf);
void			print_string(t_fdf *fdf);
void			drawing_to_display(t_fdf *fdf);
int				char_count(char *argv, t_fdf *fdf);

#endif
