/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
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

int		print_o(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	int		c;
	int		len;

	c = va_arg(*ap, unsigned int);
	if (s->precision == 0)
	{
		ft_fill(bi, s->width, ' ');
		return (0);
	}
	len = ft_nbrlen_base(c, 8);
	len = (s->flags & PLUS) + ((len < s->precision) ? s->precision : len);
	if (!(s->flags & (ZERO | MINUS)) && s->width > len)
		ft_fill(bi, s->width - len, ' ');
	ft_putnbr_base(bi, s, c, 8);
	if (!(s->flags & ZERO) && (s->flags & MINUS) && s->width > len)
		ft_fill(bi, s->width - len, ' ');
	return (0);
}
