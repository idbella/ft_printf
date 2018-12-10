/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:10:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hextoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

void		ft_fill3(char **str, char flag, int hex)
{
	size_t	i;

	i = 0;
	while (flag && i < ft_strlen(*str))
	{
		if (((*str)[i] == ' ' && (*str)[i + 1] != ' ')
		|| (i == 0 && (*str)[i] != ' '))
		{
			if (hex)
			{
				(*str)[i == 0 ? 0 : (i + 1)] = '0';
				(*str)[i == 0 ? 1 : (i + 2)] = 'x';
			}
			else
				(*str)[i] = flag;
			break ;
		}
		i++;
	}
}

static int	ft_readl(t_param *param, char **str)
{
	unsigned int			i_result;
	long unsigned int		l_result;
	long long unsigned int	ll_result;

	if (param->_long == 0)
	{
		i_result = va_arg(param->list, unsigned int);
		*str = ft_uitoa(i_result, 16);
		return (i_result > 0);
	}
	else if (param->_long == 1)
	{
		l_result = va_arg(param->list, long unsigned int);
		*str = ft_uitoa(l_result, 16);
		return (l_result > 0 ? 1 : -1);
	}
	else
	{
		ll_result = va_arg(param->list, long long unsigned int);
		*str = ft_uitoa(ll_result, 16);
		return (ll_result > 0);
	}
	return (0);
}

static int	ft_readh(t_param *param, char **str)
{
	unsigned short	h_result;
	unsigned char	hh_result;

	if (param->_short == 1)
	{
		h_result = (unsigned short)va_arg(param->list, int);
		*str = ft_uitoa(h_result, 16);
		if (h_result)
			return (h_result > 0 ? 1 : -1);
		return (0);
	}
	else
	{
		hh_result = (unsigned char)va_arg(param->list, int);
		*str = ft_uitoa(hh_result, 16);
		if (hh_result)
			return (hh_result > 0 ? 1 : -1);
		return (0);
	}
	return (0);
}

void		ft_setpre3(t_param *param, char **str)
{
	int		i;
	char	*filler;
	char	flag;
	int		zero;
	int		hex;

	zero = param->zero;
	if (param->precision)
	{
		flag = 0;
		hex = (**str == '0' && *(*str + 1) == 'x');
		i = param->precision_size - ft_strlen(*str) + hex;
		if (**str == '-' || **str == '+' || hex)
		{
			i++;
			flag = **str;
			if (hex)
			{
				hex = 1;
				(*str)[0] = '0';
				(*str)[1] = '0';
			}
			**str = '0';
		}
		if (i > 0)
		{
			filler = ft_strrepeat("0", i);
			*str = ft_strjoin(filler, *str);
		}
		if (flag)
		{
			if (hex)
			{
				(*str)[0] = '0';
				(*str)[1] = 'x';
			}
			**str = flag;
		}
	}
}

void		ft_setmargin3(t_param *param, char **str)
{
	size_t	i;
	char	*filler;
	char	flag;
	int		lenght;
	int		hex;

	lenght = ft_strlen(*str);
	filler = " ";
	if (!param->precision && !param->right_margin && param->zero)
		filler = "0";
	if (param->margin && lenght < param->margin_size)
	{
		flag = 0;
		hex = (**str == '0' && *(*str + 1) == 'x');
		i = param->margin_size - lenght - hex;
		if (**str == '-' || **str == '+' || hex)
		{
			i++;
			flag = **str;
			if (hex)
			{
				(*str)[0] = '0';
				(*str)[1] = '0';
			}
			else
				**str = '0';
		}
		if (i > 0)
		{
			filler = ft_strrepeat(filler, i);
			if (param->right_margin)
				*str = ft_strjoin(*str, filler);
			else
				*str = ft_strjoin(filler, *str);
		}
		ft_fill3(str, flag, hex);
	}
}

void		ft_gethex(t_param *param, int upper)
{
	int		result;
	char	*str;
	int		skip;

	skip = param->precision && !param->precision_size;
	param->prefix = 0;
	if (param->_short > 0)
		result = ft_readh(param, &str);
	else
		result = ft_readl(param, &str);
	if (skip)
		str = "";
	if (param->hash && result)
		str = ft_strjoin("0x", str);
	ft_setpre3(param, &str);
	ft_setmargin3(param, &str);
	if (upper)
		ft_hextoupper(str);
	param->str = ft_strjoin(param->str, str);
}
