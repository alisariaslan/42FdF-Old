/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:54:40 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/02 03:56:09 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_words(char *text, char divider)
{
	int n;
	char **split;

	n = 0;
	split = ft_split(text, divider);
	while(*split)
	{
		n++;
		split++;
	}
	return (n);
}

int		count_lines(char *file, t_fdf *fdf)
{
	int rows;
	int columns;
	int length;
	int fd;
	char *line;
	
	fd = open(file,O_RDONLY);
	if(fd <= 0)
		close_program("Map Open Error!",0);
	rows = 0;
	columns = 0;
	line = get_next_line(fd);
	while(line)
	{
		if(*line == 0)
			break;
		ft_printf("%s\n",line);

		length =  count_words(line,' ');


		line = get_next_line(fd);
	}
	
}