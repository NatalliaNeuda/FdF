/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:14:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/21 18:13:10 by nneuda           ###   ########.fr       */
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

# define MAX_COLOR 0xFF00AF
# define MIN_COLOR 0xC400FF 
# define BACK_COLOR 0x2E4053
# define WIN_WID 2000
# define WIN_HGH 1280
# define ANGLE_X	-0.7
# define ANGLE_Y	0.30
# define ANGLE_Z	0.0
# define SHIFT_X	0
# define SHIFT_Y	0
# define ZOOM_SMALL	30
# define ZOOM_BIG   3
# define X   7
# define Y   16
# define Z   6
# define MINUS   78
# define PLUS   69
# define SCRL_UP   5
# define SCRL_DWN   4
# define DEFAULT_0   82




# define ESCAPE 53

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				size_line;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_rgb
{
	float			r;
	float			g;
	float			b;
    float           value;
}					t_rgb;

typedef struct  s_point {
    int         x;
    int         y;
    int         z;
    int         z1;
    int         color;
}               t_point;

typedef struct  s_map {
    t_point     **z_map;
    int         width;
    int         height;
    t_rgb       max_z;
    t_rgb       min_z;

}               t_map;

typedef struct s_line {
    float       x;
    float       x1;
    float       y;
    float       y1;
    int         z;
    int         z1;
    int         out;
    int         color;
    int         color1;
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
    t_event     event;
    t_point     cur;
    int         shift_x;
    int         shift_y;
    int         zoom;
    double      angle_z;
    double      angle_y;
    double      angle_x;
    float       z_temp;
    float       z_temp1;
    float       dev_z;
    int         bottom_color;
    int         top_color;
    t_rgb		c_middle;
	t_rgb		c_step;
    
    
}               t_mlx;

// ________main_________
void	dead(char *str);
void  fdx(t_mlx *mlx);
void	set_image(t_mlx *mlx);
void	set_map_color(t_mlx *mlx, int min_color, int max_color);
void		set_defaults(t_mlx *mlx);

//_________read_________
void	lst_assign(t_map *mp, t_list *lst);
void read_file(char *file_name, t_map *mp);
int		count_width(char **line_split);
int		input_lst(t_list **lst, int fd);

//_________read2_________
void	free_lst(t_list *lst);
size_t	ft_lstcount(t_list *lst);
void	ft_lstaddend(t_list *lst, t_list *new);

//______draw____________
void draw(t_mlx *mlx);
void put_line(t_mlx *mlx, t_line line_cur);
void isometric(float angle, float *x, float *y, int *z);
void settings(t_mlx *mlx, t_line *cur);
void set_backgr(t_mlx *mlx);
void	set_linear_coefficients(t_mlx *mlx);
float mod(float i);


// ____ bonuses______
int		get_map_max(t_map *mp);
int		get_map_min(t_map *mp);
int		get_color_z(int z, t_point *a, t_point *b);

//______events_______
int			mouse_release(int key, int x, int y, void *param);
int			mouse_press(int key, int x, int y, void *param);
int			mouse_move(int x, int y, void *param);
void	    projection_xyz(int key, t_mlx *mlx);
int deal_key(int key, void *param);

//______rotation______
t_line create_line(t_mlx *mlx, int step_x, int step_y);

//______gradient______

void	set_colors_coeff(t_mlx *mlx);
int		set_color(t_mlx *mlx, t_line line, int delta, int i);

#endif
