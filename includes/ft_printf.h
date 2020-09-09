/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:10:29 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/11 18:16:52 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef char*	(*t_s_func)(void *);

typedef	struct	s_func
{
	char		c;
	t_s_func	func;
}				t_func;

typedef struct	s_pf
{
	va_list		ap;
	size_t		len;
	const char	*str;
	char		*types;
	t_func		func[10];

	char		*value;
	size_t		strlen;
	int			ret_value;
	char		t;
	char		*width;
	size_t		width_len;
	char		*p;
	size_t		p_len;
	size_t		p_size;
	int			flags_count;
	int			f_len;
	char		modf[2];
	int			flag_diez;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			negative_p;
	size_t		fl_len;
	int			was_diez;
	size_t		ox;
	size_t		sign;
	long long	ta;
}				t_pf;

int				ft_printf(const char *str, ...);
void			pf_flags(t_pf *s);
int				print_precision(t_pf *s);
void			pf_width(t_pf *s);
void			pf_precision(t_pf *s);
void			pf_modifier(t_pf *s);
void			pf_type(t_pf *s);
void			case_of_error(void);
t_pf			*initialize(const char *str);
void			re_initialize(t_pf *s);
void			func_arr(t_pf *s);
char			*pf_itoa(void *var);
char			*pf_hex(void *var);
char			*pf_bhex(void *var);
char			*pf_oct(void *var);
char			*pf_u(void *var);
void			pf_flag_diez(t_pf *s);
void			pf_flag_zero(t_pf *s);
void			pf_flag_minus(t_pf *s);
void			pf_flags_plus_and_space(t_pf *s);
void			pf_no_flags(t_pf *s);
void			pf_putvalue(t_pf *s);

#endif
