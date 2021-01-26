/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:00:24 by hbooke            #+#    #+#             */
/*   Updated: 2020/07/30 23:35:43 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

t_list		*ft_lstnew(void *data)
{
	t_list *item;

	item = (t_list*)malloc(sizeof(t_list));
	if (item)
	{
		item->next = NULL;
		item->content = data;
	}
	return (item);
}
