/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:18:30 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/06 21:05:33 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && len)
	{
		j = 0;
		n = len;
		while (str[i + j] && str[i + j] == to_find[j] && n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
			n--;
		}
		i++;
		len--;
	}
	return (0);
}
