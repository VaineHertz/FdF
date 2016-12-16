/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 20:00:00 by tpadilla          #+#    #+#             */
/*   Updated: 2016/10/01 20:11:49 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *clst;
	t_list *nlst;

	clst = *alst;
	while (clst)
	{
		nlst = clst->next;
		del(clst->content, clst->content_size);
		free(clst);
		clst = nlst;
	}
	*alst = NULL;
}
