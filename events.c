/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:36:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/30 14:10:37 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_program(int n, char *text)
{
	if (n == 0)
		fc_printf("Safe Exit.\n\n", 0, 1, 0);
	else
		fc_printf(text, 1, 0, 0);
	exit(n);
}

static int	keyboard_click_part_sec(int key, t_fdf *fdf)
{
	if (key == KEY_K)
		fdf->map.angle_x += .1;
	else if (key == KEY_L)
		fdf->map.angle_x -= .1;
	else if (key == KEY_N)
		fdf->map.angle_y += .1;
	else if (key == KEY_M)
		fdf->map.angle_y -= .1;
	else if (key == KEY_P)
	{
		if (fdf->map.isometric++ % 2)
			fdf->map.angle_y *= 2;
		else
			fdf->map.angle_y *= 0.5;
	}
	return (key);
}

static int	keyboard_click_part(int key, t_fdf *fdf)
{
	if (key == KEY_R)
	{
		fdf->map.coord_y = 0;
		fdf->map.coord_x = 0;
	}
	else if (key == KEY_C)
	{
		fdf->color.r = 100;
		fdf->color.g = 100;
		fdf->color.b = 100;
	}
	else if (key == KEY_G)
	{
		fdf->color.r = 0;
		fdf->color.g = 255;
		fdf->color.b = 0;
	}
	else if (key == KEY_B)
	{
		fdf->color.r = 0;
		fdf->color.g = 0;
		fdf->color.b = 255;
	}
	return (keyboard_click_part_sec(key, fdf));
}

int	keyboard_click(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		exit_program(0, "!");
	else if (key == KEY_W)
		fdf->map.coord_y += 10;
	else if (key == KEY_A)
		fdf->map.coord_x += 10;
	else if (key == KEY_S)
		fdf->map.coord_y -= 10;
	else if (key == KEY_D)
		fdf->map.coord_x -= 10;
	else if (key == KEY_Q)
		fdf->map.scalin -= 1;
	else if (key == KEY_E)
		fdf->map.scalin += 1;
	else if (key == KEY_T)
		fdf->map.z_value += 0.25;
	else if (key == KEY_Y)
		fdf->map.z_value -= 0.25;
	return (keyboard_click_part(key, fdf));
}
