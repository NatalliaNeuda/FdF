/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:14:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/09 18:16:15 by nneuda           ###   ########.fr       */
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

# define MAX_COLOR 0xFF0067
# define MIN_COLOR 0xFFFFFF
# define BACK_COLOR 0x696C6D
# define WIN_WID 2000
# define WIN_HGH 1280
# define ANGLE_X	0
# define ANGLE_Y	0.5
# define ANGLE_Z	0
# define SHIFT_X	0
# define SHIFT_Y	0
# define ZOOM	    30


# define ESCAPE 53

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				size_line;
	int				bpp;
	int				endian;
}					t_img;

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
    t_point     max_z;
    t_point     min_z;

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

typedef struct s_event
{
    char        mouse_press;
    char        mouse_realise;
    t_point     mouse_move;
    char        perspective;
    char        menu;
}               t_event;

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
    t_map       *mp;
    t_img       img;
    int         *color;
    int         shift_x;
    int         shift_y;
    int         zoom;
    double      angle_z;
    double      angle_y;
    double      angle_x;
    t_event     event;
    
}               t_mlx;

// ________main_________
void	dead(char *str);
void  fdx(t_mlx *mlx);
void	set_map_color(t_mlx *mlx, int min_color, int max_color);
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
void isometric(float angle, float *x, float *y, int *z);
void settings(t_mlx *mlx, t_line *cur);
void set_backgr(t_mlx *mlx);


// ____ bonuses______
int		get_map_max(t_map *mp);
int		get_map_min(t_map *mp);
int		get_color_z(int z, t_point *a, t_point *b);

//______events_______
int			mouse_release(int key, int x, int y, void *param);
int			mouse_press(int key, int x, int y, void *param);
int			mouse_move(int x, int y, void *param);
#endif
