/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 07:14:48 by sid-bell          #+#    #+#             */
/*   Updated: 2018/11/19 07:14:50 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# define TRUE 1
# define FALSE 0
# define ABS(x) x < 0 ? -x : x

typedef char	bool;
int				ft_printf(const char *str, ...);
void			ft_wspaces(int wspaces, int *lenght, bool perform);
#endif
