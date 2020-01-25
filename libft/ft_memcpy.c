/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 11:12:14 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 09:50:04 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *ul_dst;
	unsigned char *ul_src;

	if (!src && !dst)
		return (NULL);
	if (len)
	{
		ul_dst = (unsigned char *)dst;
		ul_src = (unsigned char *)src;
		while (len--)
			*ul_dst++ = *ul_src++;
	}
	return (dst);
}
