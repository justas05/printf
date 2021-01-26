/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:41:30 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 02:41:30 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	nbr_len(int num)
{
	size_t p;

	p = 1;
	while ((num /= 10))
		++p;
	return (p);
}

char			*ft_itoa(int n)
{
	char	*buf;
	size_t	len;
	size_t	i;

	len = nbr_len(n);
	i = len + (n < 0);
	buf = malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (NULL);
	ft_bzero(buf, i + 1);
	if (n < 0)
		buf[0] = '-';
	if (len == 1 && n == 0)
		buf[0] = '0';
	while (n != 0)
	{
		buf[--i] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	return (buf);
}
