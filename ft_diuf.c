/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diuf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 02:51:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_diuf(t_param *param)
{
	if (*param->format == 'd' || *param->format == 'i')
	{
		param->type = 'd';
		ft_getint(param);
		return (1);
	}
	else if (*param->format == 'u')
	{
		param->type = *param->format;
		ft_getuint(param);
		return (1);
	}
	else if (*param->format == 'f')
	{
		param->type = *param->format;
		ft_getfloat(param);
		return (1);
	}
	return (0);
}
