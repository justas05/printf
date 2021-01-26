/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:59:39 by hbooke            #+#    #+#             */
/*   Updated: 2020/07/30 23:38:23 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_lstsize(t_list *begin_list)
{
	int len;

	len = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++len;
	}
	return (len);
}
