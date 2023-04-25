/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:54:40 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/25 09:47:18 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *text, char divider)
{
	int		n;
	char	**split;

	n = 0;
	split = ft_split(text, divider);
	while (split[n])
	{
		free(split[n]);
		n++;
	}
	free(split[n]);
	free(split);
	return (n);
}

static void	warn_before_exit(char *file, int rows, int cols, int len)
{
	print_yellow();
	ft_printf("\nError Target: %s\nError Row: %d\nExpected Count: \
					%d\nError Count: %d", file, rows + 1, cols, len);
	print_color_reset();
	exit_program(1, "Error! This map has different char counts");
}

int	count_lines(char *file, t_fdf *fdf, int rows, int columns)
{
	int		wc;
	int		fd;
	char	*line;

	fd = check_fd(open(file, O_RDONLY));
	line = get_next_line(fd);
	while (line)
	{
		wc = count_words(line, ' ');
		if (columns == 0)
			columns = wc;
		if (columns == wc)
			rows++;
		else
			warn_before_exit(file, rows, columns, wc);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (rows < 4 || wc < 4)
		exit_program(1, "Error! This map is smaller than 3x3 area");
	check_fd(close(fd));
	fdf->map.char_count = wc;
	return (rows);
}
