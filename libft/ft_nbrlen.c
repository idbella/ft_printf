/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:41:22 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/09 07:01:25 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(long long int n, int base)
{
	size_t lenght;
	lenght = n <= 0 ? 1 : 0;
	while (n)
	{
		lenght++;
		n /= base;
	}
	return (lenght);
}
