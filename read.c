/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:33:18 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/30 22:35:01 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		input_lst(char **line, int fd)
{
	char	*line;
	char	**line_split;
	int		len;
	int		count;
	int		status;

	len = 0;
	while ((status = get_next_line(fd, &line)))
	{
		line_split = ft_strsplit(line, ' ');
		free(line);
		count = fdf_count_row(line_split);
		if (!count || status < 0)
			return (0);
		else if (!len)
			len = count;
		else if (count != len)
			return (0);
		add_line(lst, line_split);
	}
	return (len);
}

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
        printf("%3s", z[i]);
        free(z[i]);
        i++;
    }
    free(z);
}


// void read_file(char *file_name, t_fdf *data)
// {
//     int fd;
//     char *line;
//     int i;
    
//     data->height = get_height(file_name);
//     data->width = get_width(file_name);
//     data->z_map = (int **)malloc(sizeof(int*) * (data->height + 1));
//     i = 0;
//     while (i <= data->height)
//         data->z_map[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
//     fd = open(file_name, O_RDONLY, 0);
//     i = 0;
//     while (get_next_line(fd, &line))    
//     {
//         fill_map(data->z_map[i], line);
//         free(line);
//         i++;
//     }
//     close(fd);
//     data->z_map[i] = NULL;
// }
// void read_file(char *file_name, t_map *mp)
// {
//     int fd;
//     char *line;
//     int i;
//     int **z_map;
    
//     mp->height = get_height(file_name);
//     mp->width = get_width(file_name);
//     z_map = (int**)malloc(sizeof(int*) * (mp->height + 1));
//     arr = (t_point**)malloc(sizeof(t_point*) * (mp->height + 1));
//     i = 0;
//     while (i <= mp->height)
//        z_map[i++] = (int*)malloc(sizeof(int) * (mp->width + 1));
//     fd = open(file_name, O_RDONLY, 0);
//     i = 0;
//     while (get_next_line(fd, &line))    
//     {
//         fill_map(z_map[i], line);
//         free(line);
//         i++;
//         printf("\n");
//     }
//     close(fd);
//     z_map[i] = NULL;
//     mp->z_map = z_map;
// }

void read_file(char *file_name, t_map *mp)
{
    int fd;
    char *line;
    int i;
    int **z_map;
    t_point **ar;
    
    i = 0;
    mp->height = get_height(file_name);
    mp->width = get_width(file_name);
    fd = open(file_name, O_RDONLY, 0);
    arr = (t_point**)malloc(sizeof(t_point*) * (mp->height + 1));
    while (i < height);
     (get_next_line(fd, &line))    
    {
        fill_map(z_map[i], line);
        free(line);
        i++;
        printf("\n");
    }
    close(fd);
    z_map[i] = NULL;
    mp->z_map = z_map;
}
