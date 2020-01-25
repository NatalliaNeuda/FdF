/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:06:44 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/06 21:25:45 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		sign;
	char	res;

	res = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	if (n < -9 || n > 9)
	{
		ft_putnbr(n / 10 * sign);
		ft_putnbr(n % 10 * sign);
	}
	if (n >= -9 && n <= 9)
	{
		res = (n * sign) + '0';
		write(1, &res, 1);
	}
}
