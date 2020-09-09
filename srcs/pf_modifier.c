/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:49:33 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/04 19:07:41 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_modifier(t_pf *s)
{
	if (*s->str == 'l' && (s->str)++)
	{
		s->modf[0] = 'l';
		(s->ret_value)++;
		if (*s->str == 'l' && (s->str)++)
		{
			(s->ret_value)++;
			s->modf[1] = 'l';
		}
	}
	else if (*s->str == 'h' && (s->str)++)
	{
		s->modf[0] = 'h';
		(s->ret_value)++;
		if (*s->str == 'h' && (s->str)++)
		{
			(s->ret_value)++;
			s->modf[1] = 'h';
		}
	}
	pf_type(s);
}
