/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <unistd.h>

int		print__(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	(void)ap;
	if (!(s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width - 1, ((s->flags & ZERO) ? '0' : ' '));
	ft_putc_buf(bi, '%');
	if ((s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width - 1, ' ');
	return (0);
}
