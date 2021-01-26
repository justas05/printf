/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

#include <stddef.h>
#include <unistd.h>

void		get_flags(const char **specs, t_specifier *s)
{
	const char	*flags = " -+0#";
	size_t		index;
	char		*pos;

	while (**specs && (pos = ft_strchr(flags, (int)**specs)))
	{
		index = pos - flags;
		if (index == 0)
			s->flags |= SPACE;
		else if (index == 1)
			s->flags |= MINUS;
		else if (index == 2)
			s->flags |= PLUS;
		else if (index == 3)
			s->flags |= ZERO;
		else if (index == 4)
			s->flags |= SHARP;
		(*specs)++;
	}
}

void		get_width(const char **specs, t_specifier *s, va_list *ap)
{
	if (**specs == '*')
	{
		s->width = va_arg(*ap, int);
		if (s->width < 0)
		{
			s->flags |= MINUS;
			s->width = ft_abs(s->width);
		}
		++(*specs);
		return ;
	}
	s->width = (size_t)ft_atoi(*specs);
	while (ft_isdigit(**specs))
		++(*specs);
}

void		get_precision(const char **specs, t_specifier *s, va_list *ap)
{
	if (**specs != '.')
		return ;
	s->precision = 0;
	++(*specs);
	if (**specs == '*')
	{
		s->precision = va_arg(*ap, int);
		++(*specs);
		return ;
	}
	s->precision = (size_t)ft_atoi(*specs);
	while (ft_isdigit(**specs))
		++(*specs);
}

int			get_size(const char **specs, t_specifier *s, const char *sizes[])
{
	const char	**sizes_copy;
	int			pos;
	size_t		i;

	sizes_copy = sizes;
	pos = -1;
	i = 0;
	while (sizes_copy[i] && pos == -1)
	{
		if (ft_strnstr(*specs, sizes_copy[i],
					ft_strlen(sizes_copy[i])) == *specs)
			pos = i;
		++i;
	}
	if (pos == -1)
		return (s->size = -1);
	s->size = (size_t)pos;
	(*specs) += ft_strlen(sizes_copy[pos]);
	return (s->size);
}

int			get_type(const char **specs, t_specifier *s, const char *types)
{
	char		*pos;

	if (!**specs || !(pos = ft_strchr(types, (int)**specs)))
		return (-1);
	s->type = *pos;
	++(*specs);
	return (pos - types);
}
