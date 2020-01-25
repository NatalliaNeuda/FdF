/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:13:48 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/02 20:25:13 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*al_s1;
	unsigned char	*al_s2;

	al_s1 = (unsigned char *)s1;
	al_s2 = (unsigned char *)s2;
	i = 0;
	while (al_s1[i] && al_s2[i] && al_s1[i] == al_s2[i] && n-- > 0)
		i++;
	if (!n)
		return (0);
	return (al_s1[i] - al_s2[i]);
}
