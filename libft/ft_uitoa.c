/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:58:39 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/09 06:10:51 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill(char *str,unsigned long long int n, int lenght, int base)
{
	char				*bse;

	bse = "0123456789abcdef";
	while (--lenght >= 0)
	{
		str[lenght] = bse[n % base];
		n /= base;
	}
}

char			*ft_uitoa(unsigned long long int n, int base)
{
	char			*str;
	size_t			lenght;

	lenght = ft_unbrlen(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	str[lenght] = '\0';
	fill(str, n, lenght, base);
	return (str);
}
