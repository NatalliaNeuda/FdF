/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:27:38 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/06 22:27:10 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst1;
	t_list *tmp;

	tmp = f(lst);
	lst1 = tmp;
	if (!lst1)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!((tmp->next) = f(lst)))
		{
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (lst1);
}
