/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:33:23 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/20 21:53:31 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	set_colors_coeff(t_mlx *mlx)
{
	float n;

	mlx->mp->max_z.r = (mlx->top_color >> 16);
	mlx->mp->max_z.g = ((mlx->top_color & 0xFF00) >> 8);
	mlx->mp->max_z.b = (mlx->top_color & 0xFF);
	mlx->mp->min_z.r = ((mlx->bottom_color) >> 16);
	mlx->mp->min_z.g = (((mlx->bottom_color) & 0xFF00) >> 8);
	mlx->mp->min_z.b = ((mlx->bottom_color) & 0xFF);
	n = (float)mlx->mp->min_z.value - (float)mlx->mp->max_z.value;
	mlx->c_middle.r = n / ((float)mlx->mp->min_z.r - (float)mlx->mp->max_z.r);
	mlx->c_middle.g = n / ((float)mlx->mp->min_z.g - (float)mlx->mp->max_z.g);
	mlx->c_middle.b = n / ((float)mlx->mp->min_z.b - (float)mlx->mp->max_z.b);
	mlx->c_step.r = ((float)mlx->mp->min_z.value -
		mlx->c_middle.r * (float)mlx->mp->min_z.r);
	mlx->c_step.g = (float)mlx->mp->min_z.value -
		mlx->c_middle.g * (float)mlx->mp->min_z.g;
	mlx->c_step.b = (float)mlx->mp->min_z.value -
		mlx->c_middle.b * (float)mlx->mp->min_z.b;
}

int		set_color(t_mlx *mlx, t_line cur_line, int step, int i)
{ 
	float	r;
	float	g;
	float	b;
	int		color;
	float	k;

	if (cur_line.color > cur_line.color1)
		k = ((float)cur_line.color - mod(((float)(cur_line.color1 - cur_line.color) /
			(float)step) * i));
	else
		k = ((float)cur_line.color + mod(((float)(cur_line.color1 - cur_line.color) /
			(float)step) * i));
	r = (k - mlx->c_step.r) / mlx->c_middle.r;
	g = (k - mlx->c_step.g) / mlx->c_middle.g;
	b = (k - mlx->c_step.b) / mlx->c_middle.b;
	color = ((int)r << 16) + ((int)g << 8) + b;
	return (color);
}