/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:57:48 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/01 13:44:12 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *s;

	s = NULL;
	if (size)
	{
		if (!(s = (unsigned char *)(malloc(size))))
			return (NULL);
		ft_bzero(s, size);
	}
	return ((void *)s);
}
