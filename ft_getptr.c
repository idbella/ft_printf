/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:15:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill4(char **str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(*str))
	{
		if (((*str)[i] == '0' && (*str)[i + 1] == '0'))
		{
			(*str)[i] = '0';
			(*str)[i + 1] = 'x';
			break ;
		}
		i++;
	}
}

void	ft_setpre4(t_param *param, char **str)
{
	int		i;
	char	*filler;
	int		zero;

	zero = param->zero;
	if (param->precision)
	{
		i = param->precision_size - ft_strlen(*str) + 2;
		(*str)[0] = '0';
		(*str)[1] = '0';
		if (i > 0)
		{
			filler = ft_strrepeat("0", i);
			*str = ft_strjoin(filler, *str);
		}
		(*str)[0] = '0';
		(*str)[1] = 'x';
	}
}

void	ft_setmargin4(t_param *param, char **str)
{
	size_t	i;
	char	*filler;
	int		lenght;

	lenght = ft_strlen(*str);
	filler = " ";
	if (!param->precision && !param->right_margin && param->zero)
		filler = "0";
	if (param->margin && lenght < param->margin_size)
	{
		i = param->margin_size - lenght;
		(*str)[0] = '0';
		(*str)[1] = '0';
		if (i > 0)
		{
			filler = ft_strrepeat(filler, i);
			if (param->right_margin)
				*str = ft_strjoin(*str, filler);
			else
				*str = ft_strjoin(filler, *str);
		}
		ft_fill4(str);
	}
}

void	ft_getptr(t_param *param)
{
	long int	result;
	char		*str;
	int			skip;

	skip = param->precision && !param->precision_size;
	param->prefix = 0;
	result = va_arg(param->list, long int);
	str = ft_itoa(result, 16);
	if (skip)
		str = "";
	str = ft_strjoin("0x", str);
	ft_setpre4(param, &str);
	ft_setmargin4(param, &str);
	if (param->space && result > 0 && !param->prefix)
	{
		if (param->precision || param->margin)
			*str = ' ';
		else
			str = ft_strjoin(" ", str);
	}
	param->str = ft_strjoin(param->str, str);
}
