/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:59:58 by hbooke            #+#    #+#             */
/*   Updated: 2020/07/30 23:31:27 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **begin_list, t_list *data)
{
	t_list *last;

	last = ft_lstlast(*begin_list);
	if (last)
		last->next = data;
	else
		*begin_list = data;
}
