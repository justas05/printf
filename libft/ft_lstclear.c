/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:00:14 by hbooke            #+#    #+#             */
/*   Updated: 2020/07/30 23:34:41 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstclear(t_list **begin_list,
						void (*free_fct)(void *))
{
	t_list *next;
	t_list *walker;

	walker = *begin_list;
	while (walker)
	{
		next = walker->next;
		if (free_fct)
			free_fct(walker->content);
		free(walker);
		walker = next;
	}
	*begin_list = NULL;
}
