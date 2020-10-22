/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:44:37 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:19:21 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	ft_errors(char *av)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(av);
}

void	ft_ls(unsigned short op, char **s)
{
	int i;

	i = 0;
	if (op & L && !(op & R) && !(op & T))
		rec_r(s, op);
	else if ((op & T) && !(op & F))
	{
		ft_sort_tab_time(s);
		if (op & R)
			rec_rr(s, op);
		else
			rec_r(s, op);
	}
	else if ((op & R) && !(op & F))
		rec_rr(s, op);
	else if ((op & RR) && !(op & R))
		rec_r(s, op);
	else if ((op & RR) && (op & R) && !(op & F))
		rec_rr(s, op);
	else
		rec_r(s, op);
	free(s);
}

void	adder(char **str, char *av)
{
	char *tmp2;

	tmp2 = *str;
	*str = ft_strjoin(*str, av);
	free(tmp2);
	tmp2 = *str;
	*str = ft_strjoin(*str, ":");
	free(tmp2);
}

void	linkr(struct stat *st, char **av, int i)
{
	char	*tmp;
	int		c;
	char	*buff;

	buff = ft_strnew(4096);
	readlink(av[i], buff, 4096);
	c = ft_strlen(buff);
	tmp = (char *)ft_memalloc(sizeof(char) * c + 1);
	ft_strjoinfirst(buff, '/', &tmp);
	lstat(tmp, &*st);
	free(tmp);
	free(buff);
}

char	*ft_args_adder(char **av, int i, unsigned short op, t_list **files)
{
	t_vars var;

	var.str = ft_strnew(0);
	while (av[i])
	{
		if (lstat(av[i], &var.st) != -1)
		{
			if (S_ISLNK(var.st.st_mode) && !(op & L) && !(op & G))
				linkr(&var.st, av, i);
			if (S_ISDIR(var.st.st_mode) && !(op & D))
				adder(&var.str, av[i]);
			else
			{
				var.list = ft_newlst(av[i], ft_strlen(av[i]), var.st, av[i]);
				ft_lstadd(files, var.list);
			}
		}
		i++;
	}
	return (var.str);
}
