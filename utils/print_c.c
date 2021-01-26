/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <unistd.h>

int		print_c(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	char	c;

	c = va_arg(*ap, int);
	--s->width;
	if (!(s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	ft_putc_buf(bi, c);
	if ((s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	return (1);
}
