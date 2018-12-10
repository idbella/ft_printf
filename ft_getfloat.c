/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 07:43:26 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 03:03:06 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getfloat(t_param *param)
{
	double		integer;
	char		*str;
	long int	test;
	int			last;

	if (!param->precision)
		param->precision_size = 6;
	integer = va_arg(param->list, double);
	str = ft_itoa((int)integer, 10);
	str = ft_strjoin(str, ".");
	test = integer;
	while (param->precision_size-- >= 0)
	{
		integer -= test;
		integer *= 10;
		test = integer;
		if (!param->precision_size)
		{
			last = test;
		}
		else if (param->precision_size == -1)
		{
			str = ft_strjoin(str, ft_itoa(test > 5 ? last + 1 : last, 10));
		}
		else
			str = ft_strjoin(str, ft_itoa(test, 10));
	}

	param->str = ft_strjoin(param->str, str);
}
