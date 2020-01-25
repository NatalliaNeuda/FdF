/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:15:50 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/01 14:09:29 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_fresh;
	int		i;

	i = 0;
	s_fresh = NULL;
	if (s)
	{
		if (!(s_fresh = (char *)(malloc(ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			s_fresh[i] = f(s[i]);
			i++;
		}
		s_fresh[i] = '\0';
	}
	return (s_fresh);
}
