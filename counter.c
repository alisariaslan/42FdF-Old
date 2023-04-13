/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:54:40 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/13 22:35:52 by msariasl         ###   ########.fr       */
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
		close_program("counter.c -> Map Open Error!",0);
	rows = 0;
	columns = 0;
	line = get_next_line(fd);
	while(line)
	{
		if(*line == 0)
			break;
		if(WRITE_MAP)
			ft_printf("\033[0;32m%s\n",line);
		length =  count_words(line,' ');
		if(columns == 0)
			columns = length;
		if(columns==length)
			rows++;
		else
			close_program("counter.c -> Error! This map has different column counts.",0);
		free(line);
		line = get_next_line(fd);
	}
	if(close(fd)<0)
		close_program("counter.c -> Map CLOSE Error!",0);
	fdf->map.line_count = length;
	return rows;
}