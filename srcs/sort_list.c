/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:57:43 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:21:23 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	sort_rev(t_list **lst)
{
	t_list		*tmp;
	t_list		*cmp;

	if (!*lst)
		return ;
	cmp = *lst;
	while (cmp && cmp->content)
	{
		tmp = cmp->next;
		while (tmp && tmp->content)
		{
			if (ft_strcmp(cmp->content, tmp->content) < 0)
				ft_swap(cmp, tmp);
			tmp = tmp->next;
		}
		cmp = cmp->next;
	}
}

void	sort_rev_time(t_list **lst)
{
	t_list		*tmp;
	t_list		*cmp;

	if (!*lst)
		return ;
	cmp = *lst;
	while (cmp && cmp->content)
	{
		tmp = cmp->next;
		while (tmp && tmp->content)
		{
			if ((cmp->st.st_mtime - tmp->st.st_mtime) > 0)
				ft_swap(cmp, tmp);
			else if ((cmp->st.st_mtime == tmp->st.st_mtime
					&& ft_strcmp(cmp->content, tmp->content) < 0))
				ft_swap(cmp, tmp);
			tmp = tmp->next;
		}
		cmp = cmp->next;
	}
}

void	sort_nor(t_list **lst)
{
	t_list		*tmp;
	t_list		*cmp;

	if (!*lst)
		return ;
	cmp = *lst;
	while (cmp && cmp->content)
	{
		tmp = cmp->next;
		while (tmp && tmp->content)
		{
			if (ft_strcmp(cmp->content, tmp->content) > 0)
				ft_swap(cmp, tmp);
			tmp = tmp->next;
		}
		cmp = cmp->next;
	}
}

void	sort_f(t_list **lst)
{
	t_list		*tmp;
	t_list		*cmp;

	if (!*lst)
		return ;
	cmp = *lst;
	while (cmp && cmp->content)
	{
		tmp = cmp->next;
		while (tmp && tmp->content)
		{
			ft_swap(cmp, tmp);
			tmp = tmp->next;
		}
		cmp = cmp->next;
	}
}

void	sorting(t_list **lst, unsigned short op)
{
	if (!*lst)
		return ;
	if ((op & R) && (op & T) && !(op & F))
		sort_rev_time(lst);
	else if (op & F)
		sort_f(lst);
	else if ((op & T) && (!(op & F)))
		sort_time(lst);
	else if (op & R)
		sort_rev(lst);
	else
		sort_nor(lst);
}
