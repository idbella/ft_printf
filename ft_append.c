/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 03:32:22 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/02 05:43:00 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_append(t_param *param)
{
	int		lenght;
	char	*str;

	lenght = ft_strlen(param->str);
	str = ft_strnew(lenght + 1);
	ft_strcpy(str, param->str);
	str[lenght] = *param->format;
	param->str = str;
}
