/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:38:35 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/24 22:17:21 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_fd(int fd)
{
	if (fd <= 0)
		exit_program(1, "Error! Map opening error occured");
	return fd;
}

void	show_invalid_file_input(char *argv0)
{
	ft_printf("\n\033[03;33mError: Your file input is invalid!\n");
	ft_printf("\033[03;33mYou can use like that -> \033[0m");
	ft_printf("%s map.fdf\n\n", argv0);
}

void	how_to_control(void)
{
	ft_printf("\n\033[03;33mMAP CONTROLS:");
	ft_printf("\n\033[03;33mESC	-> Exit");
	ft_printf("\n\033[03;33mR  	-> Reset");
	ft_printf("\n\033[03;33mC	-> Color");
	ft_printf("\n\033[03;33mQ, A	-> Zoom");
	ft_printf("\n\033[03;33mW, S	-> Altitude ");
	ft_printf("\n\033[03;33mE	-> View");
	ft_printf("\n\033[03;33mArrow Keys -> Move\n\n");
}