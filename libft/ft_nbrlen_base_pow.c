/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base_pow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_nbrlen_base_pow(double n, unsigned int base, double *maxpow)
{
	size_t	len;

	len = 1;
	*maxpow = 1;
	if (n < 0)
		n = -n;
	while ((n /= base) >= 1)
	{
		++len;
		*maxpow *= base;
	}
	return (len);
}
