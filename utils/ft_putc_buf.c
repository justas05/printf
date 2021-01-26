/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putc_buf(t_buf_info *bi, char c)
{
	if (bi->pos == bi->buf_size)
		ft_flush_fd(bi->fd, bi);
	bi->buf[bi->pos++] = c;
}
