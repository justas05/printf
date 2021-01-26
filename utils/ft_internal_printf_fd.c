/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal_printf_fd.c                            :+:      :+:    :+:   */
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

int			ft_internal_printf_fd(int fd, const char *fmt, va_list *ap)
{
	char		buf[BUF_SIZE];
	t_buf_info	bi;

	bi.buf = (char*)buf;
	bi.pos = 0;
	bi.len = 0;
	bi.fd = fd;
	bi.buf_size = BUF_SIZE;
	while (*fmt)
	{
		if (*fmt == '%')
			parse_specificator(&fmt, ap, &bi);
		else
			ft_putc_buf(&bi, *fmt++);
	}
	if (bi.pos)
		ft_flush_fd(fd, &bi);
	return (bi.len);
}
