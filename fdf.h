/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:14:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/01 18:40:58 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define MAX_COLOR 0xFFA367
# define MIN_COLOR 0xFFFFFF

typedef struct  s_point {
    int         x;
    int         y;
    int         z;
    int         color;
}               t_point;

typedef struct  s_map {
    t_point     **z_map;
    int         width;
    int         height;
    int         max_z;
    int         min_z;
}               t_map;

typedef struct s_line {
    float       x;
    float       x1;
    float       y;
    float       y1;
    int         z;
    int         z1;
    int         color;
    int         zoom;
    int         shift_x;
    int         shift_y;
}               t_line;

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
    t_map       *mp;
    int         *color;
}               t_mlx;



// typedef struct s_fdf {
//     int         height;
//     int         width;
//     int         **z_map;
//     int         z_max;
//     int         z_min;
//     int         zoom;
//     int         color;
//     int         shift_x;
//     int         shift_y;
//     float       x;
//     float       y;
//     float       x1;
//     float       y1; 
//     int         z;
//     int         z1;
//     void        *mlx_ptr;
//     void        *win_ptr;
//     t_map       *map;
// }               t_fdf;

// ________main_________
void	dead(char *str);
//void  fdf_init_mlx(t_mlx *mlx);
//_________read_________

// void read_file(char *file_name, t_fdf *data);
void	lst_map(t_map *mp, t_list *lst);
void	ft_lstappend(t_list *alst, t_list *new);
void read_file(char *file_name, t_map *mp);
void  fdx(t_mlx *mlx);
int		fdf_count_width(char **line_split);
int		input_lst(t_list **lst, int fd);
void	fdf_free_lst(t_list *lst);

//______draw____________
void draw(t_mlx *mlx, t_map *mp);
void brsenham(t_mlx mlx, t_line *cur);
// void brsenham(t_fdf data);
// void draw(t_fdf *data);
// void isometric(float *x, float *y, int z);
// float mod(float i);
// void	set_map_color(t_fdf *data, int min_color, int max_color);

// ____ bonuses______
int		get_map_max(t_map *mp);
int		get_map_min(t_map *mp);
// int		get_color_z(int z, t_point *a, t_point *b);

#endif
