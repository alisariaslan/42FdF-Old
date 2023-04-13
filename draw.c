/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:25:28 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/13 22:35:52 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawto_y_axis(void)
{
}

static void	drawto_x_axis(void)
{
}

static void	drawto_screen(void)
{
}

int	draw(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	fdf->mlx.img = mlx_new_image(fdf->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp,
			&fdf->image.size, &fdf->image.endian);
	while (fdf->map.char_count > y)
	{
		x = 0;
		while (fdf->map.line_count > x)
		{
			fdf->map.x0 = x;
			fdf->map.y0 = y;
			if (fdf->map.line_count > x + 1)
				drawto_x_axis();
			if (fdf->map.char_count > y + 1)
				;
			drawto_y_axis();
			x++;
		}
		y++;
	}
	drawto_screen();
	mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img);
	return (0);
}