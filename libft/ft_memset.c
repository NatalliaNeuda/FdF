/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 23:15:31 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 09:37:44 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *u_b;

	u_b = (unsigned char *)b;
	while (len > 0)
	{
		*u_b = (unsigned char)c;
		u_b++;
		len--;
	}
	return (b);
}
