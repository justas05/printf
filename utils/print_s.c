/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
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

int		print_s(t_specifier *s, va_list *ap, t_buf_info *bi)
{
	char	*c;
	int		len;

	if (!(c = va_arg(*ap, char*)))
		c = (s->precision >= 0 && s->precision < 6) ? "" : "(null)";
	if ((len = ft_strlen(c)) > s->precision && s->precision >= 0)
		len = s->precision;
	if (!(s->flags & MINUS) && s->width > len)
		ft_fill(bi, s->width - len, ' ');
	ft_putsn_buf(bi, c, len);
	if ((s->flags & MINUS) && s->width > len)
		ft_fill(bi, s->width - len, ' ');
	return (0);
}
