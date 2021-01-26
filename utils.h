/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbooke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:59:59 by hbooke            #+#    #+#             */
/*   Updated: 2020/10/29 01:00:48 by hbooke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <stddef.h>

# define BUF_SIZE 1024

enum			e_flags
{
	SPACE = 1,
	MINUS = 2,
	PLUS = 4,
	ZERO = 8,
	SHARP = 16
};

enum			e_sizes
{
	SILE_l,
	SILE_ll,
	SILE_h,
	SILE_hh,
	SILE_L
};

typedef	struct	s_specifier
{
	char		flags;
	int			width;
	int			precision;
	int			size;
	char		type;
}				t_specifier;

typedef struct	s_buf_info
{
	int			fd;
	char		*buf;
	size_t		pos;
	size_t		len;
	size_t		buf_size;
}				t_buf_info;

int				ft_internal_printf_fd(int fd, const char *fmt, va_list *ap);
int				ft_internal_snprintf(char *buf, size_t size,
									const char *fmt, va_list *ap);

void			ft_flush_fd(int fd, t_buf_info *bi);
void			ft_putc_buf(t_buf_info *bi, char c);
void			ft_puts_buf(t_buf_info *bi, const char *c);
void			ft_putsn_buf(t_buf_info *bi, const char *c, size_t n);
void			ft_fill(t_buf_info *bi, size_t size, char fill);
void			ft_putnbr_base(t_buf_info *bi, t_specifier *s,
							double n, unsigned int base);

int				parse_specificator(const char **spec, va_list *ap,
									t_buf_info *buf_info);

void			get_flags(const char **specs, t_specifier *s);
void			get_width(const char **specs, t_specifier *s, va_list *ap);
void			get_precision(const char **specs, t_specifier *s, va_list *ap);
int				get_size(const char **specs, t_specifier *s,
						const char *sizes[]);
int				get_type(const char **specs, t_specifier *s,
						const char *types);
void			check_specifier(t_specifier *s);
int				print_var(t_specifier *s, va_list *ap, int ind,
						t_buf_info *buf_info);

int				print_c(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_s(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_p(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_d(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_i(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_u(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_o(t_specifier *s, va_list *ap, t_buf_info *bi);
int				print_x(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_x_up(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_n(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_f(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_g(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print_e(t_specifier *s, va_list *ap, t_buf_info *buf_info);
int				print__(t_specifier *s, va_list *ap, t_buf_info *buf_info);

#endif
