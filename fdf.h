/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:14:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/04 19:02:21 by nneuda           ###   ########.fr       */
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

# define ESCAPE 53

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

}               t_line;

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
    t_map       *mp;
    int         *color;
    int         shift_x;
    int         shift_y;
    int         zoom;
    float       angle;
}               t_mlx;

// ________main_________
void	dead(char *str);
//void  fdf_init_mlx(t_mlx *mlx);
//_________read_________


void	lst_map(t_map *mp, t_list *lst);
void	ft_lstappend(t_list *alst, t_list *new);
void read_file(char *file_name, t_map *mp);
void  fdx(t_mlx *mlx);
int		fdf_count_width(char **line_split);
int		input_lst(t_list **lst, int fd);
void	fdf_free_lst(t_list *lst);

//______draw____________
void draw(t_mlx *mlx);
void brsenham(t_mlx *mlx, t_line cur);
//void isometric(float *x, float *y, int *z);
void isometric(float angle, float *x, float *y, int *z);
void settings(t_mlx *mlx, t_line *cur);


// ____ bonuses______
int		get_map_max(t_map *mp);
int		get_map_min(t_map *mp);
// int		get_color_z(int z, t_point *a, t_point *b);

#endif
