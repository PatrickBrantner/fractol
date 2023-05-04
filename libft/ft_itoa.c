/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:30:35 by pbrantne          #+#    #+#             */
/*   Updated: 2022/10/22 16:13:19 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_zero(void)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (2));
	if (!ptr)
		return (0);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

static	char	*ft_negative(int i, int n)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (0);
	ptr[i + 1] = '\0';
	while (n != 0)
	{
		ptr[i] = -(n % 10) + '0';
		n = n / 10;
		i--;
	}
	ptr[i] = '-';
	return (ptr);
}

static	char	*ft_positive(int i, int n)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	while (n != 0)
	{
		ptr[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*ptr;

	j = n;
	i = 0;
	while (j != 0)
	{
		i++;
		j = j / 10;
	}
	if (n == 0)
		ptr = ft_zero();
	if (n < 0)
		ptr = ft_negative(i, n);
	if (n > 0)
		ptr = ft_positive(i, n);
	if (!ptr)
		return (0);
	else
		return (ptr);
}
