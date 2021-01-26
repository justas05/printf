/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void		ft_putnbr_base(t_buf_info *bi, t_specifier *s,
							double n, unsigned int base)
{
	int		temp;
	double	maxpow;

	ft_nbrlen_base_pow(n, base, &maxpow);
	if (((temp = (n < 0)) || (s->flags & PLUS)) &&
		s->type != 'x' && s->type != 'X' && s->type != 'o')
		ft_putc_buf(bi, ((temp) ? '-' : '+'));
	if (s->precision > 0)
		ft_fill(bi, s->precision, '0');
	n = (temp) ? -n : n;
	while (maxpow >= 1)
	{
		temp = (int)(n / maxpow) % base;
		if (0 <= temp && temp <= 9)
			ft_putc_buf(bi, temp + '0');
		else
			ft_putc_buf(bi, temp - 10 + ((s->type == 'X') ? 'A' : 'a'));
		n -= temp * maxpow;
		maxpow /= base;
	}
}
