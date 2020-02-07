/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:16:07 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/06 18:04:20 by nneuda           ###   ########.fr       */
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

int deal_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	printf("%d\n", key);
	if (key == ESCAPE)
	{
		exit (0);
	}
	if (key == 126)
		mlx->shift_y -= 10;
	if (key == 125)
		mlx->shift_y += 10;
	if (key == 123)
		mlx->shift_x -= 10;
	if (key == 124)
		mlx->shift_x += 10;
	if (key == 18)
		mlx->angle += 0.1;
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
	mlx->zoom = 20;
	mlx->shift_x = 450;
	mlx->shift_y = 200;
}

int main(int ac, char *av[])
{
	t_mlx mlx;
	
	if (ac != 2)
		dead("usage: fdf [map]");
	fdx(&mlx);
	read_file(av[1], mlx.mp);
	set_image(&mlx);
	
	// set_map_color(data, MAX_COLOR, MIN_COLOR);
	draw(&mlx);
	mlx_key_hook(mlx.win, &deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return(0);
}



