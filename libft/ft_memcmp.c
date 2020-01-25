/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:26:43 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 22:08:55 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *al_s1;
	const unsigned char *al_s2;

	if (s1 == s2 || n == 0)
		return (0);
	al_s1 = (const unsigned char *)s1;
	al_s2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*al_s1 != *al_s2)
			return (*al_s1 - *al_s2);
		if (n)
		{
			al_s1++;
			al_s2++;
		}
	}
	return (0);
}
