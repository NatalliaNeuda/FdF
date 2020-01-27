/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:14:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/01/26 21:03:07 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define MAX_COLOR 0xFFA367
# define MIN_COLOR 0xFFFFFF

// typedef struct s_fdf {
//     int         height;
//     int         wight;
//     int         **z_map;

//     void        *mlx;
//     void        *window;
// }               t_fdf;

// typedef struct  s_map {
//     t_point     **map;
//     int         rows;
//     int         collums;
//     int         max_z;
//     int         min_z;
// }               t_map;

// typedef struct  s_mlx {
//     void        *mlx;
//     void        *window:
//     t_map       *map;
//     int         *color;
// }               t_mlx;

typedef struct  s_point {
    float         x;
    float         y;
    float         z;
    int         color;
}               t_point;


typedef struct s_fdf {
    int         height;
    int         width;
    int         **z_map;
    int         z_max;
    int         z_min;
    int         zoom;
    int         color;
    int         shift_x;
    int         shift_y;
    float       x;
    float       y;
    float       x1;
    float       y1; 
    int         z;
    int         z1;
    void        *mlx_ptr;
    void        *win_ptr;
}               t_fdf;

void read_file(char *file_name, t_fdf *data);
void brsenham(t_fdf data);
void draw(t_fdf *data);
void isometric(float *x, float *y, int z);
float mod(float i);

void	set_map_color(t_fdf *data, int min_color, int max_color);
int		get_map_max(t_fdf *data);
int		get_map_min(t_fdf *data);
int		get_color_z(int z, t_point *a, t_point *b);

#endif
