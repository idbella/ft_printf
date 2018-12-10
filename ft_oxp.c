/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/09 05:04:21 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_oxp(t_param *param)
{
	if (*param->format == 'o')
	{
		param->type = *param->format;
		ft_getoctal(param);
		return (1);
	}
	else if (ft_tolower(*param->format) == 'x')
	{
		param->type = *param->format;
		ft_gethex(param, *param->format == 'X');
		return (1);
	}
	else if (*param->format == 'p')
	{
		param->type = *param->format;
		ft_getptr(param);
		return (1);
	}
	return (0);
}
