/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:13:52 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/02 20:45:34 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			s_fresh[i] = f(i, s[i]);
			i++;
		}
		s_fresh[i] = '\0';
	}
	return (s_fresh);
}
