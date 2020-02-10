/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <n*neuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:23:24 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/01 11:17:54 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minilibx_macos/mlx.h"
#include "fdf.h"

#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float mod(float i)
{
    return (i < 0 ? -i : i);
}

static void	draw_pixel(t_mlx *mlx, int x, int y, int c)
{
	if ((y >= WIN_HGH) || (x * 4 > mlx->img.size_line) || y < 0 || x * 4 < 0)
		return ;
	mlx->img.data[y * mlx->img.size_line + x * 4 + 3] =
		(unsigned char)((c & 0xFF000000) >> 24);
	mlx->img.data[y * mlx->img.size_line + x * 4 + 2] =
		(unsigned char)((c & 0xFF0000) >> 16);
	mlx->img.data[y * mlx->img.size_line + x * 4 + 1] =
		(unsigned char)((c & 0xFF00) >> 8);
	mlx->img.data[y * mlx->img.size_line + x * 4 + 0] =
		(unsigned char)(c & 0xFF);
}


void set_backgr(t_mlx *mlx)
{
    int i;

    i = 0;
    while (i < mlx->img.size_line * WIN_HGH)
    {
        mlx->img.data[i] = (unsigned char)BACK_COLOR & 255;
        mlx->img.data[i + 1] = (unsigned char)((BACK_COLOR >> 8) & 255);
        mlx->img.data[i + 2] = (unsigned char)((BACK_COLOR >> 16) & 255);
        mlx->img.data[i + 3] = 0;
        i += 4;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}


void settings(t_mlx *mlx, t_line *cur)
{
    cur->x *= mlx->zoom;
    cur->x1 *= mlx->zoom;
    cur->y *= mlx->zoom;
    cur->y1 *= mlx->zoom;

    
    cur->color = (cur->z) || (cur->z1) ? MAX_COLOR : MIN_COLOR;
    if (mlx->angle_y != 0)
    {
        isometric(mlx->angle_y, &cur->x, &cur->y, &cur->z);
        isometric(mlx->angle_y, &cur->x1, &cur->y1, &cur->z1);
    }
     if (mlx->angle_z != 0)
    {
        isometric(mlx->angle_z, &cur->x, &cur->y, &cur->z);
        isometric(mlx->angle_z, &cur->x1, &cur->y1, &cur->z1);
    }
    if (mlx->angle_x != 0)
    {
        isometric(mlx->angle_x, &cur->x, &cur->y, &cur->z);
        isometric(mlx->angle_x, &cur->x1, &cur->y1, &cur->z1);
    }
    cur->x +=  (WIN_WID / 2) - (mlx->mp->width/2 * mlx->zoom) + mlx->shift_x;
    // printf("%d\n", mlx->mp->width);
    // printf("%d\n", mlx->mp->height);
    cur->y += (WIN_HGH / 2) -   (mlx->mp->height / 2 * mlx->zoom) + mlx->shift_y;
    cur->x1 += (WIN_WID / 2) -  (mlx->mp->width/2 * mlx->zoom) + mlx->shift_x;
    cur->y1 += (WIN_HGH / 2)  - (mlx->mp->height/2 * mlx->zoom) + mlx->shift_y;
}


void isometric(float angle, float *x, float *y, int *z)
{
    *x = (*x * cos(angle) - (double)*z * sin(angle));
    *z = (double)*z * cos(angle) + *x * sin(angle);
    *y = (*x * cos(angle) + *y * sin(angle)) - (*z * 2);
}

void brsenham(t_mlx *mlx, t_line cur)
{
    float x_step;
    float y_step;
    int max;    
    
    settings(mlx, &cur);

    x_step = cur.x1 - cur.x;
    y_step = cur.y1 - cur.y;

    max = MAX(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int) (cur.x - cur.x1) || (int)(cur.y - cur.y1))
    {
        

        //draw_pixel(mlx, cur.x, cur.y, cur.color);
        mlx_pixel_put(mlx->mlx, mlx->win, cur.x, cur.y, cur.color);
        // if (cur.z1 > cur.z)
        //     cur.color = get_color_z(cur.color, &mlx->mp->min_z,
		// 			&mlx->mp->max_z);
        
        //mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
        cur.x += x_step;
        
        cur.y += y_step;
    }

}


void draw(t_mlx *mlx)
{
    t_line *cur;
    int i;
    int j;
    static int count = 0;

    set_backgr(mlx);
    count++;
    i = 0;
    cur = (t_line*)ft_memalloc(sizeof(t_line));
    while (i < mlx->mp->height)
    {
        j = 0;
        while (j < mlx->mp->width)
        {
            cur->y = i;
            cur->x = j;
            cur->z = mlx->mp->z_map[i][j].z ;
            cur->y1 = i;
            if(j <  mlx->mp->width - 1)
            {   
                cur->x1 = j + 1;
                cur->z1 = mlx->mp->z_map[i][j + 1].z ; 
                brsenham(mlx, *cur);
            }
            if( i < mlx->mp->height - 1)
            {
                cur->x1 = j;
                cur->y1 = i + 1;
                cur->z1 = mlx->mp->z_map[i + 1][j].z ; 
                brsenham(mlx, *cur);
            }
            j++;
        }
        i++;
    }
}