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

void put_line(t_mlx *mlx, t_line line_cur)
{
    float x_step;
    float y_step;
    float delta;
    int i;
    

    x_step = line_cur.x1 - line_cur.x;
    y_step = line_cur.y1 - line_cur.y;
    i = -1;
    if (mod(x_step) >= mod(y_step))
        while (++i < mod(x_step))
        {
            delta = (float) i / x_step;
            draw_pixel(mlx, line_cur.x + copysign(i, x_step) , line_cur.y + copysign(round(delta * y_step), y_step), set_color(mlx, line_cur, x_step, i));        
        }
    else
        while (++i < mod(y_step))
        {
            delta = (float) i / y_step;
            draw_pixel(mlx, line_cur.x + copysign(round(delta * x_step), x_step) , line_cur.y + copysign(i, y_step), set_color(mlx, line_cur, y_step, i));        
        }
}

void draw(t_mlx *mlx)
{   
    set_colors_coeff(mlx);
    set_backgr(mlx);
    mlx->cur.y = 0;  
    while (mlx->cur.y < mlx->mp->height)
    {
        mlx->cur.x = 0;
        while (mlx->cur.x < mlx->mp->width)
        {
            if(mlx->cur.x < mlx->mp->width - 1)
                put_line(mlx, create_line(mlx, 1, 0));
            if(mlx->cur.y < mlx->mp->height - 1)
                put_line(mlx, create_line(mlx, 0, 1));
            mlx->cur.x++;
        }
        mlx->cur.y++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}