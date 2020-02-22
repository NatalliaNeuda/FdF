/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:33:18 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/21 18:33:38 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		ft_lstaddend(*lst, new);
	}
}

int		count_width(char **line_split)
{
	int i;

	i = 0;
	while (line_split[i])
		i++;
	return (i);
}

int		input_lst(t_list **lst, int fd)
{
	int		status;
	char	*line;
	char	**line_split;
	int		len;
	int		q;
	

	len = 0;
	while ((status = get_next_line(fd, &line)))
	{
	
		line_split = ft_strsplit(line, ' ');
		free(line);
		q = count_width(line_split);
		if (status < 0 || !q )
			return (0);
		else if (!len)
			len = q;
		else if (q != len)
			return (0);
		add_line(lst, line_split);
	}	
	return (len);
}

void	lst_assign(t_map *mp, t_list *lst)
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
		arr[++i] = (t_point*)ft_memalloc(sizeof(t_point) * (mp->width + 1));
		j = -1;
		while (++j < mp->width)
		{
			arr[i][j].y = i;
			arr[i][j].x = j;
			arr[i][j].z = ft_atoi(((char**)lst->content)[j]);
		}
		lst = lst->next;
	}
	free_lst(lst_head);
	mp->z_map = arr;
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
	lst_assign(mp, lst);
	mp->max_z.value = get_map_max(mp);
	mp->min_z.value = get_map_min(mp);
}
