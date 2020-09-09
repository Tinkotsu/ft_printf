/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:03:17 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/11 18:22:11 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_putvalue(t_pf *s)
{
	if (s->flag_diez)
	{
		if (s->p_len && !s->p_size && ft_strchr("xX", s->t) && *s->value == '0')
			if (!s->width_len && s->flag_space)
				s->width_len--;
			else
				s->strlen--;
		else
			ft_putstrn(s->value + s->sign, s->strlen - s->sign);
	}
	else
	{
		if (s->p_len && !s->p_size && ft_strchr("xXdDiouUOp", s->t)
				&& *s->value == '0')
		{
			if (!s->width_len && s->flag_space)
				s->width_len--;
			else
				s->strlen--;
		}
		else
			ft_putstrn(s->value + s->sign, s->strlen - s->sign);
	}
}
