/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 02:28:02 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 01:03:29 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_param param;

	param = ft_init((char *)format);
	va_start(param.list, format);
	while (*param.format)
	{
		ft_reset(&param);
		if (*param.format == '%')
		{
			if (*(param.format + 1) == '\0')
			{
				ft_nospec(&param);
				break ;
			}
			else
				while (*(++param.format))
				{
					if (ft_cs(&param))
						break ;
					if (ft_diuf(&param))
						break ;
					if (ft_oxp(&param))
						break ;
					if (ft_flags(&param))
						break ;
				}
		}
		else
			ft_append(&param);
		param.format++;
	}
	ft_putstr(param.str);
	return (ft_strlen(param.str) + param.lenght);
}
