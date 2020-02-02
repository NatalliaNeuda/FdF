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

// void isometric(float *x, float *y, int z)
// {
//     *x = (*x - *y) * cos(0.7);
//     *y = (*x + *y) * sin(0.8) - z * 1;
// }

// void brsenham(t_fdf data)
// {
//     float x_step;
//     float y_step;
//     int max;

//     data.z = data.z_map[(int)data.y][(int)data.x];
//     data.z1 = data.z_map[(int)data.y1][(int)data.x1];

//     //_______________ZOOM______________
//     data.x *= data.zoom;
//     data.x1 *= data.zoom;
//     data.y *= data.zoom;
//     data.y1 *= data.zoom;

//     //_______________COLOR______________
//     data.color = (data.z) || (data.z1) ? 0xe80c0c : 0xffffff;
//     isometric(&data.x, &data.y, data.z);
//     isometric(&data.x1, &data.y1, data.z1);
//     //______________shift______________//
//     data.x += data.shift_x;
//     data.y += data.shift_y;
//     data.x1 += data.shift_x;
//     data.y1 += data.shift_y;


//     x_step = data.x1 - data.x;
//     y_step = data.y1 - data.y;

//     max = MAX(mod(x_step), mod(y_step));
//     x_step /= max;
//     y_step /= max;
//     while ((int) (data.x - data.x1) || (int)(data.y - data.y1))
//     {
//         mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.x, data.y, data.color);
//         data.x += x_step;
//         data.y += y_step;
//     }

// }
// void draw(t_fdf *data)
// {
//     data->y = 0;
//     while(data->y < data->height)
//     {
//         data->x = 0;
//         while (data->x < data->width)
//         {
//             if(data->x < data->width -1)
//             {   
//                 data->x1 = data->x + 1;
//                 data->y1 = data->y; 
//                 brsenham(*data);
//             }
//             if(data->y < data->height -1)
//             {
//                 data->x1 = data->x;
//                 data->y1 = data->y + 1;
//                 brsenham(*data);
//             }
//             data->x++;
//         }
//         data->y++;
//     }
// }

void brsenham(t_mlx mlx, t_line cur)
{
    float x_step;
    float y_step;
    int max;

    // printf("%0.0f\n", cur->x);
    // printf("%0.0f\n", cur->y);
    // printf("%d\n", cur->z);
    // printf("%0.0f\n", cur->x1);
    // printf("%0.0f\n", cur->y1);
    // printf("%d\n", cur->z1);
    // printf("\n");
    // cur.x *= cur.zoom;
    // cur.x1 *= cur.zoom;
    // cur.y *= cur.zoom;
    // cur.y1 *= cur.zoom;

    //_______________ZOOM______________
    cur.zoom = 20; 
    cur.x *= 10;
    cur.x1 *= 10;
    cur.y *= 10;
    cur.y1 *= 10;

    //_______________COLOR______________
    cur.color = (cur.z) || (cur.z1) ? 0xe80c0c : 0xffffff;
    // isometric(&cur.x, &cur.y, cur.z);
    // isometric(&cur.x1, &cur.y1, cur.z1);
    //______________shift______________//
    // cur->x += cur->shift_x;
    // cur->y += cur->shift_y;
    // cur->x1 += cur->shift_x;
    // cur->y1 += cur->shift_y;


    x_step = cur->x1 - cur->x;
    y_step = cur->y1 - cur->y;

    max = MAX(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int) (cur->x - cur->x1) || (int)(cur->y - cur->y1))
    {
        mlx_pixel_put(mlx.mlx, mlx.win, cur->x, cur->y, cur->color);
        cur->x += x_step;
        cur->y += y_step;
    }

}


void draw(t_mlx *mlx, t_map *mp)
{
    t_line cur;
    int i;
    int j;

    i = 0;
    cur = *(t_line*)ft_memalloc(sizeof(t_line));
    while(i <  mp->height)
    {
        cur.y = i;
        j = 0;
        cur.x = j;
        while (j < mp->width - 1)
        {
            cur.z = mp->z_map[i][j].z;
            cur.y1 = i;
            cur.x1 = j; 
            if(j <  mp->width - 1)
            {   
                cur.x1 = j + 1;
                cur.z1 = mp->z_map[i][j + 1].z; 
                brsenham(*mlx, *cur);
            }
            if( i < mp->height - 1)
            {
                cur.y1 = i + 1;
                cur.z1 = mp->z_map[i + 1][j].z; 
                brsenham(*mlx, *cur);
            }
            j++;
            //printf("%0.0f\n", cur.x);
        }
        i++;
    }
}