/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:55:56 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/06 22:29:37 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_q_words(char const *s, char c)
{
	int q;
	int flag;

	q = 0;
	flag = 0;
	while (*s)
	{
		if (!flag && *s != c)
		{
			flag = 1;
			q++;
		}
		if (flag && *s == c)
			flag = 0;
		s++;
	}
	return (q);
}

static int	ft_word_len(char const *s, char c)
{
	int i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**splitarray;
	int		qwords;
	int		i;

	splitarray = NULL;
	if (s)
	{
		qwords = ft_q_words(s, c);
		i = 0;
		if (!(splitarray = (char **)(malloc(sizeof(char *) * qwords + 1))))
			return (NULL);
		while (qwords--)
		{
			while (*s == c && *s)
				s++;
			*(splitarray + i) = ft_strsub(s, 0, ft_word_len(s, c));
			if (!(splitarray + i))
				return (NULL);
			s += ft_word_len(s, c);
			i++;
		}
		*(splitarray + i) = NULL;
	}
	return (splitarray);
}
