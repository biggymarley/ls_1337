/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 01:40:42 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 22:21:03 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_newlst(char *content, size_t c_z, struct stat st, char *path)
{
	t_list	*list;

	if (!(list = (t_list *)(ft_memalloc(sizeof(t_list)))))
		return (NULL);
	if (content)
	{
		list->content = ft_strdup(content);
		list->content_size = c_z;
		list->st = st;
		if (path)
			list->path = ft_strdup(path);
		else
			list->path = NULL;
	}
	else
	{
		list->content_size = 0;
		list->content = NULL;
		list->path = NULL;
	}
	list->next = NULL;
	return (list);
}
