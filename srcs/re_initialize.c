/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:42:55 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/11 18:17:00 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	re_initialize(t_pf *s)
{
	int	i;

	s->strlen = 0;
	s->ret_value = 0;
	s->t = '\0';
	i = -1;
	while (++i < 2)
		s->modf[i] = '\0';
	s->width_len = 0;
	s->p_len = 0;
	s->flags_count = 0;
	s->flag_zero = 0;
	s->flag_diez = 0;
	s->flag_space = 0;
	s->flag_plus = 0;
	s->flag_minus = 0;
	s->f_len = 0;
	s->ox = 0;
	s->fl_len = 0;
	s->was_diez = 0;
	s->negative_p = 0;
	ft_strdel(&s->value);
	ft_strdel(&s->p);
	ft_strdel(&s->width);
}
