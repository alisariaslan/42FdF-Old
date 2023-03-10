/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/03/11 02:02:42 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	mouse_click_mask(int select, int x, int y, t_vars *vars)
{
	if(select == 1)
	{
		int size = 50;
		draw_gradient_square(x-size/2,y-size/2,size,vars,0x00FF00,0x0000FF);
	}

	return (0);
}

int	draw_next_frame(t_vars *vars)
{
	int size = 10;
	static int pos_x = 50;
	static int pos_y = 50;

	mlx_clear_window(vars->mlx, vars->win);

	if(way_x==1 && way_y == 0)
	{
		draw_square(pos_x,pos_y,size,vars);
		pos_x+=size;
	}
	if(way_x==-1 && way_y == 0)
	{
		draw_square(pos_x,pos_y,size,vars);
		pos_x-=size;
	}
	if(way_x==0 && way_y == 1)
	{
		draw_square(pos_x,pos_y,size,vars);
		pos_y+=size;
	}
	if(way_x==0 && way_y == -1)
	{
		draw_square(pos_x,pos_y,size,vars);
		pos_y-=size;
	}

	return (0);
}

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "42 FdF by Msariasl");

	mlx_mouse_hook(vars.win, mouse_click_mask, &vars);



	//draw_square((1920 / 2) - (350 /2), (1080 / 2) - (350/2),350, &vars);
	//draw_gradient_square((1920 / 2) - (350 /2), (1080 / 2) - (350/2),350, &vars,0xFF0000,0x00FF00);
	mlx_loop_hook(vars.mlx, draw_next_frame, &vars);
	mlx_loop(vars.mlx);
}*/

#include "fdf.h"
#include <math.h>

typedef struct z_data
{
	void *mlx_ptr;
	void *win_ptr;
} k_data;

typedef struct s_point
{
	int x;
	int y;
	int z;
} t_point;

void draw_line(k_data *data, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx - dy;

	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void rotate_x(t_point cube_points[], double angle)
{
    // Küp noktalarını x ekseni etrafında döndürmek için bu fonksiyonu kullanıyoruz
    for (int i = 0; i < 8; i++)
    {
        int prev_y = cube_points[i].y;
        cube_points[i].y = cube_points[i].y * cos(angle) + cube_points[i].z * sin(angle);
        cube_points[i].z = -prev_y * sin(angle) + cube_points[i].z * cos(angle);
    }
}

void rotate_y(t_point *point, double angle)
{
	int prev_x = point->x;
	point->x = point->x * cos(angle) + point->z * sin(angle);
	point->z = -prev_x * sin(angle) + point->z * cos(angle);
}

void rotate_z(t_point *point, double angle)
{
	int prev_x = point->x;
	point->x = point->x * cos(angle) - point->y * sin(angle);
	point->y = prev_x * sin(angle) + point->y * cos(angle);
}

int win_exit_event(k_data *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(1);
	return (0);
}

const int x1 = 300;
const int x2 = 400;
t_point cube[8] = {
	{x1, x1, x1}, {x2, x1, x1}, {x2, x2, x1}, {x1, x2, x1}, {x1, x1, x2}, {x2, x1, x2}, {x2, x2, x2}, {x1, x2, x2}};

int keyboard_click(int key, k_data *vars)
{
	static double angle_x = 0;
	static double angle_y = 0;
	static double angle_z = 0;

	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(1);
	}

	if (key == KEY_W)
	{
		
			rotate_x(cube, angle_x);
		

		angle_x += 0.001;
		
	}
	if (key == KEY_S)
	{
		for (int i = 0; i < 8; i++)
		{

			rotate_x(&cube[i], angle_y);
			
		}
		angle_y += 0.01;
	}
	if (key == KEY_D)
	{
		for (int i = 0; i < 8; i++)
		{
			rotate_x(&cube[i], angle_x);
		}
		angle_x += 0.1;
	}
	if (key == KEY_A)
	{
		for (int i = 0; i < 8; i++)
		{
			rotate_x(&cube[i], angle_x);
		}
		angle_x -= 0.1;
	}
	return (key);
}

int draw_next_frame(k_data *data)
{
	
	draw_line(data, cube[0].x, cube[0].y, cube[1].x, cube[1].y);
	draw_line(data, cube[1].x, cube[1].y, cube[2].x, cube[2].y);
	draw_line(data, cube[2].x, cube[2].y, cube[3].x, cube[3].y);
	draw_line(data, cube[3].x, cube[3].y, cube[0].x, cube[0].y);

	draw_line(data, cube[4].x, cube[4].y, cube[5].x, cube[5].y);
	draw_line(data, cube[5].x, cube[5].y, cube[6].x, cube[6].y);
	draw_line(data, cube[6].x, cube[6].y, cube[7].x, cube[7].y);
	draw_line(data, cube[7].x, cube[7].y, cube[4].x, cube[4].y);

	draw_line(data, cube[0].x, cube[0].y, cube[4].x, cube[4].y);
	draw_line(data, cube[1].x, cube[1].y, cube[5].x, cube[5].y);
	draw_line(data, cube[2].x, cube[2].y, cube[6].x, cube[6].y);
	draw_line(data, cube[3].x, cube[3].y, cube[7].x, cube[7].y);

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	
	return (0);
}

int main(void)
{
	k_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Rotating Cube");

	mlx_key_hook(data.win_ptr, keyboard_click, &data);
	mlx_hook(data.win_ptr, ON_DESTROY, 1L << 22, win_exit_event, &data);
	mlx_loop_hook(data.mlx_ptr, draw_next_frame, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
