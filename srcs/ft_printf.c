/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:17:05 by ifran             #+#    #+#             */
/*   Updated: 2019/10/03 16:16:51 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	if_flag(t_pf *s)
{
	size_t	n;
	char	*chr;
	size_t	str_len;

	str_len = ft_strlen(s->str);
	if (!(chr = ft_strchr(s->str, '%')))
	{
		s->len += str_len;
		ft_putstrn(s->str, str_len);
		return (0);
	}
	n = str_len - ft_strlen(chr);
	ft_putstrn(s->str, n);
	s->str += n;
	s->len += n;
	return (1);
}

int			ft_printf(const char *str, ...)
{
	t_pf	*s;
	int		res;

	s = initialize(str);
	va_start(s->ap, str);
	while (*s->str)
	{
		if (*(s->str) == '%' && *(++s->str))
		{
			pf_flags(s);
			re_initialize(s);
		}
		if (!(if_flag(s)))
			break ;
	}
	va_end(s->ap);
	res = s->len;
	free(s);
	return (res);
}
