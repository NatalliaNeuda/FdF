/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:53:08 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/09 14:53:37 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

int		get_color_z(int z, t_point *a, t_point *b)
{
	int		r;
	int		g;
	int		blue;
	double	t;
	a->color = MAX_COLOR;
	b->color = MIN_COLOR;

	t = ((double)z - (double)a->z) / ((double)b->z - (double)a->z);
	r = ((a->color >> 16) & 0xFF) + (((b->color >> 16) & 0xFF) -
		((a->color >> 16) & 0xFF)) * t;
	g = ((a->color >> 8) & 0xFF) + (((b->color >> 8) & 0xFF) -
		((a->color >> 8) & 0xFF)) * t;
	blue = ((a->color >> 0) & 0xFF) + (((b->color >> 0) & 0xFF) -
		((a->color >> 0) & 0xFF)) * t;
	return (r << 16 | g << 8 | blue);
}
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

// void	set_map_color(t_mlx *mlx, int min_color, int max_color)
// {
// 	t_point	z_min;
// 	t_point	z_max;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	ft_bzero(&z_min, sizeof(z_min));
// 	ft_bzero(&z_max, sizeof(z_max));
// 	z_min.z = get_map_min(mlx->mp);
// 	z_max.z = get_map_max(mlx->mp);
// 	z_min.color = min_color;
// 	z_max.color = max_color;
// 	while (i < mlx->mp->width)
// 	{
// 		j = -1;
// 		while (++j < mlx->mp->height)
// 		{
// 			if (z_min.z == z_max.z)
// 				mlx->mp->z_map[i][j].color = z_min.color;
// 			else
// 				mlx->mp->z_map[i][j].color = get_color_z(mlx->mp->z_map[i][j].z,
// 					&z_min, &z_max);
// 		}
// 		++i;
// 	}
// }

// void	set_map_color(t_mlx *mlx, int min_color, int max_color)
// {
// 	t_point	z_min;
// 	t_point	z_max;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	ft_bzero(&z_min, sizeof(z_min));
// 	ft_bzero(&z_max, sizeof(z_max));
// 	z_min.z = get_map_min(mlx->mp);
// 	z_max.z = get_map_max(mlx->mp);
// 	z_min.color = min_color;
// 	z_max.color = max_color;
// 	while (i < mlx->mp->width)
// 	{
// 		j = -1;
// 		while (++j < mlx->mp->height)
// 		{
// 			if (z_min.z == z_max.z)
// 				mlx->mp->z_map[i][j].color = z_min.color;
// 			else
// 				mlx->mp->z_map[i][j].color = get_color_z(mlx->mp->z_map[i][j].z,
// 					&z_min, &z_max);
// 		}
// 		++i;
// 	}
// }
