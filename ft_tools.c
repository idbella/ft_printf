/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 03:32:22 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:04:13 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	ft_init(char *format)
{
	t_param param;

	param.format = format;
	param.str = "";
	param.lenght = 0;
	return (param);
}

void	ft_reset(t_param *param)
{
	param->zero = 0;
	param->hash = 0;
	param->precision = 0;
	param->prefix = 0;
	param->right_margin = 0;
	param->margin_size = 0;
	param->precision_size = 0;
	param->type = 0;
	param->margin = 0;
	param->space = 0;
	param->_long = 0;
	param->_short = 0;
}

int		ft_nospec(t_param *param)
{
	char	*str;
	char	*s1;

	str = ft_strnew(1);
	if (!(*param->format == '%' && *(param->format + 1) == '\0'))
		str[0] = *param->format;
	if (param->margin)
	{
		s1 = ft_strrepeat(" ", param->margin_size - ft_strlen(str));
		str = ft_strjoin(s1, str);
	}
	param->str = ft_strjoin(param->str, str);
	return (1);
}
