/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:49:40 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/21 18:28:22 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

void	projection_xyz(int key, t_mlx *mlx)
{
	if (key == X) 
	{
		mlx->angle_x = -1.57;
		mlx->angle_y = 0.0;
		mlx->angle_z = 0.0;
	}
	if (key == Y) 
	{
		mlx->angle_x = -1.57;
		mlx->angle_y = 0.0;
		mlx->angle_z = 1.57;
	}
	if (key == Z) 
	{
		mlx->angle_x = 0.0;
		mlx->angle_y = 0.0;
		mlx->angle_z = 0.0;
	}
}

void	sizing(int key, t_mlx *mlx)
{
	if (key == 126)
		mlx->angle_x += 0.1;
	if (key == 125)
		mlx->angle_y += 0.1;
	if (key == 123)
		mlx->angle_z += 0.1;
	if (key == PLUS)
		mlx->dev_z += 0.1;
	if (key == MINUS)
		mlx->dev_z -= 0.1;
}

void	set_colors(int key, t_mlx *mlx)
{
	if (key == 83)
	{
		mlx->bottom_color = 0xFF0000;
		mlx->top_color = 0x00FDFB;
	}
	if (key == 84)
	{
		mlx->bottom_color = 0x02DDFF;
		mlx->top_color = 0xFF005F;
	}
	if (key == 85)
	{
		mlx->bottom_color = 0xFF00AF;
		mlx->top_color = 0xF4FF00;
	}
	if (key == 86)
	{
		mlx->bottom_color = 0x72FF02;
		mlx->top_color = 0xFD5F00;
	}
	if (key == 87)
	{
		mlx->bottom_color = 0x0026FF;
		mlx->top_color = 0xDCFF00;
	}
}

int deal_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	printf("%d\n", key);
	if (key == ESCAPE)
		exit (0);
	sizing(key, mlx);
	projection_xyz(key, mlx);
	if (key == DEFAULT_0)
		set_defaults(mlx);
	set_colors(key, mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
	return (0);
}
