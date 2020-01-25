/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:38:28 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 21:31:32 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*al_dst;
	unsigned char	*al_src;

	if (!dst && !src)
		return (NULL);
	i = -1;
	al_dst = (unsigned char *)dst;
	al_src = (unsigned char *)src;
	if (al_src < al_dst)
		while (len--)
			al_dst[len] = al_src[len];
	else
		while (++i < len)
			al_dst[i] = al_src[i];
	return (al_dst);
}
