/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 04:00:53 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 04:01:59 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	ft_linkdir(char *path, char *buff, unsigned short op)
{
	struct stat	st;
	char		*tmp;
	int			c;

	readlink(path, buff, 4096);
	c = ft_strlen(buff);
	tmp = (char *)ft_memalloc(sizeof(char) * c + 1);
	ft_strjoinfirst(buff, '/', &tmp);
	lstat(tmp, &st);
	if (S_ISDIR(st.st_mode))
		read_file(tmp, op);
	else
		ft_putendl(path);
	free(tmp);
}

int		one_ag(t_list **files, unsigned short op)
{
	read_file(".", op);
	ft_deletlist(files, func);
	return (1);
}
