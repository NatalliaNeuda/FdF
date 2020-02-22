/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:14:56 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/21 16:24:35 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstaddend(t_list *lst, t_list *new)
{
	if (!lst || !new)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void	free_lst(t_list *lst)
{
	int		i;
	t_list	*tmp;

	while (lst)
	{
		i = 0;
		while (((char**)lst->content)[i])
		{
			free(((char**)lst->content)[i]);
			i++;
		}
		free(lst->content);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

size_t	ft_lstcount(t_list *lst)
{
	size_t q;

	q = 0;
	while (lst)
	{
		lst = lst->next;
		q++;
	}
	return (q);
}
