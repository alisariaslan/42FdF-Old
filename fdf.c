/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/03/13 23:10:08 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int keyboard_click(int key, p_vars *vars)
{
	printf("key: %d\n", key);
	if (key == L_KEY_ESC)
		red_cross(65307, vars);
	if (key == 'w')
	{
	}
	if (key == 's')
	{
	}
	if (key == 'd')
	{
	}
	if (key == 'a')
	{
	}
	return (key);
}

int red_cross(int key, void *vars)
{
	exit(0);
	return (key);
}

int draw_line(p_vars *vars, int x1, int y1, int x2, int y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	float slope = (dx == 0) ? 0 : dy / dx; // Eğim sıfır ise slope 0 olarak ayarlanır
	float y = y1;
	float x = x1;
	float temp;

	if (fabs(dx) > fabs(dy))
	{
		if (x2 < x1)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
			y1 = y2;
		}
		y = y1;
		x = x1;
		while (x < x2)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, WHITE);
			y += slope * (y2 > y1 ? 1 : -1); // slope * 1 veya -1 olarak ayarlanır
			x++;
		}
	}
	else
	{
		if (y2 < y1)
		{
			temp = y1;
			y1 = y2;
			y2 = temp;
			x1 = x2;
		}
		x = x1;
		y = y1;
		while (y < y2)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, WHITE);
			x += (slope == 0) ? 0 : 1 / slope; // Eğim sıfır ise x değeri sabit kalır
			y++;
		}
	}
	return 0;
}

int draw_skeleton(p_vars *vars, p_skeleton *start)
{
	p_skeleton *temp = start;
	while (temp)
	{
		if (temp->next)
		{
			draw_line(vars, temp->x, temp->y, temp->next->x, temp->next->y);
		}
		temp = temp->next;
	}
	return 0;
}

int draw_body(p_vars *vars, p_skeleton ***body)
{
	
	int b = 0;
	int r = 0;
	while (body[b])
	{
		r =0;
		while (body[b][r])
		{
			draw_skeleton(vars, body[b][r]);
			r++;
		}
		b++;
	}
	
}

int add_skeleton(p_skeleton *start, int x, int y, int z)
{
	p_skeleton *temp;
	p_skeleton *new;

	temp = start;

	while (temp)
	{
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	new = (p_skeleton *)malloc(sizeof(p_skeleton));
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = 0;

	temp->next = new;
}

p_skeleton *init_skeleton(int x, int y, int z)
{
	p_skeleton *head;

	head = (p_skeleton *)malloc(sizeof(p_skeleton));
	head->x = x;
	head->y = y;
	head->z = z;
	head->next = 0;
	return head;
}

int x_point_counter(char *file)
{
	int count = 0;
	int i = 0;
	int fd = open(file, O_RDONLY);

	char *text = get_next_line(fd);
	while (text[i])
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			while (text[i] >= '0' && text[i] <= '9')
				i++;
			count++;
		}
		else
			i++;
	}
	close(fd);
	free(text);
	return count;
}

int y_point_counter(char *file)
{
	int count = 0;
	int fd = open(file, O_RDONLY);
	char *text = get_next_line(fd);
	void *temp;
	while (text != 0)
	{
		count++;
		temp = text;
		text = get_next_line(fd);
		free(temp);
	}
	close(fd);
	return count;
}

p_skeleton ***build_skeleton(p_vars *vars, char *file, int row_size, int column_size)
{

	p_skeleton ***body = (p_skeleton ***)malloc(sizeof(p_skeleton **) * 2 + 1);
	p_skeleton **rows = (p_skeleton **)malloc(sizeof(p_skeleton) * row_size + 1);
	p_skeleton **columns = (p_skeleton **)malloc(sizeof(p_skeleton) * column_size + 1);

	body[0] = rows;
	body[1] = columns;
	body[2] = 0;

	int x_offset = vars->width / row_size;
	int y_offset = vars->height / column_size;

	int i = 0;
	int ri = 0;
	int ci = 0;
	int x_now = 0;
	int y_now = 0;

	int fd = open(file, O_RDONLY);
	char *line = get_next_line(fd);
	char **chars = ft_split(line, ' ');

	while (line)
	{
		i = 0;
		x_now = 0;
		while (chars[i])
		{
			if(ri == 0)
			{
				columns[i] = init_skeleton(x_now,y_now,0);
			} else{
				add_skeleton(columns[i],x_now,y_now,0);
			}
				
			if (i == 0) 
				rows[ri] = init_skeleton(x_now, y_now, 0);
			else
				add_skeleton(rows[ri], x_now, y_now, 0);
			x_now += x_offset;
			i++;
		}
		line = get_next_line(fd);
		if(line)
			chars = ft_split(line, ' ');
		y_now += y_offset;
		ri++;
	}

	return body;
}

int main(int argc, char **argv)
{
	p_vars vars;
	p_skeleton ***body;

	vars.width = 1280;
	vars.height = 720;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "42 FdF by Msariasl");

	int xpc = x_point_counter(argv[1]);
	int ypc = y_point_counter(argv[1]);
	body = build_skeleton(&vars, argv[1], xpc, ypc);

	printf("xpc: %d\n", xpc);
	printf("ypc: %d\n", ypc);

	/*
	void *img_ptr = mlx_new_image(vars.mlx,400,400);
	int bits_per_pixel;
	int size_line;
	int endian;
	char *img_data = mlx_get_data_addr(img_ptr,&bits_per_pixel,&size_line,&endian);
	int color = 0xFFFFFFFF;
	for (int x = 0; x < 400; x++)
	{
		int y = x;
		int pixel_index = (y * size_line) + (x * (bits_per_pixel / 8));
		*(int *)(img_data + pixel_index) = color;
	}
	mlx_put_image_to_window(vars.mlx,vars.win,img_ptr,0,0);
	printf("\nbpp: %d sl: %d end: %d\n",bits_per_pixel,size_line,endian);
	*/

	// draw_skeleton(&vars, &start);
	draw_body(&vars, body);

	mlx_key_hook(vars.win, keyboard_click, &vars);
	mlx_hook(vars.win, ON_DESTROY_UBUNTU, 0, red_cross, 0);
	mlx_loop(vars.mlx);

	return (0);
}
