/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:33:33 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/11 00:53:38 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(tt_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line_x(int start_x,int end_x,int y, int color, t_vars *vars)
{
	if(start_x<end_x)
	{
		while (start_x<end_x)
		{
			start_x++;
			mlx_pixel_put(vars->mlx,vars->win,start_x,y,color);
		}
		
	} else {
		while (start_x>end_x)
		{
			start_x--;
			mlx_pixel_put(vars->mlx,vars->win,start_x,y,color);
		}
	}
	return 0;
}

int draw_line_y(int start_y,int end_y,int x, int color, t_vars *vars)
{
	if(start_y<end_y)
	{
		while (start_y<=end_y)
		{
			start_y++;
			mlx_pixel_put(vars->mlx,vars->win,x,start_y,color);
		}
		
	} else {
		while (start_y>=end_y)
		{
			start_y--;
			mlx_pixel_put(vars->mlx,vars->win,x,start_y,color);
		}
	}
	return 0;
}