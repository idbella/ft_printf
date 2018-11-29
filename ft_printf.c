/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 07:13:43 by sid-bell          #+#    #+#             */
/*   Updated: 2018/11/19 07:13:45 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthexa(long int i, int base, int upper)
{
	char	*hex;
	int		lenght;

	lenght = 0;
	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	if (i < base)
	{
		lenght++;
		ft_putchar(hex[i]);
	}
	else
	{
		if (i / base)
			lenght += ft_puthexa(i / base, base, upper);
		ft_putchar(hex[i % base]);
		lenght++;
	}
	return (lenght);
}

int		ft_getstr(const char **s1, va_list vl, int wspaces, int *ret)
{
	char	*str;
	int		lenght;

	lenght = 0;
	if (**s1 == 's')
	{
		if ((str = va_arg(vl, char *)))
		{
			lenght = ft_strlen(str);
			ft_wspaces(wspaces, &lenght, wspaces > 0);
			ft_putstr(str);
			ft_wspaces(wspaces, &lenght, wspaces < 0);
			(*ret) += lenght;
		}
		else
		{
			lenght = 6;
			ft_wspaces(wspaces, &lenght, wspaces > 0);
			ft_putstr("(null)");
			ft_wspaces(wspaces, &lenght, wspaces < 0);
			(*ret) += lenght;
		}
		(*s1)++;
	}
	return (lenght);
}

void	ft_wspaces(int wspaces, int *lenght, bool perform)
{
	int tmp;
	int add;

	add = 0;
	tmp = ABS(wspaces);
	if (perform)
	{
		while (tmp - *lenght > 0)
		{
			ft_putchar(' ');
			tmp--;
			add++;
		}
		*lenght += add;
	}
}

int		ft_isflag(char c)
{
	return (c == 'd' || c == 'i' || c == 'x' || c == 'X'
		|| c == 'f' || c == 'c' || c == 'u'
		|| c == 'p' || c == 'o');
}

int		ft_getint(const char **s1, va_list vl, bool *prefix, int wspaces)
{
	int integer;
	int lenght;

	lenght = 0;
	integer = va_arg(vl, int);
	if (*prefix && integer >= 0)
		lenght++;
	lenght += ft_nbrlen(integer, 10);
	ft_wspaces(wspaces, &lenght, wspaces > 0);
	if (*prefix && integer >= 0)
		ft_putchar('+');
	ft_putnbr(integer);
	ft_wspaces(wspaces, &lenght, wspaces < 0);
	(*s1)++;
	*prefix = 0;
	return (lenght);
}

int		ft_getuint(const char **s1, va_list vl, bool *prefix, int wspaces)
{
	unsigned int	uinteger;
	int				lenght;

	lenght = 0;
	uinteger = va_arg(vl, unsigned int);
	if (*prefix)
		lenght++;
	lenght += ft_nbrlen(uinteger, 10);
	ft_wspaces(wspaces, &lenght, wspaces > 0);
	if (*prefix)
		ft_putchar('+');
	ft_putnbr(uinteger);
	ft_wspaces(wspaces, &lenght, wspaces < 0);
	(*s1)++;
	*prefix = 0;
	return (lenght);
}

int		ft_getpercent(const char **s1, int wspaces, int *ret)
{
	int lenght;

	lenght = 1;
	if (**s1 == '%')
	{
		ft_wspaces(wspaces, &lenght, wspaces > 0);
		ft_putchar('%');
		ft_wspaces(wspaces, &lenght, wspaces < 0);
		(*s1)++;
		(*ret) += lenght;
		return (1);
	}
	return (0);
}

int		ft_getchar(const char **s1, va_list vl, int wspaces, int *ret)
{
	int lenght;

	lenght = 1;
	if (**s1 == 'c')
	{
		ft_wspaces(wspaces, &lenght, wspaces > 0);
		ft_putchar(va_arg(vl, int));
		ft_wspaces(wspaces, &lenght, wspaces < 0);
		(*s1)++;
		(*ret) += lenght;
		return (1);
	}
	return (0);
}

int		ft_gethex(const char **s1, va_list vl, int wspaces, int *ret)
{
	int			lenght;
	long int	value;

	lenght = 0;
	if (**s1 == 'x' || **s1 == 'X')
	{
		value = va_arg(vl, long int);
		lenght = ft_nbrlen(value, 16);
		ft_wspaces(wspaces, &lenght, wspaces > 0);
		ft_puthexa(value, 16, **s1 == 'X');
		ft_wspaces(wspaces, &lenght, wspaces < 0);
		(*s1)++;
		(*ret) += lenght;
		return (1);
	}
	return (0);
}

int		ft_getoct(const char **s1, va_list vl, int wspaces, int *ret)
{
	int			lenght;
	long int	value;

	lenght = 0;
	if (**s1 == 'o')
	{
		value = va_arg(vl, long int);
		lenght = ft_nbrlen(value, 8);
		ft_wspaces(wspaces, &lenght, wspaces > 0);
		ft_puthexa(value, 8, 0);
		ft_wspaces(wspaces, &lenght, wspaces < 0);
		(*s1)++;
		(*ret) += lenght;
		return (1);
	}
	return (0);
}

int		ft_getpointer(const char **s1, va_list vl, int wspaces, int *ret)
{
	int			lenght;
	long int	value;

	lenght = 0;
	if (**s1 == 'p')
	{
		value = va_arg(vl, long int);
		lenght = ft_nbrlen(value, 16) + 2;
		ft_wspaces(wspaces, &lenght, wspaces > 0);
		ft_putstr("0x");
		ft_puthexa(value, 16, 0);
		ft_wspaces(wspaces, &lenght, wspaces < 0);
		(*s1)++;
		(*ret) += lenght;
		return (1);
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list	vl;
	bool	prefix;
	int		wscount;
	int		ret;
	int		start;

	va_start(vl, str);
	ret = 0;
	while (*str)
	{
		prefix = 0;
		wscount = 0;
		if (*str == '%')
		{
			start = 0;
			while (*++str)
			{
				start++;
				if (ft_getpercent(&str, wscount, &ret))
					break ;
				else if (ft_getstr(&str, vl, wscount, &ret))
					break ;
				else if (*str == 'u')
				{
					ret += ft_getuint(&str, vl, &prefix, wscount);
					break ;
				}
				else if (*str == 'd' || *str == 'i')
				{
					ret += ft_getint(&str, vl, &prefix, wscount);
					break ;
				}
				else if (ft_getchar(&str, vl, wscount, &ret))
					break ;
				else if (ft_getpointer(&str, vl, wscount, &ret))
				{
					break ;
				}
				else if (ft_gethex(&str, vl, wscount, &ret))
				{
					break ;
				}
				else if (*str == 'f')
				{
					//printf("%f", va_arg(vl, double));
					str++;
					break ;
				}
				else if (*str == '+')
				{
					prefix = 1;
					continue;
				}
				else if (*str == '-')
				{
					wscount = ft_atoi(str);
					continue;
				}
				else if (ft_getoct(&str, vl, wscount, &ret))
				{
					break ;
				}
				else if (*str >= '0' && *str <= '9' && !wscount)
				{
					wscount = ft_atoi(str);
				}
				else if (!(*str >= '0' && *str <= '9'))
				{
					if (*str == ' ')
					{
						if (ft_isflag(*(str + 1)) && !prefix)
						{
							ret++;
							ft_putchar(' ');
						}
						else
							start--;
					}
					else
					{
						ret += start;
						ft_wspaces(wscount, &ret, wscount > 0);
						ft_putchar(*str);
						ft_wspaces(wscount, &ret, wscount < 0);
						str++;
						break ;
					}
				}
			}
			continue ;
		}
		ret++;
		ft_putchar(*str);
		str++;
	}
	va_end(vl);
	return (ret);
}
