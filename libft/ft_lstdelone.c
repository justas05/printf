/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:00:58 by hbooke            #+#    #+#             */
/*   Updated: 2020/07/30 23:37:16 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void		ft_lstdelone(t_list *item, void (*f)(void *))
{
	if (item)
	{
		if (item->content)
			f(item->content);
		free(item);
	}
}
