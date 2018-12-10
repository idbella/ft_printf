/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:10:48 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/04 16:17:06 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;
	size_t	lenght;

	str = NULL;
	if (s)
	{
		lenght = ft_strlen(s);
		len = lenght < len ? lenght : len;
		if (!(str = ft_strnew(len)))
			return (NULL);
		index = 0;
		while (index < len)
		{
			str[index] = s[index + start];
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
