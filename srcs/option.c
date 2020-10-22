/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:22:56 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 05:33:32 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	errors(int i, char *arg)
{
	ft_putstr_fd("illegal option -- ", 2);
	ft_putchar_fd(arg[i], 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-lRartgGfd] [file ...]", 2);
	ft_putchar_fd('\n', 2);
}

int		opadder(char *arg, unsigned short *op, int i)
{
	if (arg[i] == 'l')
		*op = (*op) | L;
	else if (arg[i] == 'R')
		*op = (*op) | RR;
	else if (arg[i] == 'a')
		*op = (*op) | A;
	else if (arg[i] == 'r')
		(*op) = (*op) | R;
	else if (arg[i] == 't')
		(*op) = (*op) | T;
	else if (arg[i] == 'g')
		(*op) = (*op) | G;
	else if (arg[i] == 'G')
		(*op) = (*op) | GG;
	else if (arg[i] == 'f')
		(*op) = (*op) | F;
	else if (arg[i] == 'd')
		(*op) = (*op) | D;
	else
		return (0);
	return (1);
}

int		add_option(unsigned short *op, char *arg)
{
	size_t i;

	i = 0;
	while (arg[++i])
	{
		if (i == 1 && arg[i] == '-' && arg[i + 1] == '\0')
			return (0);
		else if (!(opadder(arg, op, i)))
		{
			errors(i, arg);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
