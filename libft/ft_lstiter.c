/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:00:58 by hbooke            #+#    #+#             */
/*   Updated: 2020/07/30 23:37:16 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		ft_lstiter(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		if (f)
			f(begin_list->content);
		begin_list = begin_list->next;
	}
}
