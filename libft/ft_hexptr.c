/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:23:11 by pbrantne          #+#    #+#             */
/*   Updated: 2022/11/10 20:26:33 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_print(unsigned long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

int	ft_hexptr(unsigned long long num)
{
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	ft_convert_lower(num);
	return (ft_strlen_print(num) + 2);
}
