/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:16:07 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/15 20:28:04 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minilibx_macos/mlx.h"
#include "fdf.h"

//gcc *.c -L. libft/libft.a  ~/FdF/minilibx_macos/libmlx.a fdf.h -framework OpenGL -framework Appkit

void	dead(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

static void	set_image(t_mlx *mlx)
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
	mlx->zoom = ZOOM;
	mlx->dev_z = 1;	

}

int deal_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	printf("%d\n", key);
	if (key == 35)
	{
		if (mlx->event.perspective == 0)
			mlx->event.perspective = 1;
		else
			mlx->event.perspective = 0;
	}
	if (key == ESCAPE)
		exit (0);
	if (key == 126)
		mlx->angle_x += 0.1;
	if (key == 125)
		mlx->angle_y += 0.1;
	if (key == 123)
		mlx->angle_z += 0.1;
	if (key == 18)
		mlx->dev_z += 0.1;
	if (key == 19)
		mlx->dev_z -= 0.1;
	projection_xyz(key, mlx);
	if (key == 29)
		set_defaults(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
	
	return (0);
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
	set_defaults(&mlx);
	read_file(av[1], mlx.mp);
	set_image(&mlx);
	draw(&mlx);
	mlx_key_hook(mlx.win, &deal_key, &mlx);
	mlx_hook(mlx.win, 4, 0, &mouse_press, (void *)&mlx);
	mlx_hook(mlx.win, 6, 0, &mouse_move, (void *)&mlx);
	mlx_hook(mlx.win, 5, 0, &mouse_release, (void *)&mlx);
	mlx_loop(mlx.mlx);
	return(0);
}



