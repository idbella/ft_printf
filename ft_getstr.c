/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:08:10 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:13:51 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getstr(t_param *param)
{
	char	*str;
	int		i;
	char	*filler;

	filler = param->zero ? "0" : " ";
	str = va_arg(param->list, char *);
	if (!str)
		str = "(null)";
	if (param->precision)
		str = ft_strsub(str, 0, param->precision_size);
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
	param->str = ft_strjoin(param->str, str);
}
