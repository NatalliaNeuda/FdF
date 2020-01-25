/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:46:46 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 21:26:20 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *al_dst;
	unsigned char *al_src;
	unsigned char al_c;

	al_dst = (unsigned char *)dst;
	al_src = (unsigned char *)src;
	al_c = (unsigned char)c;
	while (n > 0)
	{
		*al_dst = *al_src;
		if (*al_src == al_c)
			return (&*al_dst + 1);
		al_dst++;
		al_src++;
		n--;
	}
	return (NULL);
}
