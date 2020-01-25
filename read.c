/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:33:18 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/24 07:47:03 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int get_height(char *file_name)
{
    char *line;
    int fd;
    int height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

static int ft_widthcounter(char *line, char c)
{
    int q;
	int flag;

	q = 0;
	flag = 0;
	while (*line)
	{
		if (!flag && *line != c)
		{
			flag = 1;
			q++;
		}
		if (flag && *line == c)
			flag = 0;
		line++;
	}
	return (q);
}

static int get_width(char *file_name)
{
    int width;
    int fd;
    char *line;

    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_widthcounter(line, ' ');
    free(line);
    close(fd);
    return (width);

}

static void fill_map(int *z_line, char *line)
{
    char **z;
    int i = 0;

    z = ft_strsplit(line, ' ');
    while (z[i])
    {
        z_line[i] = ft_atoi(z[i]);
        free(z[i]);
        i++;
    }
    free(z);
}

void read_file(char *file_name, t_fdf *data)
{
    int fd;
    char *line;
    int i;
    
    data->height = get_height(file_name);
    data->width = get_width(file_name);
    data->z_map = (int **)malloc(sizeof(int*) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_map[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))    
    {
        fill_map(data->z_map[i], line);
        free(line);
        i++;
    }
    close(fd);
    data->z_map[i] = NULL;
}