/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
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

int		ft_sprintf(char *buf, const char *fmt, ...)
{
	va_list	ap;
	int		len;

	if (!buf || !ft_strcmp("%", fmt))
		return (0);
	va_start(ap, fmt);
	len = ft_internal_snprintf(buf, -1, fmt, &ap);
	va_end(ap);
	return (len);
}
