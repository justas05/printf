/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

static void	t_specifier_init(t_specifier *s,
							const char **str, const char **spec)
{
	s->flags = 0;
	s->width = 0;
	s->precision = -1;
	s->size = 0;
	s->type = 0;
	*str = *spec;
	(*spec)++;
}

int			parse_specificator(const char **spec, va_list *ap,
							t_buf_info *bi)
{
	t_specifier	s;
	const char	*str;
	const char	*types = "cspdiuoxXnfge%";
	const char	*sizes[] = { "l", "ll", "h", "hh",
							"L", NULL };
	int			ind;

	t_specifier_init(&s, &str, spec);
	get_flags(spec, &s);
	get_width(spec, &s, ap);
	get_precision(spec, &s, ap);
	get_size(spec, &s, sizes);
	if ((ind = get_type(spec, &s, types)) < 0)
	{
		ft_putsn_buf(bi, str, *spec - str);
		return (-1);
	}
	check_specifier(&s);
	return (print_var(&s, ap, ind, bi));
}

void		check_specifier(t_specifier *s)
{
	const char	*types_num = "diouxXaAeEfFgp%";
	const int	ind_ints = 6;
	char		*pos;

	if ((s->flags & MINUS) || !(pos = ft_strchr(types_num, s->type)) ||
		(s->precision >= 0 && (int)(pos - types_num) < ind_ints))
		s->flags &= ~ZERO;
	if (s->flags & PLUS)
		s->flags &= ~SPACE;
}

int			print_var(t_specifier *s, va_list *ap, int ind,
					t_buf_info *buf_info)
{
	static int	(*print_funcs[])(t_specifier *s, va_list *ap,
		t_buf_info *buf_info) = {	print_c, print_s, print_p,
									print_d, print_i, print_u,
									print_o, print_x, print_x_up,
									print_n, print_f, print_g,
									print_e, print__ };

	return (print_funcs[ind](s, ap, buf_info));
}
