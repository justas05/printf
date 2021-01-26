/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

#include <unistd.h>

int		print_p(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	unsigned long long	c;

	c = (unsigned long long)va_arg(*ap, void*);
	s->width -= (ft_nbrlen_base(c, 16) + 2);
	if (!(s->flags & ZERO) && !(s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	ft_puts_buf(bi, "0x");
	ft_putnbr_base(bi, s, c, 16);
	if (!(s->flags & ZERO) && (s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	return (0);
}
