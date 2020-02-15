/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:26:30 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/14 22:26:13 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rot_x(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	int	temp0;
	int	temp1;

	
	cur_line->x = mlx->cur.x - (float)mlx->mp->width/2 + 0.5;
	cur_line->x1 = mlx->cur.x + step_x;
	temp0 = cur_line->y;
	temp1 = cur_line->y1;
	printf("%f\n", cur_line->y);
	cur_line->y = (float)cur_line->y * cos(mlx->angle_x) +
		(float)(mlx->z_temp)
		* sin(mlx->angle_x) - (float)mlx->mp->height/2 + 0.5;
	cur_line->y1 = (float)cur_line->y1 * cos(mlx->angle_x) +
		(float)(mlx->z_temp1)
		* sin(mlx->angle_x);
	mlx->z_temp = (float)-temp0
		* sin(mlx->angle_x) + mlx->z_temp * cos(mlx->angle_x);
	mlx->z_temp1 = (float)-temp1 * sin(mlx->angle_x) + (mlx->z_temp1) * cos(mlx->angle_x);
	cur_line->z = mlx->z_temp;
	cur_line->z1 = mlx->z_temp1;
}

static void	rot_y(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	int	temp0;
	int	temp1;

	temp0 = cur_line->x;
	temp1 = cur_line->x1;
	cur_line->x = (float)cur_line->x * cos(mlx->angle_y) +
		(float)(mlx->z_temp * mlx->zoom)
		* sin(mlx->angle_y);
	cur_line->x1 = (float)cur_line->x1 * cos(mlx->angle_y) +
		(float)(mlx->z_temp1
		* mlx->zoom) * sin(mlx->angle_y);
	mlx->z_temp = -temp0
		* sin(mlx->angle_y) +
		(float)(mlx->z_temp
		* mlx->zoom) * cos(mlx->angle_y);
	mlx->z_temp1 = -temp1
		* sin(mlx->angle_y) +
		(float)(mlx->z_temp1
		* mlx->zoom) * cos(mlx->angle_y);
		cur_line->z = mlx->z_temp;
		cur_line->z1 = mlx->z_temp1;

}

static void	rot_z(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	float	cx;
	float	cy;

cx = (float)cur_line->x ;
	cy = (float)cur_line->y;
	// cx = (float)cur_line->x - (float)mlx->mp->width / 2 + 0.5;
	// cy = (float)cur_line->y - (float)mlx->mp->height / 2 + 0.5;
	cur_line->x = ((float)cx * cos(mlx->angle_z) - (float)cy
		* sin(mlx->angle_z)) * (float)mlx->zoom;
	cur_line->y = ((float)cx * sin(mlx->angle_z) + (float)cy * cos(mlx->angle_z)) *
		(float)mlx->zoom;
	cur_line->x1 = ((float)(cx + step_x) * cos(mlx->angle_z) -
		(float)(cy + step_y) * sin(mlx->angle_z)) * (float)mlx->zoom;
	cur_line->y1 = ((float)(cx + step_x) * sin(mlx->angle_z) +
		(float)(cy + step_y) * cos(mlx->angle_z)) * (float)mlx->zoom;
	cur_line->z = (float)mlx->z_temp;
	cur_line->z1 = (float)mlx->z_temp1;
}

static void	flat(t_line *cur_line)
{
	t_point	    old0;
	t_point 	old1;

	old0.x = cur_line->x;
	old0.y = cur_line->y;
	old1.x = cur_line->x1;
	old1.y = cur_line->y1;
	cur_line->x = 3000 * cur_line->x / (float)(3000 - cur_line->z);
	cur_line->y = 3000 * cur_line->y / (float)(3000 - cur_line->z);
	cur_line->x1 = 3000 * cur_line->x1 / (float)(3000 - cur_line->z1);
	cur_line->y1 = 3000 * cur_line->y1 / (float)(3000 - cur_line->z1);
	if ((old0.x > 0 && cur_line->x < 0) || (old0.x < 0 && cur_line->x > 0) ||
	(old0.y > 0 && cur_line->y < 0) || (old0.y < 0 && cur_line->y > 0) ||
	(old1.x > 0 && cur_line->x1 < 0) || (old1.x < 0 && cur_line->x1 > 0) ||
	(old1.y > 0 && cur_line->y1 < 0) || (old1.y < 0 && cur_line->y1 > 0))
	{
		cur_line->x = 0;
		cur_line->y = 0;
		cur_line->x1 = 0;
		cur_line->y1 = 0;
	}
}


 t_line create_line(t_mlx *mlx, int step_x, int step_y)
{
    t_line cur_line;

    cur_line.out = 0;
	cur_line.x =  mlx->cur.x;
    cur_line.y = mlx->cur.y;
    cur_line.x1 = mlx->cur.x + step_x;
    cur_line.y1 = mlx->cur.y + step_y;
	mlx->z_temp = mlx->mp->z_map[mlx->cur.y][mlx->cur.x].z;
	mlx->z_temp1 = mlx->mp->z_map[mlx->cur.y + step_y][mlx->cur.x + step_x].z;
	rot_x(mlx, &cur_line, step_x, step_y);
		
	rot_y(mlx, &cur_line, step_x, step_y);
	rot_z(mlx, &cur_line, step_x, step_y);
 	// if (mlx->angle_z != 0)
    // {
    //     isometric(mlx->angle_z, &cur_line.x, &cur_line.y, &cur_line.z);
    //     isometric(mlx->angle_z, &cur_line.x1, &cur_line.y1, &cur_line.z1);
    // }
    if (mlx->event.perspective == 1)
        flat(&cur_line);
    cur_line.color = (mlx->mp->z_map[mlx->cur.y][mlx->cur.x].z) || (mlx->mp->z_map[mlx->cur.y + step_y][mlx->cur.x + step_x].z ) ? MAX_COLOR : MIN_COLOR;
    cur_line.x +=  (WIN_WID / 2) + mlx->shift_x;
    cur_line.y += (WIN_HGH / 2)  + mlx->shift_y;
    cur_line.x1 += (WIN_WID / 2)  + mlx->shift_x;
    cur_line.y1 += (WIN_HGH / 2)  + mlx->shift_y;
    if (((cur_line.x > WIN_WID || cur_line.x < 0) ||
		(cur_line.y > WIN_HGH || cur_line.y < 0)) &&
		((cur_line.x1 > WIN_WID || cur_line.x1 < 0) ||
		(cur_line.y1 > WIN_HGH || cur_line.y1 < 0)))
	    cur_line.out = 1;
    return (cur_line);
}