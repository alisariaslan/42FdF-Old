/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:46 by ali               #+#    #+#             */
/*   Updated: 2023/05/02 19:03:28 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define WIN_NAME "42 FdF by Msariasl"
# define ALTI_ZOOM 10
# define MAX_ZOOM 5
# define MAGNIFY 2

# include "input-linux.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_vars;

typedef struct s_img
{
	char			*data;
	int				size;
	int				endian;
	int				bpp;
}					t_img;

typedef struct s_map
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				**vals;
	int				char_count;
	int				line_count;
	int				coord_x;
	int				coord_y;
	int				scalin;
	int				isometric;
	double			z_value;
	double			angle_x;
	double			angle_y;
}					t_map;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_fdf
{
	t_vars			mlx;
	t_map			map;
	t_img			image;
	t_color			color;
}					t_fdf;


int					check_fd(int fd);
int					draw(t_fdf *fdf);
int					exit_program(int n, char *text);
void				read_map(char *file, t_fdf *fdf, int x, int y);
int					count_lines(char *file, t_fdf *fdf,int rows,int columns);
int					count_words(char *text, char divider);
int					keyboard_click(int key, t_fdf *fdf);
void				show_invalid_file_input(char *argv0);
void				how_to_control(void);
void 				fc_printf(char *text, int r, int g, int y);
void				print_red (void);
void				print_green(void);
void				print_yellow(void);
void				print_color_reset(void);

#endif