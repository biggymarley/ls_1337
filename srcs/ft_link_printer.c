/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:45:46 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 02:44:33 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void		ft_link_printer(t_list *list)
{
	char	*buf;

	buf = ft_strnew(4096);
	readlink(list->path, buf, 4096);
	ft_putstr(list->content);
	ft_putstr("\033[0m");
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(buf);
}
