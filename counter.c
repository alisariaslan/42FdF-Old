/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:54:40 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/20 12:06:32 by msariasl         ###   ########.fr       */
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
		exit_program(1,"Error! Map opening error occured");
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
		else {
			ft_printf("\nError Target: %s\nError Row: %d\nExpected Count: %d\nError Count: %d",file,rows+1,columns,length);
			exit_program(1,"Error! This map has different char counts");
		}
		free(line);
		line = get_next_line(fd);
	}
	if(rows<4 || length <4)
			exit_program(1,"Error! This map is smaller than 3x3 area");
	
	if(close(fd)<0)
		exit_program(1,"Error! Map closing error occured");
	fdf->map.line_count = length;
	return rows;
}