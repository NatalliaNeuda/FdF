/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:42:16 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/03 22:15:26 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*s_fresh;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	s_fresh = NULL;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strnew(1));
		j = (unsigned int)(ft_strlen(s) - 1);
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		if (!(s_fresh = ft_strsub(s, i, j - i + 1)))
			return (NULL);
	}
	return (s_fresh);
}
