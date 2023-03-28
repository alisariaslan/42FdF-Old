/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/03/28 12:40:16 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(p_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
}

int	main(int argc, char **argv)
{
	p_vars	vars;

	init_window(&vars);
	mlx_key_hook(vars.win, keyboard_click, &vars);
	mlx_hook(vars.win, ON_DESTROY_UBUNTU, 0, exit_button, 0);
	mlx_loop(vars.mlx);
	return (0);
}
