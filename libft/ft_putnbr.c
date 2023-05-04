/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:32:28 by pbrantne          #+#    #+#             */
/*   Updated: 2022/11/10 21:28:49 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printnumber(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		printnumber(n / 10);
		printnumber(n % 10);
	}
}

int	ft_putnbr(long long num)
{
	int	pos;

	pos = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		pos++;
		num *= -1;
	}
	else
		pos = 0;
	if (num == 0)
	{
		pos++;
	}
	printnumber(num);
	while (num != 0)
	{
		num /= 10;
		pos++;
	}
	return (pos);
}
