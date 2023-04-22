/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:36:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/22 09:56:24 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_program(int n, char *text)
{
	if (*text != '!')
		ft_printf("\n\033[03;33m%s\n", text);
	else
		ft_printf("%s\n\n", "Safe Exit.");
	exit(n);
}

int	keyboard_click(int key, t_fdf *fdf)
{
	//ft_printf("key: %d\n", key);
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
		fdf->map.angle_y *= (fdf->map.isometric++ % 2) ? 0.5 : 2;
	else if (key == 'r') {
		fdf->map.coord_y = 0;
		fdf->map.coord_x = 0;
	} else if (key == 'c')
	{
		fdf->color.r = 255;
		fdf->color.g = 255;
		fdf->color.b = 255;
	}
	return (key);
}
