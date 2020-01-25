/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:14:44 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/07 17:00:46 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		div;
	int		i;
	char	*str;
	int		size;

	size = ft_isnegative(n) ? 2 : 1;
	n = ft_isnegative(n) ? n : n * -1;
	size += ft_numlen(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[0] = ft_isnegative(n) ? '-' : '0';
	div = n;
	i = 0;
	while (div < 0)
	{
		str[size - (1 + i)] = '0' + ((div % 10) * -1);
		div = div / 10;
		i++;
	}
	return (str);
}
