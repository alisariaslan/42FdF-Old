/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:33:33 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/11 00:27:57 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_square(int x, int y, int size, t_vars *vars)
{
	int	color;
	color = 0x0000FF00;
	int tx = x;
	int ty = y;
	
	while (y < ty+size)
	{
		x = tx;
		while (x < tx+size)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, color);		
			x++;
		}
		y++;
	}
}

void draw_gradient_square(int x, int y, int size, t_vars *vars, int start_color, int end_color) {
    int delta_red = ((end_color & 0xFF0000) - (start_color & 0xFF0000)) / size;
    int delta_green = ((end_color & 0x00FF00) - (start_color & 0x00FF00)) / size;
    int delta_blue = ((end_color & 0x0000FF) - (start_color & 0x0000FF)) / size;

    int color = start_color;
    int tx = x;
    int ty = y;

    while (y < ty + size) {
        x = tx;
        while (x < tx + size) {
            mlx_pixel_put(vars->mlx, vars->win, x, y, color);
            color += delta_red;
            color += delta_green & 0x00FF00;
            color += delta_blue & 0x0000FF;
            x++;
        }
        y++;
    }
}