/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:25:28 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/20 12:10:53 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel_helper(t_fdf *fdf, int x, int y, double dchang)
{
	int	point;

	if ((x > 0 && y > 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		point = (x * 4) + (y * WIN_WIDTH * 4);
		fdf->image.data[point] = fdf->color.r;
		fdf->image.data[point + 1] = fdf->color.g;
		fdf->image.data[point + 2] = fdf->color.b;
		
	}
}

static void	draw_pixel(t_fdf *fdf)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	dchang;

	x = fdf->map.x0;
	y = fdf->map.y0;
	dx = fdf->map.x1 - fdf->map.x0;
	dy = fdf->map.y1 - fdf->map.y0;
	dchang = sqrt((pow(dx, 2)) + (pow(dy, 2)));
	dx /= dchang;
	dy /= dchang;
	while (dchang > 0)
	{
		draw_pixel_helper(fdf, x, y, dchang);
		x += dx;
		y += dy;
		dchang -= 1;
	}
}

static void	drawto_x_axis(t_fdf *fdf, int x, int y)
{
	int		dx;
	int		dy;

	dx = x - fdf->map.line_count / 2;
	dy = y - fdf->map.char_count / 2;
	fdf->map.x0 = fdf->map.angle_x * (dx - dy) * fdf->map.scalin;
	fdf->map.y0 = fdf->map.angle_y * (dx + dy) * fdf->map.scalin;
	fdf->map.y0 -= fdf->map.vals[y][x] * fdf->map.z_value;
	fdf->map.x1 = fdf->map.angle_x * ((dx + 1) - dy) * fdf->map.scalin;
	fdf->map.y1 = fdf->map.angle_y * ((dx + 1) + dy) * fdf->map.scalin;
	fdf->map.y1 -= fdf->map.vals[y][x + 1] * fdf->map.z_value;
	fdf->map.x0 += (WIN_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y0 += (WIN_HEIGHT / 2) + fdf->map.coord_y;
	fdf->map.x1 += (WIN_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y1 += (WIN_HEIGHT / 2) + fdf->map.coord_y;
	draw_pixel(fdf);
}

static void	drawto_y_axis(t_fdf *fdf, int x, int y)
{
	int		dx;
	int		dy;

	dx = x - fdf->map.line_count / 2;
	dy = y - fdf->map.char_count / 2;
	fdf->map.x0 = fdf->map.angle_x * (dx - dy) * fdf->map.scalin;
	fdf->map.y0 = fdf->map.angle_y * (dx + dy) * fdf->map.scalin;
	fdf->map.y0 -= fdf->map.vals[y][x] * fdf->map.z_value;
	fdf->map.x1 = fdf->map.angle_x * (dx - (dy + 1)) * fdf->map.scalin;
	fdf->map.y1 = fdf->map.angle_y * (dx + (dy + 1)) * fdf->map.scalin;
	fdf->map.y1 -= fdf->map.vals[y + 1][x] * fdf->map.z_value;
	fdf->map.x0 += (WIN_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y0 += (WIN_HEIGHT / 2) + fdf->map.coord_y;
	fdf->map.x1 += (WIN_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y1 += (WIN_HEIGHT / 2) + fdf->map.coord_y;
	draw_pixel(fdf);
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
				drawto_x_axis(fdf, x, y);
			if (fdf->map.char_count > y + 1)
				drawto_y_axis(fdf,x,y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img);
	return (0);
}