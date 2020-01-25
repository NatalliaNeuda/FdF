/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:12:05 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/03 16:15:36 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	res;

	sign = 1;
	res = 0;
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	if (n < -9 || n > 9)
	{
		ft_putnbr_fd(n / 10 * sign, fd);
		ft_putnbr_fd(n % 10 * sign, fd);
	}
	if (n >= -9 && n <= 9)
	{
		res = n * sign + '0';
		write(fd, &res, 1);
	}
}
