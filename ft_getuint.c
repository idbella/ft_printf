/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:07:39 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill1(char **str, char flag)
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

void		ft_setpre1(t_param *param, char **str)
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

void		ft_setmargin1(t_param *param, char **str)
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
		ft_fill1(str, flag);
	}
}

static int	ft_readh(t_param *param, char **str)
{
	unsigned short	h_result;
	unsigned char	hh_result;

	if (param->_short == 1)
	{
		h_result = (unsigned short)va_arg(param->list, int);
		*str = ft_uitoa(h_result, 10);
		if (h_result)
			return (h_result > 0 ? 1 : -1);
		return (0);
	}
	else
	{
		hh_result = (unsigned char)va_arg(param->list, int);
		*str = ft_uitoa(hh_result, 10);
		if (hh_result)
			return (hh_result > 0 ? 1 : -1);
		return (0);
	}
	return (0);
}

static int	ft_readl(t_param *param, char **str)
{
	unsigned int			i_result;
	unsigned long int		l_result;
	unsigned long long int	ll_result;

	if (param->_long == 0)
	{
		i_result = va_arg(param->list, unsigned);
		*str = ft_uitoa(i_result, 10);
		return (i_result > 0);
	}
	else if (param->_long == 1)
	{
		l_result = va_arg(param->list, unsigned long int);
		*str = ft_uitoa(l_result, 10);
		return (l_result > 0 ? 1 : -1);
	}
	else
	{
		ll_result = va_arg(param->list, unsigned long long int);
		*str = ft_uitoa(ll_result, 10);
		return (ll_result > 0);
	}
	return (0);
}

void		ft_getuint(t_param *param)
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
	ft_setpre1(param, &str);
	ft_setmargin1(param, &str);
	param->str = ft_strjoin(param->str, str);
}
