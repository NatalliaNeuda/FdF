/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:41:57 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/01 15:25:32 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = ft_strlen(dst);
	len = ft_strlen(src);
	if (size < i)
		len += size;
	else
		len += i;
	while (*src && i + 1 < size)
		*(dst + i++) = *src++;
	*(dst + i) = '\0';
	return (len);
}
