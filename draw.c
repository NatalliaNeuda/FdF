/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:23:24 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/26 21:02:17 by nneuda           ###   ########.fr       */
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

void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.7);
    *y = (*x + *y) * sin(0.8) - z * 1;
}

void brsenham(t_fdf data)
{
    float x_step;
    float y_step;
    int max;

    data.z = data.z_map[(int)data.y][(int)data.x];
    data.z1 = data.z_map[(int)data.y1][(int)data.x1];

    //_______________ZOOM______________
    data.x *= data.zoom;
    data.x1 *= data.zoom;
    data.y *= data.zoom;
    data.y1 *= data.zoom;

    //_______________COLOR______________
    data.color = (data.z) || (data.z1) ? 0xe80c0c : 0xffffff;
    isometric(&data.x, &data.y, data.z);
    isometric(&data.x1, &data.y1, data.z1);
    //______________shift______________//
    data.x += data.shift_x;
    data.y += data.shift_y;
    data.x1 += data.shift_x;
    data.y1 += data.shift_y;


    x_step = data.x1 - data.x;
    y_step = data.y1 - data.y;

    max = MAX(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int) (data.x - data.x1) || (int)(data.y - data.y1))
    {
        mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.x, data.y, data.color);
        data.x += x_step;
        data.y += y_step;
    }

}
void draw(t_fdf *data)
{
    data->y = 0;
    while(data->y < data->height)
    {
        data->x = 0;
        while (data->x < data->width)
        {
            if(data->x < data->width -1)
            {   
                data->x1 = data->x + 1;
                data->y1 = data->y; 
                brsenham(*data);
            }
            if(data->y < data->height -1)
            {
                data->x1 = data->x;
                data->y1 = data->y + 1;
                brsenham(*data);
            }
            data->x++;
        }
        data->y++;
    }
}