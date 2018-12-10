/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:05:31 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/09 05:04:26 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cs(t_param *param)
{
	if (*param->format == 's')
	{
		param->type = *param->format;
		ft_getstr(param);
		return (1);
	}
	else if (*param->format == 'c')
	{
		param->type = *param->format;
		ft_getchar(param);
		return (1);
	}
	return (0);
}
