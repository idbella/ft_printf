/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/08 18:56:00 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnull(t_param *param, char *str)
{
	ft_putstr(param->str);
	param->lenght += ft_strlen(param->str);
	param->str = "";
	param->lenght += ft_strlen(str);
	while (*str)
	{
		ft_putchar(*str == '~' ? 0 : *str);
		str++;
	}
}

void	ft_getchar(t_param *param)
{
	char	*str;
	int		flag;
	int		i;
	char	*filler;

	flag = 0;
	filler = param->zero ? "0" : " ";
	str = (char *)ft_strnew(1);
	str[0] = (char)va_arg(param->list, int);
	str[1] = '\0';
	if (!str[0])
	{
		str[0] = '~';
		flag = 1;
	}
	if (param->margin)
	{
		i = param->margin_size - ft_strlen(str);
		while (i-- > 0)
		{
			if (param->right_margin)
				str = ft_strjoin(str, filler);
			else
				str = ft_strjoin(filler, str);
		}
	}
	if (flag)
		ft_putnull(param, str);
	else
		param->str = ft_strjoin(param->str, str);
}
