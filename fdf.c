/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/03/30 20:11:20 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
}

void		show_invalid_file_input(char *argv0)
{
	ft_printf("\n\033[03;33mError: Your file input is invalid!\n");
	ft_printf("\033[03;33mYou can use like that -> \033[0m");
	ft_printf("%s\n\n",argv0);
}

void		how_to_control()
{
	ft_printf(" map.fdf\n");
	ft_printf("\033[1;35mControls:\n\033[0m");
	ft_printf("\t[Esc]        -> Exit the program.\n");
	ft_printf("\t[R]          -> Reset the map.\n");
	ft_printf("\t[E]          -> Color the map!.\n");
	ft_printf("\t[Q][A]       -> Zoom in and zoom out.\n");
	ft_printf("\t[W][S]       -> Altitude \n");
	ft_printf("\t[C]          -> Change the camera (isometric <-> plain).\n");
	ft_printf("\t[⬆️][⬇️][⬅️][➡️] -> Move the map.\n");
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	/*
	if (argc == 2)
		init_program(argv[1], fdf);
	else*/
		show_invalid_file_input(argv[0]);
	return (0);
}

/*
void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_window(&vars);
	mlx_key_hook(vars.win, keyboard_click, &vars);
	mlx_hook(vars.win, EVENT_ON_DESTROY, 0, exit_button, 0);
	mlx_loop(vars.mlx);
	return (0);
}
*/
