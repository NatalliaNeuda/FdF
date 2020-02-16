/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:26:30 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/15 17:21:41 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rot_x(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	int	tmp;
	int	tmp1;

	tmp = cur_line->y;
	tmp1 = cur_line->y1;
	cur_line->y = (float)cur_line->y * cos(mlx->angle_x) + (float)(mlx->cur.z) * sin(mlx->angle_x);
	cur_line->y1 = (float)cur_line->y1 * cos(mlx->angle_x) + (float)(mlx->cur.z1) * sin(mlx->angle_x);
	mlx->cur.z = (float)-tmp * sin(mlx->angle_x) + mlx->cur.z * cos(mlx->angle_x);
	mlx->cur.z1 = (float)-tmp1 * sin(mlx->angle_x) + (mlx->cur.z1) * cos(mlx->angle_x);
	cur_line->z = mlx->cur.z;
	cur_line->z1 = mlx->cur.z1;
}

static void	rot_y(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	int	tmp;
	int	tmp1;

	tmp = cur_line->x;
	tmp1 = cur_line->x1;
	cur_line->x = (float)cur_line->x * cos(mlx->angle_y) + (float)(mlx->cur.z) * sin(mlx->angle_y) ;
	cur_line->x1 = (float)cur_line->x1 * cos(mlx->angle_y) + (float)(mlx->cur.z1) * sin(mlx->angle_y) ;
	mlx->cur.z = -tmp * sin(mlx->angle_y) +	(float)(mlx->cur.z) * cos(mlx->angle_y) ;
	mlx->cur.z1 = -tmp1 * sin(mlx->angle_y) +	(float)(mlx->cur.z1) * cos(mlx->angle_y) ;
	cur_line->z = mlx->cur.z;
	cur_line->z1 = mlx->cur.z1;

}

static void	rot_z(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_x1;
	float	tmp_y1;

	tmp_x = (float)cur_line->x ;
	tmp_y = (float)cur_line->y;
	tmp_x1 = (float)cur_line->x1 ;
	tmp_y1 = (float)cur_line->y1;
	cur_line->x = ((float)tmp_x * cos(mlx->angle_z) - (float)tmp_y * sin(mlx->angle_z)) ;
	cur_line->y = ((float)tmp_x * sin(mlx->angle_z) + (float)tmp_y * cos(mlx->angle_z));
	cur_line->x1 = ((float)(tmp_x1) * cos(mlx->angle_z) - (float)(tmp_y1) * sin(mlx->angle_z));
	cur_line->y1 = ((float)(tmp_x1) * sin(mlx->angle_z) +	(float)(tmp_y1) * cos(mlx->angle_z));
	cur_line->z = (float)mlx->cur.z;
	cur_line->z1 = (float)mlx->cur.z1;
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

static void line_init(t_mlx *mlx, t_line *cur_line, int step_x, int step_y)
{
	cur_line->out = 0;
	cur_line->x =  mlx->cur.x - (float)mlx->mp->width/2 + 0.5;
    cur_line->y = mlx->cur.y  - (float)mlx->mp->height/2 + 0.5;
    cur_line->x1 = cur_line->x + step_x;
    cur_line->y1 = cur_line->y + step_y;
	mlx->cur.z = mlx->mp->z_map[mlx->cur.y][mlx->cur.x].z;
	mlx->cur.z1 = mlx->mp->z_map[mlx->cur.y + step_y][mlx->cur.x + step_x].z;
	cur_line->z = mlx->cur.z;
	cur_line->z1 = mlx->cur.z1;
	cur_line->x *=  mlx->zoom;
    cur_line->y *=  mlx->zoom;
    cur_line->x1 *=  mlx->zoom;
    cur_line->y1 *=  mlx->zoom;	
	cur_line->z *=  mlx->zoom;
	cur_line->z1 *=  mlx->zoom;
}

 t_line create_line(t_mlx *mlx, int step_x, int step_y)
{
    t_line cur_line;

	line_init(mlx, &cur_line, step_x, step_y);
	rot_x(mlx, &cur_line, step_x, step_y);
	rot_y(mlx, &cur_line, step_x, step_y);
	rot_z(mlx, &cur_line, step_x, step_y);
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