/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:23:24 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/24 07:58:41 by nneuda           ###   ########.fr       */
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
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z * 1;
}

// void brsenham(float x, float y, float x1, float y1, t_fdf *data)
// {
//     float x_step;
//     float y_step;
//     int max;
//     int z;
//     int z1;

//     z = (int)data->z_map[(int)y][(int)x];
//     z1 = (int)data->z_map[(int)y1][(int)x1];

//     //______________zoom______________//
//     x *= data->zoom;
//     x1 *= data->zoom;
//     y *= data->zoom;
//     y1 *= data->zoom;

//     //______________color______________//
//     data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    
//       // ______________3D_________________//
//     isometric(&x, &y, z);
//     isometric(&x1, &y1, z1);
//     //______________shift______________//
//     x += 250;
//     y += 250;
//     x1 += 250;
//     y1 += 250;


// //    if (x1 >= x)
//         x_step = (x1 - x); //2
// //   else
// //         x_step = (x - x1); //2
//     // if (y1 >= y)
//         y_step = (y1 - y); //2
//     // else
//     //    y_step = (y - y1); //2
    
    

//     max = MAX(mod(x_step), mod(y_step));
   
//         x_step /= max;
//         y_step /= max;
    

//     while ((int)(x - x1) || (int)(y - y1))
//     {
//         mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
//         x += x_step;
//         y += y_step;

//     }
// }

void brsenham(float x, float y, float x1, float y1, t_fdf *data)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = data->z_map[(int)y][(int)x];
    z1 = data->z_map[(int)y1][(int)x1];

    //_______________ZOOM______________
    x *= data->zoom;
    x1 *= data->zoom;
    y *= data->zoom;
    y1 *= data->zoom;

    //_______________COLOR______________
    data->color = (z) || (z1) ? 0xe80c0c : 0xffffff;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    //______________shift______________//
    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;
    x_step = x1 - x;
    y_step = y1 - y;

    max = MAX(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int) (x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }

}
void draw(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while(y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if(x < data->width -1)
                brsenham(x, y, x + 1, y, data);
            if(y < data->height -1)
                brsenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}