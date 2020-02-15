/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:49:40 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/10 18:44:15 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"


int			mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (mlx->event.mouse_realise)
	{
		mlx->shift_x = x - mlx->event.mouse_move.x + mlx->shift_x;
		mlx->shift_y = y - mlx->event.mouse_move.y + mlx->shift_y;
	}
	if (mlx->event.mouse_press)
	{
		mlx->angle_z = mlx->angle_z + (float)(x - mlx->event.mouse_move.x)
		/ 150.0;
		mlx->angle_x = mlx->angle_x + (float)(y - mlx->event.mouse_move.y)
		/ 150.0;
	}
	mlx->event.mouse_move.x = x;
	mlx->event.mouse_move.y = y;
	draw(mlx);
	return (0);
}

int			mouse_press(int key, int x, int y, void *param)
{
	t_mlx		*mlx;
    
	mlx = (t_mlx*)param;
	if (key == 5)
		mlx->zoom += 1;
	if (key == 4 && mlx->zoom > 1)
		mlx->zoom -= 1;
	if (key == 3)
	{
		mlx->event.mouse_realise = 1;
		mlx->event.mouse_move.x = x;
		mlx->event.mouse_move.y = y;
		mouse_move(x, y, param);
	}
	if (key == 1)
	{
		mlx->event.mouse_press = 1;
		mlx->event.mouse_move.x = x;
		mlx->event.mouse_move.y = y;
		mouse_move(x, y, param);
	}
	if (key == 5 || key == 4)
		draw(mlx);
	return (0);
}

int			mouse_release(int key, int x, int y, void *param)
{
	t_mlx	*mlx;

	x += 0;
	y += 0;
	mlx = (t_mlx*)param;
	if (key == 3)
		mlx->event.mouse_realise = 0;
	if (key == 1)
		mlx->event.mouse_press = 0;
	draw(mlx);
	return (0);
}
