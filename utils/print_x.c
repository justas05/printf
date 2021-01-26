/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
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

int		print_x(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	unsigned int	c;
	int				len;

	c = va_arg(*ap, unsigned int);
	if (s->precision == 0 && !c)
	{
		ft_fill(bi, s->width, ' ');
		return (0);
	}
	len = ft_nbrlen_base(c, 16);
	if ((s->flags & ZERO) && s->width > 0)
		s->precision = s->width;
	s->precision -= (len + (s->flags & SPACE));
	s->width -= (len + (s->flags & SPACE) +
		((s->precision > 0) ? s->precision : 0));
	if (!(s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	if (s->flags & SPACE)
		ft_putc_buf(bi, ' ');
	ft_putnbr_base(bi, s, c, 16);
	if ((s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	return (0);
}

int		print_x_up(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	unsigned int	c;
	int				len;

	c = va_arg(*ap, unsigned int);
	if (s->precision == 0 && !c)
	{
		ft_fill(bi, s->width, ' ');
		return (0);
	}
	len = ft_nbrlen_base(c, 16);
	if ((s->flags & ZERO) && s->width > 0)
		s->precision = s->width;
	s->precision -= (len + (s->flags & SPACE));
	s->width -= (len + (s->flags & SPACE) +
		((s->precision > 0) ? s->precision : 0));
	if (!(s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	if (s->flags & SPACE)
		ft_putc_buf(bi, ' ');
	ft_putnbr_base(bi, s, c, 16);
	if ((s->flags & MINUS) && s->width > 0)
		ft_fill(bi, s->width, ' ');
	return (0);
}
