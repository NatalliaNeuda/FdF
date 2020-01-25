/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:08:31 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/02 20:29:45 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*al_s;
	int				i;

	i = 0;
	al_s = (unsigned char *)s;
	while (n)
	{
		if (*al_s == (unsigned char)c)
			return (al_s);
		al_s++;
		n--;
	}
	return (NULL);
}
