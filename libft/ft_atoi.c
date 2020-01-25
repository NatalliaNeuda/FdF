/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:17:48 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 10:06:01 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int sign;
	int res;

	sign = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\v' \
				|| *str == '\r' || *str == '\f' || *str == '\t'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= 48 && *str <= 57))
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}
