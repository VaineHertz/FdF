/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:41:47 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/28 13:41:48 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = tmp2;
	}
	*alst = NULL;
}
