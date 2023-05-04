/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:01:33 by pbrantne          #+#    #+#             */
/*   Updated: 2022/10/19 14:26:16 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			counter;
	int			sign;
	long int	output;

	sign = 1;
	counter = 0;
	output = 0;
	while (str[counter] == ' ' || (str[counter] >= 9 && str[counter] <= 13))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			sign = (-1) * sign;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9' )
	{
		output = (str[counter] - '0') + (output * 10);
		counter++;
		if (output * sign > 2147483647)
			return (-1);
		if (output * sign < -2147483648)
			return (0);
	}
	return (sign * output);
}
