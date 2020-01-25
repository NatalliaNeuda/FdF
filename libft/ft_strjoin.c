/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:14:47 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/01 12:21:49 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_fresh;
	char	*res_str;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(s_fresh = ft_strnew(len)))
			return (NULL);
		res_str = s_fresh;
		while (*s1)
			*s_fresh++ = *s1++;
		while (*s2)
			*s_fresh++ = *s2++;
		*s_fresh = '\0';
		return (res_str);
	}
	return (NULL);
}
