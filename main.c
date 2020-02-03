/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 08:16:07 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/02 21:46:00 by nneuda           ###   ########.fr       */
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
	{
		mlx->shift_x += 10;
		
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	
	draw(mlx);
	
	return (0);
}

void  fdx(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 640, "FDF");
	mlx->mp = (t_map*)ft_memalloc(sizeof(t_map));
}

// int main(int ac, char *av[])
// {
// 	t_fdf *data;
// 	//t_point *mp; 
// 	if (ac != 2)
// 		dead("usage: fdf [map]");
// 	data = (t_fdf*)malloc(sizeof(t_fdf));
// 	read_file(av[1], data);
// 	// set_map_color(data, MAX_COLOR, MIN_COLOR);
// 	data->mlx_ptr = mlx_init();
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, 1500, 1500, "FDF");
// 	data->zoom = 30;
// 	data->shift_x = 0;
// 	data->shift_y = 0;
// 	draw(data);
// 	mlx_key_hook(data->win_ptr, deal_key, data);
// 	mlx_loop(data->mlx_ptr);
// }


int main(int ac, char *av[])
{
	t_mlx mlx;
	
	if (ac != 2)
		dead("usage: fdf [map]");
	fdx(&mlx);
	read_file(av[1], mlx.mp);
	// set_map_color(data, MAX_COLOR, MIN_COLOR);
	
	mlx.zoom = 40;
	mlx.shift_x = 100;
	mlx.shift_y = 100;
	draw(&mlx);
	mlx_key_hook(mlx.win, &deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return(0);
}



