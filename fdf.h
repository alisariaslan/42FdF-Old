/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:46 by ali               #+#    #+#             */
/*   Updated: 2023/03/11 20:45:57 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "minilibx-macos/mlx.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>


typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct ss_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} tt_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25
};

enum{
	KEY_ESCAPE = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

int			matoi(char *arg);
char		*itoam(int n);
int			mrintf(char *str, ...);
int			char_counter(char *chars);
int			step_counter(int n);
void		writechar(char c);
void		writemy(char *s);
void	my_mlx_pixel_put(tt_data *data, int x, int y, int color);
int draw_line_x(int start_x,int end_x,int y, int color, t_vars *vars);
int draw_line_y(int start_y,int end_y,int x, int color, t_vars *vars);
void draw_square(int x, int y,int size,t_vars *vars);
void	draw_gradient_square(int x, int y, int size, t_vars *vars,
		int start_color, int end_color);
#endif