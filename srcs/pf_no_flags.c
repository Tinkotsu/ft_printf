/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:24:54 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 14:25:51 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_no_flags(t_pf *s)
{
	ft_putstrn(s->width, s->width_len);
	s->sign = print_precision(s);
	pf_putvalue(s);
}
