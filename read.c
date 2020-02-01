/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:33:18 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/31 15:49:30 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_lstcount(t_list *lst)
{
	size_t count;

	count = 0;
	while (lst)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}

void	add_line(t_list **lst, char **line_split)
{
	t_list *new;

	if (!*lst)
	{
		*lst = ft_lstnew(NULL, 0);
		(*lst)->content = (void*)line_split;
	}
	else
	{
		new = (t_list*)ft_memalloc(sizeof(t_list));
		new->content = (void*)line_split;
		ft_lstappend(*lst, new);
	}
}

int		fdf_count_width(char **line_split)
{
	int i;

	i = 0;
	while (line_split[i])
		i++;
	return (i);
}

int		input_lst(t_list **lst, int fd)
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
		count = fdf_count_width(line_split);
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

// static int get_height(char *file_name)
// {
//     char *line;
//     int fd;
//     int height;

//     fd = open(file_name, O_RDONLY, 0);
//     height = 0;
//     while (get_next_line(fd, &line))
//     {
//         height++;
//         free(line);
//     }
//     close(fd);
//     return (height);
// }

// static int ft_widthcounter(char *line, char c)
// {
//     int q;
// 	int flag;

// 	q = 0;
// 	flag = 0;
// 	while (*line)
// 	{
// 		if (!flag && *line != c)
// 		{
// 			flag = 1;
// 			q++;
// 		}
// 		if (flag && *line == c)
// 			flag = 0;
// 		line++;
// 	}
// 	return (q);
// }

// static int get_width(char *file_name)
// {
//     int width;
//     int fd;
//     char *line;

//     fd = open(file_name, O_RDONLY, 0);
//     get_next_line(fd, &line);
//     width = ft_widthcounter(line, ' ');
//     free(line);
//     close(fd);
//     return (width);

// }

// static void fill_map(int *z_line, char *line)
// {
//     char **z;
//     int i = 0;

//     z = ft_strsplit(line, ' ');
//     while (z[i])
//     {
//         z_line[i] = ft_atoi(z[i]);
//         printf("%3s", z[i]);
//         free(z[i]);
//         i++;
//     }
//     free(z);
// }


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


void	lst_map(t_map *mp, t_list *lst)
{
	t_point	**ar;
	t_list	*lst_head;
	int		rows;
	int		i;
	int		j;

	lst_head = lst;
	rows = ft_lstcount(lst);
	mp->height = rows;
	ar = (t_point**)ft_memalloc(sizeof(t_point*) * rows);
	i = -1;
	while (lst)
	{
		ar[++i] = (t_point*)ft_memalloc(sizeof(t_point) * mp->width);
		j = -1;
		while (j < mp->width - 1)
		{
			ar[i][++j].y = i;
			//printf("%3d", ar[i][j].y);
			ar[i][j].x = j;
			ar[i][j].z = ft_atoi(((char**)lst->content)[j]);
			printf("%3d", ar[i][j].z);
		}
		printf("\n");
		lst = lst->next;
	}
	fdf_free_lst(lst_head);
	mp->height = rows;
	mp->z_map = ar;
}

void	fdf_free_lst(t_list *lst)
{
	int		i;
	t_list	*temp;

	while (lst)
	{
		i = 0;
		while (((char**)lst->content)[i])
			free(((char**)lst->content)[i++]);
		free(lst->content);
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void read_file(char *file_name, t_map *mp)
{
    int fd;
	int l;
    t_list *lst;
	
	lst = 0;
    fd = open(file_name, O_RDONLY, 0);

    if (!(l = input_lst(&lst, fd)))
		dead("Error");
	mp->width = l;
	lst_map(mp, lst);
	mp->max_z = get_map_max(mp);
	mp->min_z = get_map_min(mp);
    // arr = (t_point**)malloc(sizeof(t_point*) * (mp->height + 1));
    // while (i < height);
    //  (get_next_line(fd, &line))    
    // {
    //     fill_map(z_map[i], line);
    //     free(line);
    //     i++;
    //     printf("\n");
    // }
    // close(fd);
    // z_map[i] = NULL;
    // mp->z_map = z_map;
}
