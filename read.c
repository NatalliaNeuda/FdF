/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:33:18 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/10 17:53:04 by nneuda           ###   ########.fr       */
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

void	lst_map(t_map *mp, t_list *lst)
{
	t_point	**arr;
	t_list	*lst_head;
	int		hght;
	int		i;
	int		j;

	lst_head = lst;
	hght = ft_lstcount(lst);
	mp->height = hght;
	arr = (t_point**)ft_memalloc(sizeof(t_point*) * hght);
	i = -1;
	while (lst)
	{
		arr[++i] = (t_point*)ft_memalloc(sizeof(t_point) * mp->width);
		j = -1;
		while (j < mp->width - 1)
		{
			arr[i][++j].y = i;
			arr[i][j].x = j;
			arr[i][j].z = ft_atoi(((char**)lst->content)[j]);
			printf("%3d", arr[i][j].z);
		}
		printf("\n");
		lst = lst->next;
	}
	fdf_free_lst(lst_head);
	mp->height = hght;
	mp->z_map = arr;
	mp->z_map_dup = arr;
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
	mp->max_z.z = get_map_max(mp);
	mp->min_z.z = get_map_min(mp);
}
