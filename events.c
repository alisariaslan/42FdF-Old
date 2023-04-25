/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:36:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/25 09:54:53 by msariasl         ###   ########.fr       */
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
	if (key == 'k')
		fdf->map.angle_x += .1;
	else if (key == 'l')
		fdf->map.angle_x -= .1;
	else if (key == 'n')
		fdf->map.angle_y += .1;
	else if (key == 'm')
		fdf->map.angle_y -= .1;
	return (key);
}

static int	keyboard_click_part(int key, t_fdf *fdf)
{
	if (key == 'r')
	{
		fdf->map.coord_y = 0;
		fdf->map.coord_x = 0;
	}
	else if (key == 'c')
	{
		fdf->color.r = 100;
		fdf->color.g = 100;
		fdf->color.b = 100;
	}
	else if (key == 'g')
	{
		fdf->color.r = 0;
		fdf->color.g = 255;
		fdf->color.b = 0;
	}
	else if (key == 'b')
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
	else if (key == 'w')
		fdf->map.coord_y += 10;
	else if (key == 'a')
		fdf->map.coord_x += 10;
	else if (key == 's')
		fdf->map.coord_y -= 10;
	else if (key == 'd')
		fdf->map.coord_x -= 10;
	else if (key == 'q')
		fdf->map.scalin -= 1;
	else if (key == 'e')
		fdf->map.scalin += 1;
	else if (key == 't')
		fdf->map.z_value += 0.25;
	else if (key == 'y')
		fdf->map.z_value -= 0.25;
	else if (key == 'p')
		if (fdf->map.isometric++ % 2)
			fdf->map.angle_y *= 2;
	else
			fdf->map.angle_y *= 0.5;
	return (keyboard_click_part(key, fdf));
}
