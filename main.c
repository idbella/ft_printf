/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 02:59:48 by sid-bell          #+#    #+#             */
/*   Updated: 2018/11/19 02:59:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	char *s = "ds";
	int p1 =    printf("%C\n", 'c');
	int p2 = ft_printf("%C\n", 'c');

	printf("s : %d\nm : %d\n",p1, p2);
	return 0;
}
