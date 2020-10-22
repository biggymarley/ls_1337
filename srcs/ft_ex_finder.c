/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 00:50:24 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 02:41:35 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void			ft_ex_finder(t_list *list)
{
	acl_t		acl;
	acl_entry_t	file;
	ssize_t		xattr;
	char		chr;
	char		*filename;

	acl = NULL;
	xattr = 0;
	filename = list->path;
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &file) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		chr = '@';
	else
		chr = ((acl != NULL) ? '+' : ' ');
	acl_free(acl);
	ft_putchar(chr);
}
