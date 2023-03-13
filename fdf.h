/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:46 by ali               #+#    #+#             */
/*   Updated: 2023/03/12 23:09:05 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF

#include "minilibx-linux/mlx.h"
#include "getnextline/get_next_line.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>

typedef struct s_vars
{
	void *mlx;
	void *win;
	int width;
	int height;
} p_vars;

typedef struct s_skeleton
{
	int x;
	int y;
	int z;
	struct s_skeleton * next;
} p_skeleton;

enum X11_EVENTS
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25,

	ON_DESTROY_UBUNTU = 33
};

enum MAC_KEYS
{
	M_KEY_ESC = 53
};

enum LINUX_KEYS
{
	L_KEY_ESC = 65307
};

enum COLORS
{
	WHITE = 0xFFFFFFFF,
	BLACK = 0xFF000000,
	RED = 0xFFFF0000,
	GREEN = 0xFF00FF00,
	BLUE = 0xFF0000FF
};

int matoi(char *arg);
char *itoam(int n);
int mrintf(char *str, ...);
int char_counter(char *chars);
int step_counter(int n);
void writechar(char c);
void writemy(char *s);

int red_cross(int key, void *vars);

char	**ft_split(const char *str, char c);
#endif