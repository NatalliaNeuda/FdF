/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:53:08 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/31 14:17:58 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

// int		get_color_z(int z, int *a, int *b)
// {
// 	int		r;
// 	int		g;
// 	int		blue;
// 	double	t;

// 	t = ((double)z - (double)a->z) / ((double)b->z - (double)a->z);
// 	r = ((a->color >> 16) & 0xFF) + (((b->color >> 16) & 0xFF) -
// 		((a->color >> 16) & 0xFF)) * t;
// 	g = ((a->color >> 8) & 0xFF) + (((b->color >> 8) & 0xFF) -
// 		((a->color >> 8) & 0xFF)) * t;
// 	blue = ((a->color >> 0) & 0xFF) + (((b->color >> 0) & 0xFF) -
// 		((a->color >> 0) & 0xFF)) * t;
// 	return (r << 16 | g << 8 | blue);
// }
void	ft_lstappend(t_list *alst, t_list *new)
{
	if (!alst || !new)
		return ;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}


int		get_map_min(t_map *mp)
{
	int i;
	int j;
	int min_z;

	i = 0;
	min_z = mp->z_map[0][0].z;
	while (i < mp->height)
	{
		j = 0;
		while (j < mp->width)
		{
			if (min_z > mp->z_map[i][j].z)
				min_z = mp->z_map[i][j].z;
			++j;
		}
		++i;
	}
	return (min_z);
}

int		get_map_max(t_map *mp)
{
	int i;
	int j;
	int max_z;

	i = 0;
	max_z = mp->z_map[0][0].z;
	while (i < mp->height)
	{
		j = 0;
		while (j < mp->width)
		{
			if (max_z < mp->z_map[i][j].z)
				max_z = mp->z_map[i][j].z;
			++j;
		}
		++i;
	}
	return (max_z);
}

// void	set_map_color(t_fdf *data, int min_color, int max_color, t_point dot)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	ft_bzero(&data.z_min, sizeof(data->z_min));
// 	ft_bzero(&data.z_max, sizeof(data->z_max));
// 	data.z_min = get_map_min(data);
// 	data.z_max = get_map_max(data);
// 	data.color_min = min_color;
// 	data.color_max = max_color;
// 	while (i < data->height)
// 	{
// 		j = -1;
// 		while (++j < data->width)
// 		{
// 			if (data.z_min == data.z_max)
// 				data.color = data.color_min;
// 			else
// 				data.color = get_color_z(data.z_map[i][j], &data.z_min, &data.z_max);
                
// 		}
// 		++i;
// 	}
// }

