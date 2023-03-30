/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/03/30 22:54:37 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_program(char *closing_text,int exit_code)
{
	ft_printf("\n\033[03;33m%s\n",closing_text);
	exit(exit_code);
}

void		init_program(char *argv1, t_fdf *fdf)
{
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		close_program("Malloc fail!",75);
	
		
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
