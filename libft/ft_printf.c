/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:56:41 by pbrantne          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:52 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_some_function(va_list args, const char var)
{
	int	c;

	c = 0;
	if (var == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (var == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (var == 'p')
		c += ft_hexptr(va_arg(args, long long));
	else if (var == 'd' || var == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (var == 'u')
		c += ft_putnbr(va_arg(args, unsigned int));
	else if (var == 'x')
		c += ft_convert_lower(va_arg(args, unsigned int));
	else if (var == 'X')
		c += ft_convert(va_arg(args, unsigned int));
	else if (var == '%')
		c += ft_putchar('%');
	return (c);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			ret;
	va_list		args;

	i = 0;
	ret = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ret += ft_some_function(args, s[i]);
			i++;
		}
		else
		{
			ret += ft_putchar(s[i]);
			i++;
		}	
	}
	va_end(args);
	return (ret);
}
