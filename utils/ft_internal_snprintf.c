/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal_snprintf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

#include <stdarg.h>
#include <unistd.h>

int			ft_internal_snprintf(char *buf, size_t size,
								const char *fmt, va_list *ap)
{
	t_buf_info	bi;

	bi.buf = buf;
	bi.pos = 0;
	bi.len = 0;
	bi.fd = -1;
	bi.buf_size = size;
	while (*fmt)
	{
		if (*fmt == '%')
			parse_specificator(&fmt, ap, &bi);
		else
			ft_putc_buf(&bi, *fmt++);
	}
	return (bi.pos);
}
