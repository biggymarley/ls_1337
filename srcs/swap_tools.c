/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 02:19:43 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 03:56:26 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	ft_swap(t_list *c, t_list *b)
{
	struct stat		stmp;
	char			*p;
	char			*tmp;

	p = b->content;
	stmp = b->st;
	tmp = b->path;
	b->content = c->content;
	b->st = c->st;
	b->path = c->path;
	c->content = p;
	c->st = stmp;
	c->path = tmp;
}

void	sort_time(t_list **lst)
{
	t_list	*tmp;
	t_list	*cmp;

	if (!*lst)
		return ;
	cmp = *lst;
	while (cmp && cmp->content)
	{
		tmp = cmp->next;
		while (tmp && tmp->content)
		{
			if (cmp->st.st_mtime < tmp->st.st_mtime)
				ft_swap(cmp, tmp);
			else if ((cmp->st.st_mtime == tmp->st.st_mtime
					&& ft_strcmp(cmp->content, tmp->content) > 0))
				ft_swap(cmp, tmp);
			tmp = tmp->next;
		}
		cmp = cmp->next;
	}
}
