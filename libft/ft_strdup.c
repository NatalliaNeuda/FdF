/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:47:57 by nneuda            #+#    #+#             */
/*   Updated: 2019/09/28 09:56:03 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*al_s2;
	int		len;

	len = ft_strlen(s1) + 1;
	if (!(s2 = (char *)(malloc(len))))
		return (NULL);
	al_s2 = s2;
	while (*s1)
		*al_s2++ = *s1++;
	*al_s2 = '\0';
	return (s2);
}
