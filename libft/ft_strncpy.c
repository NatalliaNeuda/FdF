/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:17:02 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/29 22:36:09 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char			*real_dst;
	unsigned int	counter;

	counter = 0;
	real_dst = dst;
	while (*src && len > counter)
	{
		*dst++ = *src++;
		counter++;
	}
	while (len > counter)
	{
		*dst++ = '\0';
		counter++;
	}
	return (real_dst);
}
