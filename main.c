/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:16:07 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/21 18:11:14 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dead(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

void	set_image(t_mlx *mlx)
{
	mlx->img.bpp = 32;
	mlx->img.endian = 0;
	mlx->img.size_line = WIN_WID * 4;
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WID, WIN_WID);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
	&(mlx->img.bpp), &(mlx->img.endian));
}

void		set_defaults(t_mlx *mlx)
{
	mlx->angle_x = ANGLE_X;
	mlx->angle_y = ANGLE_Y;
	mlx->angle_z = ANGLE_Z;
	mlx->shift_x = 0;
	mlx->shift_y = 0;
	if (mlx->mp->width > 150)
		mlx->zoom = ZOOM_BIG;
	else
		mlx->zoom = ZOOM_SMALL;
	mlx->dev_z = 1;	
	mlx->bottom_color = MAX_COLOR;
	mlx->top_color= 0x00FFB9;

}

void  fdx(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WID, WIN_HGH, "FDF");
	mlx->mp = (t_map*)ft_memalloc(sizeof(t_map));
}

int main(int ac, char *av[])
{
	t_mlx mlx;
	
	if (ac != 2)
		dead("usage: fdf [map]");
	fdx(&mlx);
	read_file(av[1], mlx.mp);
	set_defaults(&mlx);
	set_image(&mlx);
	set_colors_coeff(&mlx);
	draw(&mlx);
	mlx_key_hook(mlx.win, &deal_key, &mlx);
	mlx_hook(mlx.win, 4, 0, &mouse_press, (void *)&mlx);
	mlx_hook(mlx.win, 6, 0, &mouse_move, (void *)&mlx);
	mlx_hook(mlx.win, 5, 0, &mouse_release, (void *)&mlx);
	mlx_loop(mlx.mlx);
	return(0);
}



