/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 03:32:22 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:12:26 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getpercent(t_param *param)
{
	size_t	i;
	char	*filler;
	char	*str;
	int		lenght;

	str = "%";
	lenght = ft_strlen(str);
	filler = " ";
	if ((!param->precision || param->precision_size == 0)
	&& !param->right_margin && param->zero)
		filler = "0";
	if (param->margin && lenght < param->margin_size)
	{
		i = param->margin_size - lenght;
		if (i > 0)
		{
			filler = ft_strrepeat(filler, i);
			if (param->right_margin)
				str = ft_strjoin(str, filler);
			else
				str = ft_strjoin(filler, str);
		}
	}
	param->str = ft_strjoin(param->str, str);
	return (1);
}

int	ft_flags(t_param *param)
{
	char	c;

	c = *param->format;
	if (c == '%')
		return (ft_getpercent(param));
	else if (c == '-')
		param->right_margin = 1;
	else if (c == '+')
		param->prefix = 1;
	else if (c == '#')
		param->hash = 1;
	else if (c == '.')
	{
		param->precision = 1;
		param->precision_size = ft_atoi(param->format + 1);
		if (ft_isdigit(*(param->format + 1)))
			param->format += ft_nbrlen(param->precision_size, 10);
	}
	else if (c >= '0' && c <= '9')
		ft_padding(param, c);
	else if (c == ' ')
		param->space = 1;
	else if (c == 'l')
		param->_long++;
	else if (c == 'h')
		param->_short++;
	else
		return (ft_nospec(param));
	if (!*(param->format + 1))
		ft_nospec(param);
	return (0);
}
