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
	int		len;

	(void)buf;
	(void)size;
	(void)fmt;
	(void)ap;
	if (!ft_strcmp("%", fmt))
		return (0);
	len = 0;
	return (len);
}
