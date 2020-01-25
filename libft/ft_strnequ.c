/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:43:30 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/03 10:50:50 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*al_s1;
	unsigned char	*al_s2;

	al_s1 = (unsigned char *)s1;
	al_s2 = (unsigned char *)s2;
	i = 0;
	if (s1 && s2)
	{
		while (al_s1[i] && al_s2[i] && al_s1[i] == al_s2[i] && i <= n)
		{
			i++;
			n--;
		}
		if ((al_s1[i] == al_s2[i]) || n == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
