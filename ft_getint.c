/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/09 08:17:28 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill(char **str, char flag)
{
	size_t	i;

	i = 0;
	while (flag && i < ft_strlen(*str))
	{
		if (((*str)[i] == ' ' && (*str)[i + 1] != ' ')
		|| (i == 0 && (*str)[i] != ' '))
		{
			(*str)[i] = flag;
			break ;
		}
		i++;
	}
}

void	ft_setpre(t_param *param, char **str)
{
	int		i;
	char	*filler;
	char	flag;
	int		zero;

	zero = param->zero;
	if (param->precision)
	{
		flag = 0;
		i = param->precision_size - ft_strlen(*str);
		if (**str == '-' || **str == '+')
		{
			i++;
			flag = **str;
			**str = '0';
		}
		if (i > 0)
		{
			filler = ft_strrepeat("0", i);
			*str = ft_strjoin(filler, *str);
		}
		if (flag)
			**str = flag;
	}
}

void	ft_setmargin(t_param *param, char **str)
{
	size_t	i;
	char	*filler;
	char	flag;
	int		lenght;

	lenght = ft_strlen(*str);
	filler = " ";
	if (!param->precision && !param->right_margin && param->zero)
		filler = "0";
	if (param->margin && lenght < param->margin_size)
	{
		flag = 0;
		i = param->margin_size - lenght;
		if (**str == '-' || **str == '+')
		{
			flag = **str;
			**str = *filler;
		}
		if (i > 0)
		{
			filler = ft_strrepeat(filler, i);
			if (param->right_margin)
				*str = ft_strjoin(*str, filler);
			else
				*str = ft_strjoin(filler, *str);
		}
		ft_fill(str, flag);
	}
}

int		ft_readl(t_param *param, char **str)
{
	int				i_result;
	long int		l_result;
	long long int	ll_result;

	if (param->_long == 0)
	{
		i_result = va_arg(param->list, int);
		*str = ft_itoa(i_result, 10);
		if (i_result)
			return (i_result > 0 ? 1 : -1);
		return (0);
	}
	else if (param->_long == 1)
	{
		l_result = va_arg(param->list, long int);
		*str = ft_itoa(l_result, 10);
		if (l_result)
			return (l_result > 0 ? 1 : -1);
		return (0);
	}
	else
	{
		ll_result = va_arg(param->list, long long int);
		*str = ft_itoa(ll_result, 10);
		if (ll_result)
			return (ll_result > 0 ? 1 : -1);
		return (0);
	}
	return (0);
}

int		ft_readh(t_param *param, char **str)
{
	short		h_result;
	signed char	hh_result;

	if (param->_short == 1)
	{
		h_result = (short)va_arg(param->list, int);
		*str = ft_itoa(h_result, 10);
		if (h_result)
			return (h_result > 0 ? 1 : -1);
		return (0);
	}
	else
	{
		hh_result = (signed char)va_arg(param->list, int);
		*str = ft_itoa(hh_result, 10);
		if (hh_result)
			return (hh_result > 0 ? 1 : -1);
		return (0);
	}
	return (0);
}

void	ft_getint(t_param *param)
{
	int		result;
	char	*str;
	int		len;
	int		skip;

	if (param->_short > 0)
		result = ft_readh(param, &str);
	else
		result = ft_readl(param, &str);
	skip = param->precision && !param->precision_size && !result;
	len = ft_strlen(str);
	if (skip)
		str = "";
	if (param->prefix && result >= 0)
		str = ft_strjoin("+", str);
	ft_setpre(param, &str);
	ft_setmargin(param, &str);
	if (param->space && result >= 0 && !param->prefix)
	{
		if (param->precision || param->margin)
			*str = ' ';
		else
			str = ft_strjoin(" ", str);
	}
	param->str = ft_strjoin(param->str, str);
}
