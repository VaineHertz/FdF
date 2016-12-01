/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flip_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:46:03 by tpadilla          #+#    #+#             */
/*   Updated: 2016/11/05 18:47:06 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			flip_list(t_list **list)
{
	t_list *last;
	t_list *cur;
	t_list *next;

	last = NULL;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = last;
		last = cur;
		cur = next;
	}
	*list = last;
}
