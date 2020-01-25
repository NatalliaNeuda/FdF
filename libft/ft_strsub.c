/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:10:08 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/15 16:57:44 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s_fresh;

	i = 0;
	s_fresh = NULL;
	if (s)
	{
		if (!(s_fresh = ft_strnew(len)))
			return (NULL);
		while (s[start + i] && i < len)
		{
			s_fresh[i] = s[start + i];
			i++;
		}
		s_fresh[i] = '\0';
	}
	return (s_fresh);
}
