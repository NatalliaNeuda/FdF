/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:33:23 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/17 16:01:34 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx->coeff_k.r = n / ((float)mlx->mp->min_z.r - (float)mlx->mp->max_z.r);
	mlx->coeff_k.g = n / ((float)mlx->mp->min_z.g - (float)mlx->mp->max_z.g);
	mlx->coeff_k.b = n / ((float)mlx->mp->min_z.b - (float)mlx->mp->max_z.b);
	mlx->coeff_b.r = ((float)mlx->mp->min_z.value -
		mlx->coeff_k.r * (float)mlx->mp->min_z.r);
	mlx->coeff_b.g = (float)mlx->mp->min_z.value -
		mlx->coeff_k.g * (float)mlx->mp->min_z.g;
	mlx->coeff_b.b = (float)mlx->mp->min_z.value -
		mlx->coeff_k.b * (float)mlx->mp->min_z.b;
}

int		get_color(t_mlx *mlx, t_line line, int delta, int i)
{
	int		c;
	float	r;
	float	g;
	float	b;
	float	k;

	if (line.color > line.color1)
		k = ((float)line.color - fabsf(((float)(line.color1 - line.color) /
			(float)delta) * i));
	else
		k = ((float)line.color + fabsf(((float)(line.color1 - line.color) /
			(float)delta) * i));
	r = (k - mlx->coeff_b.r) / mlx->coeff_k.r;
	g = (k - mlx->coeff_b.g) / mlx->coeff_k.g;
	b = (k - mlx->coeff_b.b) / mlx->coeff_k.b;
	c = ((int)r << 16) + ((int)g << 8) + b;
	if (mlx->coeff_k.r == 0 && mlx->coeff_k.g == 0 && mlx->coeff_k.b == 0
		&& mlx->coeff_b.r == 0 && mlx->coeff_b.g == 0 && mlx->coeff_b.b == 0)
		c = mlx->bottom_color;
	return (c);
}