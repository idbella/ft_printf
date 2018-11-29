/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:41:22 by sid-bell          #+#    #+#             */
/*   Updated: 2018/11/29 00:31:15 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(long int n, int base)
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