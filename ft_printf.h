/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 02:29:44 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/10 02:51:16 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_param
{
	va_list	list;
	char	*str;
	char	*format;
	int		margin_size;
	int		precision_size;
	char	right_margin;
	char	precision;
	int		hash;
	int		margin;
	int		prefix;
	int		zero;
	char	type;
	int		space;
	int		lenght;
	int		_long;
	int		_short;
}				t_param;
int				ft_printf(const char *restrict format, ...);
void			ft_getstr(t_param *param);
void			ft_getchar(t_param *param);
void			ft_getint(t_param *param);
void			ft_getuint(t_param *param);
void			ft_getoctal(t_param *param);
void			ft_gethex(t_param *param, int upper);
void			ft_getptr(t_param *param);
void			ft_setprecision(t_param *param, char **str);
int				ft_cs(t_param *param);
int				ft_diuf(t_param *param);
int				ft_oxp(t_param *param);
void			ft_append(t_param *param);
int				ft_nospec(t_param *param);
void			ft_padding(t_param *param, char c);
int				ft_flags(t_param *param);
t_param			ft_init(char *format);
void			ft_reset(t_param *param);
void			ft_getfloat(t_param *param);
void			ft_setpadding(t_param *param, char **str);
char			*ft_getprefix(t_param *param, char **str, int len);
#endif
