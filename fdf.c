/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/04/13 22:35:52 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_program(char *closing_text, int exit_code)
{
	ft_printf("\n\033[03;33m%s\n", closing_text);
	exit(exit_code);
}

void	map_set(t_fdf *fdf)
{
	fdf->map.coord_x = 0;
	fdf->map.coord_y = 0;
	fdf->map.z_value = 1;
	fdf->map.angle_x = cos(M_PI / 3);
	fdf->map.angle_y = fdf->map.angle_x * sin(M_PI / 6);
	if (fdf->map.line_count > fdf->map.char_count)
	{
		fdf->map.scalin = ceil((WIN_WIDTH / fdf->map.line_count) + MAGNIFY);
	}
	else
	{
		fdf->map.scalin = ceil((WIN_HEIGHT / fdf->map.char_count) + MAGNIFY);
	}
	fdf->map.isometric = 1;
	fdf->color.r = 0x4F;
	fdf->color.g = 0x4F;
	fdf->color.b = 0x4F;
}

void	init_program(char *argv1, t_fdf *fdf)
{
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		close_program("fdf.c -> Malloc fail!", 0);
	read_map(argv1, fdf);
	map_set(fdf);
	fdf->mlx.mlx = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.mlx,WIN_WIDTH,WIN_HEIGHT,"42 Fdf by Msariasl");
	mlx_hook(fdf->mlx.win,2,3,keyboard_click,fdf);
	mlx_loop_hook(fdf->mlx.mlx,draw,fdf);
	mlx_loop(fdf->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
		init_program(argv[1], fdf);
	else
		show_invalid_file_input(argv[0]);
	return (0);
}
