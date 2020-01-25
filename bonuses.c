/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:53:08 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/24 07:49:47 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

// int		get_color_z(int z, t_point *a, t_point *b)
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

// int		get_map_min(t_fdf *data)
// {
// 	int i;
// 	int j;
// 	int z_min;

// 	i = 0;
// 	z_min = data->z_map[0][0].z;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			z_min = z_min <= data->z_map[i][j].z ? z_min : data->z_map[i][j].z;
// 			++j;
// 		}
// 		++i;
// 	}
// 	return (z_min);
// }

// int		get_map_max(t_fdf *data)
// {
// 	int i;
// 	int j;
// 	int z_max;

// 	i = 0;
// 	z_max = data->z_map[0][0].z;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			z_max = z_max >= data->z_map[i][j].z ? z_max : data->z_map[i][j].z;
// 			++j;
// 		}
// 		++i;
// 	}
// 	return (z_max);
// }

// void	set_map_color(t_fdf *data, int min_color, int max_color)
// {
// 	t_point	z_min;
// 	t_point	z_max;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	ft_bzero(&z_min, sizeof(z_min));
// 	ft_bzero(&z_max, sizeof(z_max));
// 	z_min.z = get_map_min(data);
// 	z_max.z = get_map_max(data);
// 	z_min.color = min_color;
// 	z_max.color = max_color;
// 	while (i < data->height)
// 	{
// 		j = -1;
// 		while (++j < data->width)
// 		{
// 			if (z_min.z == z_max.z)
// 				data->z_map[i][j].color = z_min.color;
// 			else
// 				data->z_map[i][j].color = get_color_z(data->z_map[i][j].z, &z_min, &z_max);
                
// 		}
// 		++i;
// 	}
// }

