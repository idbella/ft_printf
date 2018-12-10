/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 03:32:22 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/08 14:27:31 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(t_param *param, char c)
{
	if (c == '0' && !param->zero)
		param->zero = 1;
	else if (!param->margin)
	{
		param->margin = 1;
		param->margin_size = ft_atoi(param->format);
		param->format += ft_nbrlen(param->margin_size, 10) - 1;
	}
}
